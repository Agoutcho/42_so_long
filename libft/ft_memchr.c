/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:36:15 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 04:59:13 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			temp_c;
	char			*temp_s;

	temp_s = (char *)s;
	temp_c = (char)c;
	while (n)
	{
		if (*temp_s == temp_c)
			return ((void *)temp_s);
		temp_s++;
		n--;
	}
	return (NULL);
}
