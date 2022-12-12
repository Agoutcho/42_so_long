/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:01:26 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 05:00:16 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	dst += dst_len;
	if (dstsize < dst_len || dstsize == 0 || !src)
		return (dstsize + src_len);
	dstsize--;
	while (*src && dstsize && dstsize > (dst_len))
	{
		*dst = *src;
		src++;
		dst++;
		dstsize--;
	}
	*dst = 0;
	return (dst_len + src_len);
}
