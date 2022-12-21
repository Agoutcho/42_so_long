/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:49:09 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 04:59:22 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n)
	{
		if (*(unsigned char *)(s1) != *(unsigned char *)(s2))
			return ((*(unsigned char *)(s1) - *(unsigned char *)(s2)));
		(s1)++;
		(s2)++;
		n--;
	}
	return (0);
}
