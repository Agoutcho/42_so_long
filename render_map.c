/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:35:57 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/20 04:40:14 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_map_checker(t_struct *mlx, int *tab)
{
	if (mlx->map.real_map[tab[3]][tab[2]] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
				mlx->map.img_wall, tab[0] * 32, tab[1] * 32);
	else if (mlx->map.real_map[tab[3]][tab[2]] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
				mlx->player.img_mario, tab[0] * 32, tab[1] * 32);
	else if (mlx->map.real_map[tab[3]][tab[2]] == 'E')
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
				mlx->end.img_end4, tab[0] * 32, tab[1] * 32);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
				mlx->img_end, tab[0] * 32, tab[1] * 32);
	}
	else if (mlx->map.real_map[tab[3]][tab[2]] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
				mlx->img_col, tab[0] * 32, tab[1] * 32);
}

static void	init_tab(t_struct *mlx, int *tab)
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = mlx->map.min_x;
	tab[3] = mlx->map.min_y;
}

int	render_map(t_struct *mlx)
{
	char	*temp;
	int		tab[4];

	fill_min_max(mlx, 0);
	init_tab(mlx, tab);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->map.img_fn, 0, 0);
	while (tab[3] < mlx->map.max_y)
	{
		while (tab[2] < mlx->map.max_x)
		{
			render_map_checker(mlx, tab);
			tab[2]++;
			tab[0]++;
		}
		tab[3]++;
		tab[1]++;
		tab[2] = mlx->map.min_x;
		tab[0] = 0;
	}
	temp = ft_itoa(mlx->player.f_counter);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 16, 20, 0x00FFFFFF, temp);
	free (temp);
	return (0);
}
