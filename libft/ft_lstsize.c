/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:20:54 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/15 19:08:17 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
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
		printlst(lst);
		new++;
		i++;
	}
	printf("\n%d\n", ft_lstsize(lst));
}
*/