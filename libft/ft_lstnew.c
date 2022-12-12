/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 19:37:27 by atchougo          #+#    #+#             */
/*   Updated: 2021/11/22 21:30:52 by atchougo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*add_to_end;

	add_to_end = malloc(sizeof(t_list));
	if (!add_to_end)
		return (NULL);
	add_to_end->content = content;
	add_to_end->next = 0;
	return (add_to_end);
}
