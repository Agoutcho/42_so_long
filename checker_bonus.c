/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:50:24 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/21 22:09:07 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_a_rectangle(int *x_counter, int *y_counter)
{
	if (*x_counter != *y_counter)
		return (1);
	return (0);
}

int	is_map_size_ok(int fd, int *x_counter, int *y_counter)
{
	int		readsize;
	int		x_previous;
	char	buf[2];

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
	if (x_previous != (*x_counter)--)
		return (0);
	(*y_counter)++;
	return (is_a_rectangle(x_counter, y_counter));
}

static void	check_flag(t_struct *mlx, char c)
{
	if (c == '1' || c == '0')
		return ;
	else if (c == 'C')
		(mlx->col.flag_c)++;
	else if (c == 'P')
		(mlx->player.flag_p)++;
	else if (c == 'E')
		(mlx->end.flag_e)++;
}

void	check_if_map_ok(t_struct *mlx, char **map, int x_cnt, int y_counter)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (j < y_counter)
	{
		while (i < x_cnt)
		{
			c = map [j][i];
			if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C'\
			&& c != 'X')
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
