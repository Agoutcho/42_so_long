/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:42:28 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 05:00:36 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if (*s1 != *s2)
		{
			return (((unsigned char)(*s1) - (unsigned char)(*s2)));
		}
		s1++;
		s2++;
		if ((!*s1 || !*s2) && n > 1)
		{
			return (((unsigned char)(*s1) - (unsigned char)(*s2)));
		}
		n--;
	}
	return (0);
}
