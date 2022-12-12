/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:49:25 by atchougo          #+#    #+#             */
/*   Updated: 2021/11/20 16:54:17 by atchougo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*temp_needle;
	char	*temp_haystack;
	size_t	temp_len;

	temp_len = len;
	temp_haystack = (char *)haystack;
	temp_needle = (char *)needle;
	if (!*needle)
		return ((char *)haystack);
	while (*temp_haystack && len)
	{
		while (len-- && *temp_haystack == *temp_needle && *temp_needle)
		{
			temp_haystack++;
			temp_needle++;
			if (!*temp_needle)
				return ((char *)haystack);
		}
		len = --temp_len;
		haystack++;
		temp_haystack = (char *)haystack;
		temp_needle = (char *)needle;
	}
	return (NULL);
}
