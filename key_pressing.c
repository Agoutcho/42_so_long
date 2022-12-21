/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:33:39 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/21 22:08:23 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	go_left(t_struct *mlx)
{
	int	t;

	t = mlx->map.real_map[mlx->player.y][mlx->player.x - 1] == 'X';
	if ((mlx->map.real_map[mlx->player.y][mlx->player.x - 1] == 'E' \
				&& mlx->finished) || t)
		destroy_win(mlx);
	if (mlx->map.real_map[mlx->player.y][mlx->player.x - 1] != '1' \
			&& mlx->map.real_map[mlx->player.y][mlx->player.x - 1] != 'E')
	{
		mlx->map.real_map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.x--;
		if (mlx->map.real_map[mlx->player.y][mlx->player.x] == 'C')
			mlx->col.flag_c--;
		mlx->map.real_map[mlx->player.y][mlx->player.x] = 'P';
		mlx->player.f_counter++;
		ft_printf("%d\n", mlx->player.f_counter);
	}
}

static void	go_right(t_struct *mlx)
{
	int	t;

	t = mlx->map.real_map[mlx->player.y][mlx->player.x + 1] == 'X';
	if ((mlx->map.real_map[mlx->player.y][mlx->player.x + 1] == 'E' \
				&& mlx->finished) || t)
		destroy_win(mlx);
	if (mlx->map.real_map[mlx->player.y][mlx->player.x + 1] != '1' \
			&& mlx->map.real_map[mlx->player.y][mlx->player.x + 1] != 'E')
	{
		mlx->map.real_map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.x++;
		if (mlx->map.real_map[mlx->player.y][mlx->player.x] == 'C')
			mlx->col.flag_c--;
		mlx->map.real_map[mlx->player.y][mlx->player.x] = 'P';
		mlx->player.f_counter++;
		ft_printf("%d\n", mlx->player.f_counter);
	}
}

static void	go_down(t_struct *mlx)
{
	int	t;

	t = mlx->map.real_map[mlx->player.y + 1][mlx->player.x] == 'X';
	if ((mlx->map.real_map[mlx->player.y + 1][mlx->player.x] == 'E' \
				&& mlx->finished) || t)
		destroy_win(mlx);
	if (mlx->map.real_map[mlx->player.y + 1][mlx->player.x] != '1' \
			&& mlx->map.real_map[mlx->player.y + 1][mlx->player.x] != 'E')
	{
		mlx->map.real_map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.y++;
		if (mlx->map.real_map[mlx->player.y][mlx->player.x] == 'C')
			mlx->col.flag_c--;
		mlx->map.real_map[mlx->player.y][mlx->player.x] = 'P';
		mlx->player.f_counter++;
		ft_printf("%d\n", mlx->player.f_counter);
	}
}

static void	go_up(t_struct *mlx)
{
	int	t;

	t = mlx->map.real_map[mlx->player.y - 1][mlx->player.x] == 'X';
	if ((mlx->map.real_map[mlx->player.y - 1][mlx->player.x] == 'E' \
				&& mlx->finished) || t)
		destroy_win(mlx);
	if (mlx->map.real_map[mlx->player.y - 1][mlx->player.x] != '1' \
			&& mlx->map.real_map[mlx->player.y - 1][mlx->player.x] != 'E')
	{
		mlx->map.real_map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.y--;
		if (mlx->map.real_map[mlx->player.y][mlx->player.x] == 'C')
			mlx->col.flag_c--;
		mlx->map.real_map[mlx->player.y][mlx->player.x] = 'P';
		mlx->player.f_counter++;
		ft_printf("%d\n", mlx->player.f_counter);
	}
}

int	key_pressed(int button, t_struct *mlx)
{
	if (button == KEY_ESC)
		destroy_win(mlx);
	else if ((button == ARROW_LEFT || button == KEY_A))
		go_left(mlx);
	else if ((button == ARROW_RIGHT || button == KEY_D))
		go_right(mlx);
	else if ((button == ARROW_DOWN || button == KEY_S))
		go_down(mlx);
	else if ((button == ARROW_UP || button == KEY_W))
		go_up(mlx);
	return (0);
}
