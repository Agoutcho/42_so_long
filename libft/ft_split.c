/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:30:58 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/14 03:41:23 by atchougo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char *s, char c)
{
	int	result;
	int	index;

	index = 0;
	result = 0;
	while (s[index])
	{
		if (!(s[index] == c) && (s[index + 1] == c || !s[index + 1]))
			result++;
		index++;
	}
	return (result);
}

static int	ft_word_size(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_copy(char *s, char c, unsigned long *temp)
{
	unsigned long		i;
	unsigned long		j;
	char				*str;

	j = 0;
	i = 0;
	str = (char *) malloc (sizeof (char) * (ft_word_size(s, c) + 1));
	while (s[j] && s[j] != c)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = 0;
	*temp = i;
	return (str);
}

static int	ft_free(char **s, int i)
{
	if (!s[i])
	{
		while (i >= 0)
		{
			free(s[i]);
			i--;
		}
		free(s);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char				**str;
	unsigned long		temp;
	unsigned long		i;

	i = 0;
	str = malloc (sizeof (char *) * (ft_count_word((char *)s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			str[i] = ft_copy((char *)s, c, &temp);
			if (ft_free(str, i))
				return (NULL);
			s += temp - 1;
			i++;
		}
		s++;
	}
	str[i] = 0;
	return (str);
}
