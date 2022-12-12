/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:43:37 by atchougo          #+#    #+#             */
/*   Updated: 2022/12/12 21:24:49 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    // int *i;
    // int fd = open("map.ber", O_RDONLY);
    // i = (int *)malloc(sizeof(int) * 1000);
    // exit(0);
    // free (i);

    if (argc != 2)
	{
        printf("Wrong format, should be \"./so_long [map.ber]\"\n");
		exit (1);
	}
	if (strstr(argv[1] + (strlen(argv[1]) - 4), ".ber") == 0)
	{
        
		printf("%lu ;This map has to be a \".ber\".\n", (strlen(argv[1]) - 4));
		exit (1);
	}
    return (0);
}