/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 05:19:44 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 04:57:59 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	un;
	int				len;

	len = ft_len(n);
	ptr = (char *)malloc(len + 1);
	un = n;
	if (!ptr)
		return (NULL);
	if (n == 0)
		*ptr = '0';
	else if (n < 0)
	{
		*ptr = '-';
		un = -n;
	}
	ptr[len] = 0;
	while (un)
	{
		ptr[--len] = (un % 10) + '0';
		un /= 10;
	}
	return (ptr);
}
