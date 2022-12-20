/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:40:08 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/20 04:40:55 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_x_max(t_struct *mlx, int test)
{
	int	a;

	a = mlx->map.move_x;
	if (mlx->map.flag_x_min == 0 || test)
	{
		if ((mlx->map.size_x - mlx->player.x) - (mlx->win_size_x / 2) > 0 && a)
		{
			mlx->map.flag_x_max = 0;
			mlx->map.max_x = mlx->player.x + (mlx->win_size_x / 2);
		}
		else
		{
			mlx->map.flag_x_max = 1;
			mlx->map.max_x = mlx->map.size_x;
		}
	}
	else
		mlx->map.max_x = mlx->win_size_x;
}

static void	check_x_min(t_struct *mlx, int test)
{
	int	a;

	a = mlx->map.move_x;
	if (mlx->map.flag_x_max == 0 || test)
	{
		if (mlx->player.x - (mlx->win_size_x / 2) > 0 && a)
		{
			mlx->map.flag_x_min = 0;
			mlx->map.min_x = mlx->player.x - (mlx->win_size_x / 2);
		}
		else
		{
			mlx->map.flag_x_min = 1;
			mlx->map.min_x = 0;
		}
	}
	else
		mlx->map.min_x = mlx->map.size_x - mlx->win_size_x;
}

static void	check_y_min(t_struct *mlx, int test)
{
	int	a;

	a = mlx->map.move_y;
	if (mlx->map.flag_y_max == 0 || test)
	{
		if (mlx->player.y - (mlx->win_size_y / 2) > 0 && a)
		{
			mlx->map.flag_y_min = 0;
			mlx->map.min_y = mlx->player.y - (mlx->win_size_y / 2);
		}
		else
		{
			mlx->map.flag_y_min = 1;
			mlx->map.min_y = 0;
		}
	}
	else
		mlx->map.min_y = mlx->map.size_y - mlx->win_size_y;
}

static void	check_y_max(t_struct *mlx, int test)
{
	int	a;

	a = mlx->map.move_y;
	if (mlx->map.flag_y_min == 0 || test)
	{
		if ((mlx->map.size_y - mlx->player.y) - (mlx->win_size_y / 2) > 0 && a)
		{
			mlx->map.flag_y_max = 0;
			mlx->map.max_y = mlx->player.y + (mlx->win_size_y / 2);
		}
		else
		{
			mlx->map.flag_y_max = 1;
			mlx->map.max_y = mlx->map.size_y;
		}
	}
	else
		mlx->map.max_y = mlx->win_size_y;
}

void	fill_min_max(t_struct *mlx, int value)
{
	check_x_min(mlx, value);
	check_x_max(mlx, value);
	check_y_min(mlx, value);
	check_y_max(mlx, value);
}
