/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:51:14 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/19 20:54:05 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		lst = &(*lst)->next;
	(*lst)->next = new;
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
		printf("%i\n", *(int *)lst->content);
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
		printlst(lst);
		new++;
		i++;
	}
	new = 15;
	ft_lstadd_back(&lst, (void *)&new);
	printf("\n%d\n", ft_lstsize(lst));
	printlst(lst);
}
*/