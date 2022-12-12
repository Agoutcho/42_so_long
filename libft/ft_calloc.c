/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:10:26 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 04:57:34 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	size_t			sum;

	sum = count * size;
	result = (unsigned char *) malloc(sum);
	if (!result)
		return (NULL);
	while (sum--)
		result[sum] = 0;
	return ((void *)result);
}
