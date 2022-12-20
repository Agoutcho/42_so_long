/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:47:00 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/20 04:59:49 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	wall_error(char **map)
{
	ft_printf("Error\nWrong map, it should be surrounded by walls.\n");
	free_map(map);
	exit(1);
}
