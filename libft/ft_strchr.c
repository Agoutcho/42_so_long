/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:21:44 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 04:58:51 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	temp_c;

	temp_c = (char) c;
	while (*s)
	{
		if (*s == temp_c)
			return ((char *)s);
		s++;
	}
	if (temp_c == 0)
		return ((char *)s);
	return (NULL);
}
