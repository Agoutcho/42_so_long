/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:43:37 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/12 21:24:49 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft/libft.h"

unsigned int sleep(unsigned int seconds);

ssize_t read(int fd, void *buf, size_t count);

void free_map(char **map);

void check_arg_error(int argc, char **argv)
{
    int size;

    size = ft_strlen (argv[1]);
    if (argc != 2)
	{
        ft_printf("Error\nWrong format, should be \"./so_long [map.ber]\"\n");
		exit (1);
	}
	if (ft_strnstr (argv[1] + (size - 4), ".ber", size + 1) == 0)
	{
		ft_printf("Error\nMap has to be a \".ber\" file.\n");
		exit (1);
	}
}

void char_error(char **map)
{
    ft_printf("Error\nWrong map, it should contain only :\n");
    ft_printf("- '1' for walls\n- '0' for free space\n- 'C' for coins\n");
    ft_printf("- Only 1 'E' for Exit\n- Only 1 'P' for Player\n");
    free_map(map);
    exit(1);
}

int is_map_size_ok(int fd, int *x_counter, int *y_counter)
{
    int     readsize;
    int     x_previous;
    char    buf[2];

    readsize = 1;
    x_previous = 0;
    while (readsize != 0)
    {
        readsize = read(fd, buf, 1);
        (*x_counter)++;
        if (buf[0] == '\n')
        {
            (*y_counter)++;
            if (x_previous == 0 || x_previous == *x_counter)
                x_previous = *x_counter;
            else
                return (0);
            *x_counter = 0;
        }
    }
    if (x_previous != *x_counter)
        return (0);
    (*y_counter)++;
    (*x_counter)--;
    return (1);
}

char **fill_map(int fd, char **map, int x_counter, int y_counter)
{
    int i;

    i = 1;
    ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map);
    map = (char **)malloc (sizeof(char *) * y_counter + 1);
    if (!map)
    {
        close (fd);
        exit (1);
    }
    map[0] = get_next_line(fd);
    ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map[i]);
    
    while (i < y_counter)
    {
        map[i] = get_next_line(fd);
        if (!map[i])
        {
            close (fd);
            exit (1);
        }
        i++;
        ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map[i]);
    }
    map[y_counter] = 0;
    ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map);
    return (map);
}

void check_flag(int *flag_E, int *flag_P, int *flag_C, char c, char **map)
{
    if (c == '1'|| c == '0')
        return;
    else if (c == 'C')
        (*flag_C)++;
    else if (c == 'P')
        (*flag_P)++;
    else if (c == 'E')
        (*flag_E)++;
}

void check_if_map_ok(char **map, int x_counter, int y_counter)
{
    ft_printf("[%s]:[%d]\n",__FUNCTION__ ,__LINE__);
    int     i;
    int     j;
    int     flag_E;
    int     flag_P;
    int     flag_C;
    char    c;

    i = 0;
    j = 0;
    flag_E = 0;
    flag_P = 0;
    flag_C = 0;
    while (j < y_counter)
    {
        while (i < x_counter)
        {
            c = map [j][i];
            if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
                char_error(map);
            else 
                check_flag(&flag_E, &flag_P, &flag_C, c, map);
            i++;
        }
        j++;
        i = 0;
    }
    if (flag_E != 1 || flag_P != 1 || flag_C < 1 )
        char_error(map);
}

void free_map(char **map)
{
    int j;

    j = 0;
    while (map[j])
    {
        free(map[j]);
        map[j] = NULL;
        j++;
    }
    if (map)
    {
        free(map);
        map = NULL;
    }
}

void wall_error(char **map)
{
    ft_printf("Error\nWrong map, it should be surrounded by walls.\n");
    free_map(map);
    exit(1);
}

void check_if_wall_ok(char **map, int x_counter, int y_counter)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < y_counter)
    {
        if (j == 0 || j == y_counter - 1)
        {
            while (i < x_counter)
            {
                if (map[j][i] != '1')
                    wall_error(map);
                i++;
            }
        }
        else if (map[j][0] != '1' || map[j][x_counter - 1] != '1')
            wall_error(map);
        j++;
        i = 0;
    }
}


void check_if_playable(char **map, int count_col, int x_counter, int y_counter)
{
    check_if_wall_ok(map, x_counter, y_counter);
}

int main(int argc, char **argv)
{
    int fd;
    int readsize;
    int counterY = 0;
    char buf[100];
    int x_counter = 0;
    int y_counter = 0;
    char **map;

    check_arg_error(argc, argv);
    fd = open (argv[1], O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error\nFile \"%s\" not found.\n", argv[1]);
		exit (1);
    }
    if (!is_map_size_ok(fd, &x_counter, &y_counter))
    {
        ft_printf("Error\nWrong size, map should be a rectangle.\n");
		exit (1);
    }
    ft_printf("x_counter : %d\ny_counter : %d\n",x_counter, y_counter);
    close (fd);
    fd = open (argv[1], O_RDONLY);
    ft_printf("open FD:%d\n",fd);
    map = fill_map(fd, map, x_counter, y_counter);
    close (fd);
    ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map);
    ft_printf("[%s]:[%d] map[1][11]:%c\n",__FUNCTION__ ,__LINE__, map[1][11]);

    check_if_map_ok(map, x_counter, y_counter);


    check_if_playable(map, 0, x_counter, y_counter);
    ft_printf("\n");
    for(int j = 0; map[j];j++)
    {
        for (int i = 0; map[j][i];i++)
        {
            ft_printf("%c",map[j][i]);
        }
    }
    ft_printf("\n");
    // exit(0);
    free_map(map);
    return (0);
}