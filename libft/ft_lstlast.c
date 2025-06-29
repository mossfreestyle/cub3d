/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:28:23 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/01 13:57:09 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(lst) - 1)
		lst = lst->next;
	return (lst);
}

/*
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	lst[0] -> content = new;
}


t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

static void	printlst(t_list *lst)
{
	while (lst)
	{
		printf("%d\n", *(int *)lst->content);
		lst = lst->next;
	}
}


int	main(void)
{
	int		n;
	int		new;
	int		i;
	t_list	*lst;

	n = 50;
	new = 125;
	i = 0;
	lst = ft_lstnew((void *)&n);
	while(i <  5)
	{
		ft_lstadd_front(&lst, (void *)&new);
		new++;
		i++;
	}
	printlst(lst);
	printlst(ft_lstlast(lst));
}
*/