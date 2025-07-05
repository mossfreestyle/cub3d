/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:26:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/05 13:41:37 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	str = recup_gnl(info->map_file);
	if (!str)
		error(info, "error recup gnl", 1);
	info->map_info->stash = ft_split(str, "\n");
	free(str);
	i = -1;
	while (info->map_info->stash[++i] != NULL)
	{
		if (info->in_map)
		{
			if (!info->map_info->first_map)
			{
				info->map_info->first_map = malloc(sizeof(char *)
						* (get_nb_lines(info->map_info->stash + i) + 1));
				if (!info->map_info->first_map)
					error(info, "probelem malloc", 1);
			}
			info->map_info->first_map[j++] = ft_strdup(info->map_info->stash[i]);
			if (!info->map_info->first_map[j - 1])
				error(info, "Problem during allocation when reading the map",
					1);
			if (info->map_info->stash[i + 1] == NULL)
				info->map_copied = true;
		}
		if (!ft_strncmp(info->map_info->stash[i], "\n", 1))
			continue ;
		if (!is_texture(info->map_info->stash[i]) && !is_valid(info,
				info->map_info->stash[i]))
			error(info, "Invalid line in map file", 1);
		if (!info->valid_assets)
		{
			check_info(info, info->map_info->stash[i]);
			if (info->valid_assets)
				info->in_map = true;
			continue ;
		}
	}
	if (info->map_copied)
		info->map_info->first_map[j] = NULL;
	else
		error(info, "Invalid map", 1);
	if (check_map_is_last(info, info->map_info->first_map))
		error(info, "Map format isnt good", 1);
	set_up_final_map(info);
	// check_final_map_is_valid();
	// setup struct genre indice de spawn, x max, y max, etc ...
}

// char	*equal_line(char *src, int limit)
// {
// 	int		i;
// 	char	*res;

// 	i = -1;
// 	res = malloc(sizeof(char) * (limit + 1));
// 	if (!res)
// 		return (NULL);
// 	ft_strlcpy(res, src, limit + 1);
// 	i = ft_strlen(res);
// 	while (i < limit)
// 		res[i++] = 'X';
// 	res[i] = '\0';
// 	return (res);
// }

char	*equal_line(char *src, int limit)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (limit + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (src[i] && i < limit)
	{
		if (src[i] == 32)
		{
			if (only_white_spaces(src + i))
				res[i] = 'X';
			else
				res[i] = 'V';
		}
		else
			res[i] = src[i];
		i++;
	}
	while (i < limit)
		res[i++] = 'X';
	res[i] = '\0';
	return (res);
}
