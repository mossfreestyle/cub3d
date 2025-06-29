/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:23:32 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/02 15:50:36 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tab;
	t_list	*new_ele;
	t_list	*new_content;

	tab = NULL;
	new_ele = NULL;
	while (lst)
	{
		new_content = f(lst -> content);
		new_ele = ft_lstnew(new_content);
		if (!new_ele)
		{
			del (new_content);
			ft_lstclear(&tab, del);
			return (NULL);
		}
		ft_lstadd_back(&tab, new_ele);
		lst = lst->next;
	}
	return (tab);
}
