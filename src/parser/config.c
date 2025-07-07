/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:41:30 by mglikenf          #+#    #+#             */
/*   Updated: 2025/05/01 20:11:52 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_unified.h"

void	extract_path(char *line, char **dst, t_game *cub)
{
	char	**subs;

	subs = ft_split(line, ' ');
	if (!subs || !subs[0] || !subs[1] || subs[2])
	{
		free(line);
		free_tab(subs);
		error_close_exit(cub, "Invalid texture line format");
	}
	if (*dst)
	{
		free(line);
		free_tab(subs);
		error_close_exit(cub, "Duplicate configuration for texture");
	}
	*dst = ft_strdup(subs[1]);
	if (!(*dst))
	{
		free(line);
		free_tab(subs);
		error_close_exit(cub, "Malloc failed");
	}
	free_tab(subs);
}

void	parse_config(char *line, t_game *cub)
{
	while (*line && (*line == ' ' || *line == '\t'))
		++line;
	if (ft_strncmp(line, "NO ", 3) == 0)
		extract_path(line, &cub->map.no_texture, cub);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		extract_path(line, &cub->map.so_texture, cub);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		extract_path(line, &cub->map.we_texture, cub);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		extract_path(line, &cub->map.ea_texture, cub);
	else if (ft_strncmp(line, "F ", 2) == 0)
		cub->map.floor_rgb = parse_rgb_line(cub, line, &cub->map.floor_rgb);
	else if (ft_strncmp(line, "C ", 2) == 0)
		cub->map.ceiling_rgb = parse_rgb_line(cub, line, &cub->map.ceiling_rgb);
	else
	{
		free(line);
		error_close_exit(cub, "Invalid line in .cub file");
	}
}

int	is_config_line(char *s)
{
	while (*s == ' ' || *s == '\t')
		++s;
	return (!ft_strncmp(s, "NO", 2) || !ft_strncmp(s, "SO", 2)
		|| !ft_strncmp(s, "WE", 2) || !ft_strncmp(s, "EA", 2)
		|| !ft_strncmp(s, "F", 1) || !ft_strncmp(s, "C", 1));
}
