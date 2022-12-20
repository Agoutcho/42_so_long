/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:33:38 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/20 02:11:03 by atchougo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int button, t_struct *mlx);
int	anim(t_struct *mlx);
int	render_map(t_struct *mlx);

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
	mlx_destroy_image(mlx->mlx_ptr, mlx->map.img_font);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
	return (0);
}

int	key_pressed(int button, t_struct *mlx)
{
	if (button == KEY_ESC)
		destroy_win(mlx);
	else if ((button == ARROW_LEFT || button == KEY_A))
	{
		if (mlx->map.real_map[mlx->player.y][mlx->player.x - 1] == 'E' \
				&& mlx->finished)
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
	else if ((button == ARROW_RIGHT || button == KEY_D))
	{
		if (mlx->map.real_map[mlx->player.y][mlx->player.x + 1] == 'E' \
				&& mlx->finished)
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
	else if ((button == ARROW_DOWN || button == KEY_S))
	{
		if (mlx->map.real_map[mlx->player.y + 1][mlx->player.x] == 'E' \
				&& mlx->finished)
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
	else if ((button == ARROW_UP || button == KEY_W))
	{
		if (mlx->map.real_map[mlx->player.y - 1][mlx->player.x] == 'E' \
				&& mlx->finished)
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
	render_map(mlx);
	return (0);
}

// anim_counter : 10 000 = 1sec
int	anim(t_struct *mlx)
{
	if (mlx->anim_counter == 0 && !mlx->finished)
	{
		mlx->img_col = mlx->col.img_col1;
		if (mlx->finished == 0)
			mlx->img_end = mlx->end.img_end1;
		render_map(mlx);
	}
	else if (mlx->anim_counter == 1500)
	{
		mlx->img_col = mlx->col.img_col2;
		render_map(mlx);
	}
	else if (mlx->anim_counter == 3000)
	{
		mlx->img_col = mlx->col.img_col3;
		if (mlx->finished == 1)
		{
			mlx->finished = 2;
			mlx->img_end = mlx->end.img_end2;
		}
		render_map(mlx);
	}
	else if (mlx->anim_counter == 4500)
	{
		mlx->img_col = mlx->col.img_col4;
		render_map(mlx);
	}
	else if (mlx->anim_counter == 6000)
	{
		mlx->img_col = mlx->col.img_col5;
		render_map(mlx);
	}
	else if (mlx->anim_counter == 7500)
	{
		mlx->img_col = mlx->col.img_col6;
		if (mlx->finished == 2)
			mlx->img_end = mlx->end.img_end3;
		render_map(mlx);
		mlx->anim_counter = 0;
	}
	if (!mlx->col.flag_c && mlx->finished < 2)
		mlx->finished = 1;
	mlx->anim_counter++;
	return (0);
}

int	render_map(t_struct *mlx)
{
	char	*temp;
	int		i;
	int		j;
	int		i2;
	int		j2;

	fill_min_max(mlx);
	i2 = 0;
	j2 = 0;
	i = mlx->map.min_x;
	j = mlx->map.min_y;
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_font, 0, 0);
	while (j < mlx->map.max_y)
	{
		while (i < mlx->map.max_x)
		{
			if (mlx->map.real_map[j][i] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_wall, i2 * 32, j2 * 32);
			else if (mlx->map.real_map[j][i] == 'P')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player.img_mario, i2 * 32, j2 * 32);
			else if (mlx->map.real_map[j][i] == 'E')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->end.img_end4, i2 * 32, j2 * 32);
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_end, i2 * 32, j2 * 32);
			}
			else if (mlx->map.real_map[j][i] == 'C')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_col, i2 * 32, j2 * 32);
			i++;
			i2++;
		}
		j++;
		j2++;
		i = mlx->map.min_x;
		i2 = 0;
	}
	temp = ft_itoa(mlx->player.f_counter);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 16, 20, 0x00FFFFFF, temp);
	free (temp);
	return (0);
}

void	check_x_max(t_struct *mlx, int test)
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

void	check_x_min(t_struct *mlx, int test)
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
}

void	check_y_min(t_struct *mlx, int test)
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
}

void	check_y_max(t_struct *mlx, int test)
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

void	init_min_max(t_struct *mlx)
{
	check_x_min(mlx, 1);
	check_x_max(mlx, 1);
	check_y_min(mlx, 1);
	check_y_max(mlx, 1);
}

void	fill_min_max(t_struct *mlx)
{
	check_x_min(mlx, 0);
	check_x_max(mlx, 0);
	check_y_min(mlx, 0);
	check_y_max(mlx, 0);
}

void	fill_pos(t_struct *mlx, char c, int i, int j)
{
	if (c == 'P')
	{
		mlx->player.x = i;
		mlx->player.y = j;
	}
}

void	find_pos(t_struct *mlx)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (j < mlx->map.size_y)
	{
		while (i < mlx->map.size_x)
		{
			c = mlx->map.real_map[j][i];
			if (c == 'P')
			{
				mlx->player.x = i;
				mlx->player.y = j;
				return ;
			}
			i++;
		}
		j++;
		i = 0;
	}
}

void	init_player(t_struct *mlx)
{
	char	*pa;
	int		iw;
	int		ih;

	pa = "Mario/player/mario1.png";
	mlx->player.img_mario = mlx_png_file_to_image(mlx->mlx_ptr, pa, &iw, &ih);
	mlx->player.f_counter = 0;
}

void	init_end(t_struct *mlx)
{
	char	*path1;
	int		iw;
	int		ih;

	path1 = "Mario/end/end1.png";
	mlx->end.img_end1 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/end/end2.png";
	mlx->end.img_end2 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/end/end3.png";
	mlx->end.img_end3 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/end/end4.png";
	mlx->end.img_end4 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
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
	path1 = "Mario/col/col1.png";
	mlx->col.img_col1 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col2.png";
	mlx->col.img_col2 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col3.png";
	mlx->col.img_col3 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col4.png";
	mlx->col.img_col4 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col5.png";
	mlx->col.img_col5 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	path1 = "Mario/col/col6.png";
	mlx->col.img_col6 = mlx_png_file_to_image(mlx->mlx_ptr, path1, &iw, &ih);
	mlx->img_col = mlx->col.img_col1;
}

void	init_map(t_struct *mlx)
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
	path = "Mario/wall1.png";
	mlx->map.img_wall = mlx_png_file_to_image(mlx->mlx_ptr, path, &iw, &iw);
	path = "Mario/font.png";
	mlx->map.img_font = mlx_png_file_to_image(mlx->mlx_ptr, path, &iw, &iw);
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
	init_min_max(mlx);
}

int	main(int argc, char **argv)
{
	t_struct	mlx;

	init(argc, argv, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, anim, &mlx);
	mlx_hook(mlx.win_ptr, 3, (1L << 1), key_pressed, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0L, destroy_win, &mlx);
	mlx_loop(mlx.mlx_ptr);
	free_map(mlx.map.real_map);
	return (0);
}
