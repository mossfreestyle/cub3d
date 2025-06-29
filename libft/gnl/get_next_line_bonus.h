/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:24:18 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/14 02:34:26 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				create_lst(t_list **lst, int fd);
void				add_lst(t_list **lst, char *new_str);
t_list				*find_lastnode(t_list *lst);
char				*current_line(t_list *lst);
int					find_nl(t_list *lst);
int					len_nl(t_list *lst);
void				copy_content(t_list *lst, char *src);
void				clean_lst(t_list **lst);
void				free_lst(t_list **list, t_list *clean_node, char *buf);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif
#endif
