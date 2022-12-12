/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:59:09 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 05:00:51 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*temp;
	size_t	end;

	end = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		end = ft_strlen(s) - start;
	if (end > len)
		end = len;
	ptr = (char *)malloc(sizeof(char) * end + 1);
	if (!ptr)
		return (NULL);
	s = s + start;
	temp = ptr;
	while (end && *s)
	{
		*ptr = *s;
		end--;
		s++;
		ptr++;
	}
	*ptr = 0;
	return (temp);
}
