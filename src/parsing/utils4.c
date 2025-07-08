/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 00:46:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/08 21:34:50 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	add_rgb(t_info *info, char **tmp, char c)
{
	if (ft_strlenlen(tmp) != 4)
	{
		free_tab(tmp);
		error(info, "RGB format error", 1);
	}
	if (c != 'C' && c != 'F')
	{
		free_tab(tmp);
		error(info, "Error rgb", 1);
	}
	if (put_color(info, tmp))
	{
		free_tab(tmp);
		error(info, "poblem with rgb", 1);
	}
	return ;
}

static void	check_map_line(t_info *info, char *gnl, bool *in_map,
		bool *found_empty_in_map)
{
	if (!only_white_spaces(gnl))
	{
		if (*found_empty_in_map)
		{
			free(gnl);
			error(info, "empty lines are forbidden in map", 1);
		}
		*in_map = true;
	}
	else if (*in_map)
		*found_empty_in_map = true;
}

int	is_color_line(char *line)
{
	if (!line)
		return (0);
	return (line[0] == 'C' || line[0] == 'F');
}

void	check_file(t_info *info, char **av)
{
	char	*gnl;
	bool	in_map;
	bool	found_empty;
	int		assets_count;

	in_map = false;
	found_empty = false;
	assets_count = 0;
	gnl = get_next_line(info->map_file);
	if (!gnl)
		error(info, "error gnl", 1);
	while (gnl)
	{
		if (!in_map && (is_texture(gnl) || is_color_line(gnl)))
			assets_count++;
		else if (assets_count >= 6 && is_valid(info, gnl))
			check_map_line(info, gnl, &in_map, &found_empty);
		free(gnl);
		gnl = get_next_line(info->map_file);
	}
	close(info->map_file);
	get_next_line(-1);
	info->map_file = open(av[1], O_RDONLY);
	if (info->map_file < 0)
		error(info, "Cant open the file", 1);
}

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
