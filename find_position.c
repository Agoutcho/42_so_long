/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:45:01 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/20 04:45:40 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
