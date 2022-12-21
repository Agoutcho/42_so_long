/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:41:55 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/21 21:51:58 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_struct *mlx)
{
	char	*pa;
	int		iw;
	int		ih;

	pa = "Mario/player/mario1.xpm";
	mlx->player.img_mario = mlx_xpm_file_to_image(mlx->mlx_ptr, pa, &iw, &ih);
	pa = "Mario/enemy.xpm";
	mlx->img_ene = mlx_xpm_file_to_image(mlx->mlx_ptr, pa, &iw, &ih);
	mlx->player.f_counter = 0;
}

void	init_end(t_struct *mlx)
{
	char	*path1;
	int		iw;
	int		ih;

	path1 = "Mario/end/end1.xpm";
	mlx->end.img_end1 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/end/end2.xpm";
	mlx->end.img_end2 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/end/end3.xpm";
	mlx->end.img_end3 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/end/end4.xpm";
	mlx->end.img_end4 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	mlx->img_end = mlx->end.img_end1;
	mlx->finished = 0;
	mlx->anim_counter = 0;
}

void	init_col(t_struct *mlx)
{
	char	*path1;
	int		iw;
	int		ih;

	mlx->col.flag_c_counter = mlx->col.flag_c;
	path1 = "Mario/col/col1.xpm";
	mlx->col.img_col1 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col2.xpm";
	mlx->col.img_col2 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col3.xpm";
	mlx->col.img_col3 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col4.xpm";
	mlx->col.img_col4 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col5.xpm";
	mlx->col.img_col5 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col6.xpm";
	mlx->col.img_col6 = mlx_xpm_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	mlx->img_col = mlx->col.img_col1;
}

static void	init_map(t_struct *mlx)
{
	int	sx;
	int	sy;

	sx = mlx->win_size_x * 32;
	sy = mlx->win_size_y * 32;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, sx, sy, "Grand Theft Auto");
}

void	init_win(t_struct *mlx)
{
	char	*path;
	int		iw;

	if (mlx->map.size_x * 32 < X)
		mlx->win_size_x = mlx->map.size_x;
	else
	{
		mlx->map.move_x = 1;
		mlx->win_size_x = X / 32;
	}
	if (mlx->map.size_y * 32 < YW)
		mlx->win_size_y = mlx->map.size_y;
	else
	{
		mlx->map.move_y = 1;
		mlx->win_size_y = YW / 32;
	}
	init_map(mlx);
	path = "Mario/wall1.xpm";
	mlx->map.img_wall = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &iw, &iw);
	path = "Mario/font.xpm";
	mlx->map.img_fn = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &iw, &iw);
}
