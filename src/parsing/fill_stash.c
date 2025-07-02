/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:26:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/02 12:39:35 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_stash(t_info *info, char **av)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = 0;
	info->map_file = open(av[1], O_RDONLY);
	if (info->map_file < 0)
		error(info, "Cant open the file\n", 1);
	while ((info->map_info->stash[++i] = get_next_line(info->map_file)) != NULL)
	{
		if (info->in_map)
		{
			info->map_info->first_map[j++] = ft_strdup(info->map_info->stash[i]);
			if (!info->map_info->first_map[j - 1])
				error(info, "Problem during allocation when reading the map",
					1);
		}
		else if (info->map_info->stash[i][0] == '\n')
			continue ;
		else if (!info->valid_assets)
		{
			check_info(info, info->map_info->stash[i]);
			continue ;
		}
		info->in_map = true;
	}
	if (check_map_is_last(info))
		error(info, "The map isnt the last part of the file\n", 1);
	tmp = parse_map(info);
	info->map_info->final_map = add_tmp(info, tmp);
	// permet de choisir le bout de map ou se trouve le player
	free_tab(tmp);
	set_up_final_map(info);
	// check_final_map_is_valid();
	// setup struct genre indice de spawn, x max, y max, etc ...
}


char	*ft_strjoin_to_line_max(char *src, int limit)
{
	int		i;
	char	*res;

	i = -1;
	res = malloc(sizeof(char) * (limit + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, limit + 1);
	i = ft_strlen(res);
	while (i < limit)
		res[i++] = '1';
	res[i] = '\0';
	return (res);
}

char	**add_tmp(t_info *info, char **tmp)
{
	int		i;
	int		first;
	int		last;
	char	**res;
	int		flag;

	i = -1;
	flag = 0;
	while (tmp[i] && only_white_spaces(tmp[i]))
		i++;
	if (tmp[i])
		first = i;
	while (tmp[i] && !only_white_spaces(tmp[i]))
	{
		if (ft_strchr(tmp[i], info->player->view))
			flag = 1;
		i++;
	}
	if (!tmp[i])
	{
		if (!flag)
			error(info, "Player not found in map\n", 1);
	}
	else
	{
		if (!flag)
			return (add_tmp(info, tmp + i));
	}
	last = i - 1;
	res = malloc(sizeof(char *) * (last - first + 2));
	if (!res)
	{
		free_tab(tmp);
		error(info, "Problem during allocation to crop the map\n", 1);
	}
	i = first;
	while (i <= last)
	{
		res[i - first] = ft_strdup(tmp[i]);
		if (!res[i - first])
		{
			free_tab(res);
			free_tab(tmp);
			error(info, "Problem when copy the good part of map\n", 1);
		}
		i++;
	}
	res[last - first + 1] = NULL;
	return (res);
}
