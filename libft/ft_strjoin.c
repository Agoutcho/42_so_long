/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:47:09 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 05:00:12 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr)
		return (NULL);
	temp = ptr;
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	ptr += ft_strlen(s1);
	ft_strlcpy(ptr, s2, ft_strlen(s2) + 1);
	return (temp);
}
