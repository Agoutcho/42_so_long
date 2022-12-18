/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:43:37 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/18 03:44:50 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void free_map(char **map);

void error_not_rectangle()
{
    ft_printf("Error\nWrong size, map should be a rectangle.\n");
	exit (1);
}

void check_arg_error(int argc, char **argv)
{
    int size;

    if (argc != 2)
	{
        ft_printf("Error\nWrong format, should be \"./so_long [map.ber]\"\n");
		exit (1);
	}
    size = ft_strlen (argv[1]);
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

int is_a_rectangle(int *x_counter, int *y_counter)
{
    // ft_printf("[%s]:[%d] x_counter:%d\n",__FUNCTION__ ,__LINE__, *x_counter);
    // ft_printf("[%s]:[%d] y_counter:%d\n",__FUNCTION__ ,__LINE__, *y_counter);
    if (*x_counter != *y_counter)
        return (1);
    return (0);
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
        // ft_printf("[%s]:[%d] x_counter:%d\n",__FUNCTION__ ,__LINE__, *x_counter);
        // ft_printf("[%s]:[%d] x_previous:%d\n",__FUNCTION__ ,__LINE__, x_previous);
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
    return (is_a_rectangle(x_counter, y_counter));
}

char **fill_map(int fd, char **map, int x_counter, int y_counter)
{
    int i;

    i = 1;
    // ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map);
    map = (char **)malloc (sizeof(char *) * y_counter + 1);
    if (!map)
    {
        close (fd);
        exit (1);
    }
    map[0] = get_next_line(fd);
    // ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map[i]);
    
    while (i < y_counter)
    {
        map[i] = get_next_line(fd);
        if (!map[i])
        {
            close (fd);
            exit (1);
        }
        i++;
        // ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map[i]);
    }
    map[y_counter] = 0;
    // ft_printf("[%s]:[%d] map:%p\n",__FUNCTION__ ,__LINE__, map);
    return (map);
}

void check_flag(t_struct *mlx, char c)
{
    // ft_printf("[%s]:[%d] c:%c\n",__FUNCTION__ ,__LINE__, c);
    // ft_printf("[%s]:[%d] mlx->col.flag_C:%d\n",__FUNCTION__ ,__LINE__, mlx->col.flag_C);
    if (c == '1'|| c == '0')
        return;
    else if (c == 'C')
        (mlx->col.flag_c)++;
    else if (c == 'P')
        (mlx->player.flag_p)++;
    else if (c == 'E')
        (mlx->end.flag_e)++;
}

void check_if_map_ok(t_struct *mlx, char **map, int x_counter, int y_counter)
{
    int     i;
    int     j;
    char    c;

    i = 0;
    j = 0;
    while (j < y_counter)
    {
        while (i < x_counter)
        {
            c = map [j][i];
            if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
                char_error(map);
            else 
                check_flag(mlx, c);
            i++;
        }
        j++;
        i = 0;
    }
    if (mlx->end.flag_e != 1 || mlx->player.flag_p != 1 || mlx->col.flag_c < 1)
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

void check_if_playable(char **map, int count_col, int flag_E, int x_counter, int y_counter)
{
    check_if_wall_ok(map, x_counter, y_counter);
}

void parsing(int argc, char **argv, t_struct *mlx)
{
    int fd;

    check_arg_error(argc, argv);
    fd = open (argv[1], O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error\nFile \"%s\" not found.\n", argv[1]);
		exit (1);
    }
    if (!is_map_size_ok(fd, &mlx->map.size_x, &mlx->map.size_y))
        error_not_rectangle();
    // ft_printf("mlx->map.size_x : %d\nmlx->map.size_y : %d\n",mlx->map.size_x, mlx->map.size_y);
    close (fd);
    fd = open (argv[1], O_RDONLY);
    // ft_printf("open FD:%d\n",fd);
    mlx->map.real_map = fill_map(fd, mlx->map.real_map, mlx->map.size_x, mlx->map.size_y);
    close (fd);
    // ft_printf("[%s]:[%d] mlx->map.real_map:%p\n",__FUNCTION__ ,__LINE__, mlx->map.real_map);
    // ft_printf("[%s]:[%d] mlx->map.real_map[1][11]:%c\n",__FUNCTION__ ,__LINE__, mlx->map.real_map[1][11]);

    check_if_map_ok(mlx, mlx->map.real_map, mlx->map.size_x, mlx->map.size_y);


    check_if_wall_ok(mlx->map.real_map, mlx->map.size_x, mlx->map.size_y);
    ft_printf("\n");
    for(int j = 0; mlx->map.real_map[j];j++)
    {
        for (int i = 0; mlx->map.real_map[j][i];i++)
        {
            ft_printf("%c",mlx->map.real_map[j][i]);
        }
    }
    ft_printf("\n");
}