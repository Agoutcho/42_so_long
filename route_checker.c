/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:54:40 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/20 05:00:10 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_movable(t_struct *mlx, char **temp)
{
	if (temp[mlx->player.y][mlx->player.x + 1] == '1' \
			&& temp[mlx->player.y][mlx->player.x - 1] == '1' \
			&& temp[mlx->player.y + 1][mlx->player.x] == '1' \
			&& temp[mlx->player.y - 1][mlx->player.x] == '1')
		return (0);
	return (1);
}

static void	reset_map(char **temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[j])
	{
		while (temp[j][i])
		{
			if (temp[j][i] == '2')
				temp[j][i] = '0';
			i++;
		}
		i = 0;
		j++;
	}
}

static void	init_tab(t_struct *mlx, int *tab, char **temp, int flag)
{
	if (flag == 0)
	{
		find_pos(mlx);
		tab[0] = 0;
		tab[1] = mlx->col.flag_c;
		tab[2] = mlx->player.x;
		tab[3] = mlx->player.y;
		tab[4] = 0;
	}
	else if (flag == 1)
	{
		temp[tab[3]][tab[2]] = '1';
		reset_map(temp);
		tab[2] = mlx->player.x;
		tab[3] = mlx->player.y;
	}
	else if (flag == 2)
	{
		tab[0] = 1;
		temp[tab[3]][tab[2]] = '1';
		reset_map(temp);
		tab[2] = mlx->player.x;
		tab[3] = mlx->player.y;
	}
}

static void	route(t_struct *mlx, char **tp, char **map, int *tab)
{
	if (!is_movable(mlx, tp))
		route_error(map, tp);
	if (tp[tab[3] - 1][tab[2]] != '1' && tp[tab[3] - 1][tab[2]] != '2')
		tab[3]--;
	else if (tp[tab[3]][tab[2] + 1] != '1' && tp[tab[3]][tab[2] + 1] != '2')
		tab[2]++;
	else if (tp[tab[3] + 1][tab[2]] != '1' && tp[tab[3] + 1][tab[2]] != '2')
		tab[3]++;
	else if (tp[tab[3]][tab[2] - 1] != '1' && tp[tab[3]][tab[2] - 1] != '2')
		tab[2]--;
	else
		init_tab(mlx, tab, tp, 1);
}

void	check_if_playable(t_struct *mlx, char **map, int x_cnt, int y_counter)
{
	int		tab[5];
	char	**temp;

	check_if_wall_ok(map, x_cnt, y_counter);
	temp = (char **)malloc (sizeof(char *) * y_counter + 1);
	init_tab(mlx, tab, temp, 0);
	while (tab[4] < y_counter)
	{
		temp[tab[4]] = ft_strdup(map[tab[4]]);
		tab[4]++;
	}
	temp[tab[4]] = 0;
	while (tab[1] || !tab[0])
	{
		route(mlx, temp, map, tab);
		if (temp[tab[3]][tab[2]] == 'E')
		{
			init_tab(mlx, tab, temp, 2);
			continue ;
		}
		else if (temp[tab[3]][tab[2]] == 'C')
			tab[1]--;
		temp[tab[3]][tab[2]] = '2';
	}
	free_map(temp);
}
