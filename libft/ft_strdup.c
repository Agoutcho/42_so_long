/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:13:48 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 05:00:04 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*temp_ptr;

	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!(ptr))
		return (NULL);
	temp_ptr = ptr;
	while (*s1)
	{
		*temp_ptr = *s1;
		temp_ptr++;
		s1++;
	}
	*temp_ptr = 0;
	return (ptr);
}
