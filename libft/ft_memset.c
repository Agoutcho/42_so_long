/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:53:21 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 04:59:36 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;
	unsigned char	temp_c;

	temp_c = (unsigned char)c;
	temp_b = (unsigned char *)b;
	while (len--)
	{
		*temp_b = temp_c;
		temp_b++;
	}
	return (b);
}
