/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:19:15 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 05:00:47 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischar(char ptr, const char *set)
{
	size_t	counter_set;

	counter_set = 0;
	while (set[counter_set])
	{
		if (ptr == set[counter_set])
		{
			return (1);
		}
		else
			counter_set++;
	}
	return (0);
}

static char	*ft_substr_end(char const *s, unsigned int start, size_t end)
{
	char	*ptr;
	char	*temp;
	size_t	total_len;

	total_len = (end - start);
	ptr = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!ptr)
		return (NULL);
	s = s + start;
	temp = ptr;
	while (total_len && *s)
	{
		*ptr = *s;
		total_len--;
		s++;
		ptr++;
	}
	*ptr = 0;
	return (temp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_ischar(s1[start], set))
		start++;
	if (start == (end + 1))
		return (ft_substr_end(s1, start, start));
	while (ft_ischar(s1[end], set))
		end--;
	return (ft_substr_end(s1, start, end + 1));
}
