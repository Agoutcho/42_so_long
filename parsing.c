/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:43:37 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/20 04:29:06 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	error_not_rectangle(void)
{
	ft_printf("Error\nWrong size, map should be a rectangle.\n");
	exit (1);
}

void	check_arg_error(int argc, char **argv)
{
	int	size;

	if (argc != 2)
	{
		ft_printf("Error\nWrong format, should be \"./so_long [map.ber]\"\n");
		exit (1);
	}
	size = ft_strlen (argv[1]);
	if (ft_strnstr (argv[1] + (size - 4), ".ber", size + 1) == 0)
	{
		ft_printf("Error\nMap has to be a \".ber\" file.\n");
		exit (1);
	}
}

void	char_error(char **map)
{
	ft_printf("Error\nWrong map, it should contain only :\n");
	ft_printf("- '1' for walls\n- '0' for free space\n- 'C' for coins\n");
	ft_printf("- Only 1 'E' for Exit\n- Only 1 'P' for Player\n");
	free_map(map);
	exit(1);
}

void	route_error(char **map, char **temp)
{
	ft_printf("Error\nWrong map, there is no valid route.\n");
	free_map(map);
	free_map(temp);
	exit(1);
}

int	is_a_rectangle(int *x_counter, int *y_counter)
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

void	check_flag(t_struct *mlx, char c)
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

void	check_if_map_ok(t_struct *mlx, char **map, int x_counter, int y_counter)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (j < y_counter)
	{
		while (i < x_counter)
		{
			c = map [j][i];
			if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
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

void	wall_error(char **map)
{
	ft_printf("Error\nWrong map, it should be surrounded by walls.\n");
	free_map(map);
	exit(1);
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

int	is_movable(t_struct *mlx, char **temp)
{
	if (temp[mlx->player.y][mlx->player.x + 1] == '1' \
			&& temp[mlx->player.y][mlx->player.x - 1] == '1' \
			&& temp[mlx->player.y + 1][mlx->player.x] == '1' \
			&& temp[mlx->player.y - 1][mlx->player.x] == '1')
		return (0);
	return (1);
}

void	reset_map(char **temp)
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

void	route(t_struct *mlx, char **tp, char **map, int *tab)
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
