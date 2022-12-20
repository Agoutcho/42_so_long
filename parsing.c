/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:43:37 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/20 04:55:08 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(int fd, char **map, int x_counter, int y_counter)
{
	int	i;

	i = 1;
	map = (char **)malloc (sizeof(char *) * y_counter + 1);
	if (!map)
	{
		close (fd);
		exit (1);
	}
	map[0] = get_next_line(fd);
	while (i < y_counter)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			close (fd);
			exit (1);
		}
		i++;
	}
	map[y_counter] = 0;
	return (map);
}

void	free_map(char **map)
{
	int	j;

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

void	check_if_wall_ok(char **map, int x_counter, int y_counter)
{
	int	i;
	int	j;

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

void	parsing(int argc, char **argv, t_struct *mlx)
{
	int	fd;
	int	sy;

	check_arg_error(argc, argv);
	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile \"%s\" not found.\n", argv[1]);
		exit (1);
	}
	if (!is_map_size_ok(fd, &mlx->map.size_x, &mlx->map.size_y))
		error_not_rectangle();
	close (fd);
	fd = open (argv[1], O_RDONLY);
	sy = mlx->map.size_y;
	mlx->map.real_map = fill_map(fd, mlx->map.real_map, mlx->map.size_x, sy);
	close (fd);
	check_if_map_ok(mlx, mlx->map.real_map, mlx->map.size_x, sy);
	check_if_playable(mlx, mlx->map.real_map, mlx->map.size_x, sy);
}
