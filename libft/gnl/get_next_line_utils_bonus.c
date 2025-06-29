/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:23:47 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/14 02:34:18 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*current_line(t_list *lst)
{
	char	*res;
	int		len_newline;

	if (!lst)
		return (NULL);
	len_newline = len_nl(lst);
	res = malloc(len_newline + 1);
	if (!res)
		return (NULL);
	copy_content(lst, res);
	return (res);
}

int	find_nl(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
				return (1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

int	len_nl(t_list *lst)
{
	int	i;
	int	len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

void	copy_content(t_list *lst, char *str)
{
	int	i;
	int	j;

	if (!lst)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				str[j++] = '\n';
				str[j] = '\0';
				return ;
			}
			str[j++] = lst->content[i++];
		}
		lst = lst->next;
	}
	str[j] = '\0';
}

void	clean_lst(t_list **lst)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!lst || !*lst)
		return ;
	last_node = find_lastnode(*lst);
	tab = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!tab || !clean_node || !last_node)
		return (free(tab), free(clean_node), free_lst(lst, NULL, NULL));
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content[i] == '\n')
		i++;
	while (last_node->content[i])
		tab[j++] = last_node->content[i++];
	tab[j] = '\0';
	clean_node->content = tab;
	clean_node->next = NULL;
	free_lst(lst, clean_node, tab);
}
