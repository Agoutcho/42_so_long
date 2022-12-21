/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:33:38 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/21 23:14:01 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_win(t_struct *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_image(mlx->mlx_ptr, mlx->player.img_mario);
	mlx_destroy_image(mlx->mlx_ptr, mlx->col.img_col1);
	mlx_destroy_image(mlx->mlx_ptr, mlx->col.img_col2);
	mlx_destroy_image(mlx->mlx_ptr, mlx->col.img_col3);
	mlx_destroy_image(mlx->mlx_ptr, mlx->col.img_col4);
	mlx_destroy_image(mlx->mlx_ptr, mlx->col.img_col5);
	mlx_destroy_image(mlx->mlx_ptr, mlx->col.img_col6);
	mlx_destroy_image(mlx->mlx_ptr, mlx->end.img_end1);
	mlx_destroy_image(mlx->mlx_ptr, mlx->end.img_end2);
	mlx_destroy_image(mlx->mlx_ptr, mlx->end.img_end3);
	mlx_destroy_image(mlx->mlx_ptr, mlx->end.img_end4);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map.img_wall);
	mlx_destroy_image(mlx->mlx_ptr, mlx->map.img_fn);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

static void	finished(t_struct *mlx)
{
	if (mlx->finished == 0)
		mlx->img_end = mlx->end.img_end1;
	else if (mlx->finished == 1)
	{
		mlx->finished = 2;
		mlx->img_end = mlx->end.img_end2;
	}
	else if (mlx->finished == 2)
		mlx->img_end = mlx->end.img_end3;
}

int	anim(t_struct *mlx)
{
	fill_min_max(mlx, 0);
	if (mlx->anim_counter % 50 == 0)
		render_map(mlx);
	if (mlx->anim_counter % 100 == 0)
		finished(mlx);
	if (mlx->anim_counter == 1)
		mlx->img_col = mlx->col.img_col1;
	else if (mlx->anim_counter == 1500 / mlx->win_size_x)
		mlx->img_col = mlx->col.img_col2;
	else if (mlx->anim_counter == 3000 / mlx->win_size_x)
		mlx->img_col = mlx->col.img_col3;
	else if (mlx->anim_counter == 4500 / mlx->win_size_x)
		mlx->img_col = mlx->col.img_col4;
	else if (mlx->anim_counter == 6000 / mlx->win_size_x)
		mlx->img_col = mlx->col.img_col5;
	else if (mlx->anim_counter == 7500 / mlx->win_size_x)
	{
		mlx->img_col = mlx->col.img_col6;
		mlx->anim_counter = 0;
	}
	if (!mlx->col.flag_c && mlx->finished < 2)
		mlx->finished = 1;
	mlx->anim_counter++;
	return (0);
}

void	init(int argc, char **argv, t_struct *mlx)
{
	mlx->player.flag_p = 0;
	mlx->end.flag_e = 0;
	mlx->col.flag_c = 0;
	mlx->map.size_x = 0;
	mlx->map.size_y = 0;
	parsing(argc, argv, mlx);
	init_win(mlx);
	init_player(mlx);
	init_end(mlx);
	init_col(mlx);
	find_pos(mlx);
	fill_min_max(mlx, 1);
}

int	main(int argc, char **argv)
{
	t_struct	mlx;

	init(argc, argv, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, anim, &mlx);
	mlx_hook(mlx.win_ptr, 2, (1L << 1), key_pressed, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0L, destroy_win, &mlx);
	mlx_loop(mlx.mlx_ptr);
	free_map(mlx.map.real_map);
	return (0);
}
