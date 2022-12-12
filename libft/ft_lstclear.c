/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:28:42 by atchougo          #+#    #+#             */
/*   Updated: 2021/11/22 21:29:29 by atchougo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_next;

	if (!*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		temp_next = temp->next;
		del(temp->content);
		free(temp);
		temp = temp_next;
	}
	*lst = NULL;
}
