/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:29:01 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 04:59:31 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;
	size_t			elevision;

	elevision = 0;
	temp_src = (unsigned char *)src;
	temp_dst = (unsigned char *)dst;
	if (dst == 0 && src == 0)
		return (dst);
	if (dst >= src)
	{
		while (len--)
		{
			temp_dst[len] = temp_src[len];
		}
	}
	else
	{
		while (elevision < len)
		{
			temp_dst[elevision] = temp_src[elevision];
			elevision++;
		}
	}
	return (dst);
}
