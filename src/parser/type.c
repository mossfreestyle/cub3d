/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:06:32 by mglikenf          #+#    #+#             */
/*   Updated: 2025/07/07 18:34:06 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_unified.h"

int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(char *line)
{
	char	*trimmed;
	char	*set;
	int		is_map_line;

	set = "10NSWE";
	is_map_line = 0;
	trimmed = ft_strtrim(line, " \t");
	if (ft_strchr(set, trimmed[0]))
		is_map_line = 1;
	free(trimmed);
	return (is_map_line);
}

void	classify_line(char *line, t_game *cub, int *map_started, int *map_ended)
{
	if (line_is_empty(line))
	{
		if (*map_started && !(*map_ended))
			*map_ended = 1;
		return ;
	}
	if (*map_ended)
	{
		free(line);
		error_close_exit(cub, "Detected lines after map");
	}
	if (!(*map_ended) && is_config_line(line))
		parse_config(line, cub);
	else if (is_map_line(line))
	{
		*map_started = 1;
		map_list_append(cub, line, &cub->map.temp_list);
	}
	else
	{
		free(line);
		error_close_exit(cub, "Invalid line in .cub file");
	}
}
