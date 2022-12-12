/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:37:17 by atchougo          #+#    #+#             */
/*   Updated: 2021/11/22 21:29:54 by atchougo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp_one;
	void	*content;

	if (!lst || !f)
		return (NULL);
	temp_one = NULL;
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
		{
			if (del)
				del(content);
			ft_lstclear(&temp_one, del);
		}
		ft_lstadd_back(&temp_one, temp);
		lst = lst->next;
	}
	return (temp_one);
}
