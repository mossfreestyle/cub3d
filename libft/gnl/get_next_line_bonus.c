/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:23:29 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/19 20:54:19 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	create_lst(t_list **lst, int fd);
void	add_lst(t_list **lst, char *new_str);
t_list	*find_lastnode(t_list *lst);
void	free_lst(t_list **list, t_list *clean_node, char *tab);

char	*get_next_line(int fd)
{
	static t_list	*stash[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || fd > 1023)
	{
		free_lst(&stash[fd], NULL, NULL);
		return (NULL);
	}
	create_lst(&stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = current_line(stash[fd]);
	if (!line)
	{
		free_lst(&stash[fd], NULL, NULL);
		return (NULL);
	}
	clean_lst(&stash[fd]);
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

// #include <stdio.h>

// int	main(void)
// {
// 	char	*line1;
// 	char	*line2;
// 	int		i;

// 	int fd1, fd2;
// 	i = 0;
// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	if (fd1 < 0 || fd2 < 0)
// 	{
// 		perror("Error opening files");
// 		return (1);
// 	}
// 	line1 = get_next_line(fd1);
// 	line2 = get_next_line(fd2);
// 	printf("test1.txt: %s", line1);
// 	printf("test2.txt: %s", line2);
// 	while (line1 != NULL)
// 	{
// 		if (line1)
// 			free(line1);
// 		if (line2)
// 			free(line2);
// 		line1 = get_next_line(fd1);
// 		line2 = get_next_line(fd2);
// 		printf("test1.txt: %s", line1);
// 		printf("test2.txt: %s", line2);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
