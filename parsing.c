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

void check_arg_error(int argc, char **argv)
{
    if (argc != 2)
	{
        printf("Wrong format, should be \"./so_long [map.ber]\"\n");
		exit (1);
	}
	if (strstr (argv[1] + (strlen (argv[1]) - 4), ".ber") == 0)
	{
		printf("Map has to be a \".ber\" file.\n");
		exit (1);
	}
}

void check_char_error(char c)
{
    if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
    {
        printf("Wrong map, it should contain only :\n");
        printf("- '1' for walls\n- '0' for free space\n- 'C' for coins\n");
        printf("- Only 1 'E' for Exit\n- Only 1 'P' for Player\n");
        exit(1);
    }
}

int is_map_ok(int fd, int *x_counter, int *y_counter)
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

    i = 0;
    printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map);
    map = (char **)malloc (sizeof(char *) * y_counter + 1);
    map[i] = get_next_line(fd);
    printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map[i]);
    while (map[i++])
    {
        map[i] = get_next_line(fd);
        printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map[i]);
    }
    map[y_counter] = 0;
    printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map);
    return (map);
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
        printf("File \"%s\" not found.\n", argv[1]);
		exit (1);
    }
    if (!is_map_ok(fd, &x_counter, &y_counter))
    {
        printf("Wrong size, map should be a rectangle.\n");
		exit (1);
    }
    close (fd);
    fd = open (argv[1], O_RDONLY);
    map = fill_map(fd, map, x_counter, y_counter);
    printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map);
    
    printf("[%s]:[%d] map[1][11]:%c\n",__FUNCTION__ ,__LINE__, map[1][11]);

    printf("FD:%d\n",fd);

    printf("\n");
    printf("x_counter : %d\ny_counter : %d\n",x_counter, y_counter);
    close (fd);
    return (0);
}