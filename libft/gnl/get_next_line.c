/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:23:29 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/14 23:32:32 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_lst(t_list **lst, int fd);
void	add_lst(t_list **lst, char *new_str);
t_list	*find_lastnode(t_list *lst);
void	free_lst(t_list **list, t_list *clean_node, char *tab);

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free_lst(&stash, NULL, NULL);
		return (NULL);
	}
	create_lst(&stash, fd);
	if (!stash)
		return (NULL);
	line = current_line(stash);
	if (!line)
	{
		free_lst(&stash, NULL, NULL);
		return (NULL);
	}
	clean_lst(&stash);
	return (line);
}

void	create_lst(t_list **lst, int fd)
{
	char	*str;
	int		bytes_read;

	if (!lst)
		return ;
	while (!find_nl(*lst))
	{
		str = malloc(BUFFER_SIZE + 1);
		if (!str)
		{
			free_lst(lst, NULL, NULL);
			return ;
		}
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(str);
			if (bytes_read < 0)
				free_lst(lst, NULL, NULL);
			return ;
		}
		str[bytes_read] = '\0';
		add_lst(lst, str);
	}
}

void	add_lst(t_list **lst, char *new_str)
{
	t_list	*new_node;
	t_list	*last_node;

	if (!new_str)
		return ;
	new_node = malloc(sizeof(t_list));
	if (!new_node)
	{
		free(new_str);
		return ;
	}
	last_node = find_lastnode(*lst);
	if (!last_node)
		*lst = new_node;
	else
		last_node->next = new_node;
	new_node->content = new_str;
	new_node->next = NULL;
}

t_list	*find_lastnode(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	free_lst(t_list **lst, t_list *clean_node, char *tab)
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
	if (clean_node && clean_node->content && clean_node->content[0])
		*lst = clean_node;
	else
	{
		free(tab);
		free(clean_node);
	}
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("test1.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
