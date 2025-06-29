/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:20:08 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/01 14:43:00 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tab;

	while (*lst)
	{
		tab = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tab;
	}
	*lst = NULL;
}
