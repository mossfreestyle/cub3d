/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:26:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/08 21:34:35 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ft_dup(const char *s)
{
	int		i;
	char	*tab;

	tab = (char *)s;
	i = 0;
	tab = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static void	add_first_map_line(t_info *info, int *j, int i)
{
	if (!info->map_info->first_map)
	{
		info->map_info->first_map = ft_calloc(get_nb_lines(info->map_info->stash
					+ i) + 1, sizeof(char *));
		if (!info->map_info->first_map)
			error(info, "problem malloc", 1);
	}
	info->map_info->first_map[(*j)++] = ft_dup(info->map_info->stash[i]);
	if (!info->map_info->first_map[(*j) - 1])
		error(info, "Problem during allocation when reading the map", 1);
	if (info->map_info->stash[i + 1] == NULL)
		info->map_copied = true;
}

static void	process_stash_line(t_info *info, int *j, int i)
{
	if (info->in_map)
		add_first_map_line(info, j, i);
	if (!ft_strncmp(info->map_info->stash[i], "\n", 1))
		return ;
	if (!is_texture(info->map_info->stash[i]) && !is_valid(info,
			info->map_info->stash[i]))
		error(info, "Invalid line in map file", 1);
	if (!info->valid_assets)
	{
		check_info(info, info->map_info->stash[i]);
		if (info->valid_assets)
			info->in_map = true;
	}
}

void	fill_stash(t_info *info, char **av)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	info->map_file = open(av[1], O_RDONLY);
	if (info->map_file < 0)
		error(info, "Cant open the file", 1);
	check_file(info, av);
	str = recup_gnl(info->map_file);
	if (!str)
		error(info, "error recup gnl", 1);
	info->map_info->stash = ft_split(str, "\n");
	free(str);
	while (info->map_info->stash[++i])
		process_stash_line(info, &j, i);
	if (info->map_copied)
		info->map_info->first_map[j] = NULL;
	else
		error(info, "Invalid map", 1);
	if (check_map_is_last(info, info->map_info->first_map))
		error(info, "Map format isnt good", 1);
	set_up_final_map(info);
}
