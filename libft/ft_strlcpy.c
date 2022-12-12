/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:49:29 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 05:00:21 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dstsize)
		return (srclen);
	while (--dstsize && *src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = 0;
	return (srclen);
}
