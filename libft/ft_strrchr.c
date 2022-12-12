/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:38:06 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 05:00:44 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	temp_c;
	size_t	s_len;

	temp_c = (char) c;
	s_len = ft_strlen(s);
	if (temp_c == 0)
		return ((char *)(s + s_len));
	if (s_len == 0)
		s_len++;
	while (s_len--)
	{
		if (s[s_len] == temp_c)
		{
			s += s_len;
			return ((char *)s);
		}
	}
	return (NULL);
}
