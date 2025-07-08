/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:26:16 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/08 21:35:21 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_some_data(t_info *info)
{
	info->map_info->line_max = find_longuest_line(info->map_info->first_map);
	info->map_info->nb_lines = get_nb_lines(info->map_info->first_map);
	info->map_info->nb_players = get_nb_players(info,
			info->map_info->first_map);
	if (info->map_info->nb_players != 1)
		error(info, "Wrong number of players", 1);
	info->map_info->final_map = malloc(sizeof(char *)
			* (get_nb_lines(info->map_info->first_map) + 1));
	if (!info->map_info->final_map)
		error(info, "malloc final map failed\n", 1);
}

void	set_up_final_map(t_info *info)
{
	int	i;

	i = -1;
	init_some_data(info);
	if (!info->map_info->final_map)
		error(info, "malloc fianl map failed\n", 1);
	while (++i <= get_nb_lines(info->map_info->first_map))
		info->map_info->final_map[i] = NULL;
	if (check_is_closed(info, info->map_info->first_map))
		error(info, "The map is not closed by only wall", 1);
	equal_line(info, info->map_info->first_map);
	info->map_info->closed = true;
	info->map_info->x_max = info->map_info->line_max - 1;
	info->map_info->y_max = (int)ft_strlenlen(info->map_info->final_map) - 1;
	info->map_info->nb_lines = info->map_info->y_max + 1;
	info->map_info->map_ready = true;
}

int	is_valid(t_info *info, char *str)
{
	int	i;

	if (!str)
		return (0);
	(void)info;
	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '\n' || str[i] == ' '
			|| str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W'
			|| str[i] == '\t')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_map(t_info *info, char *str)
{
	int	i;

	if (!str)
		return (0);
	(void)info;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '\n' || str[i] == ' '
			|| str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			continue ;
		else
			return (0);
	}
	return (1);
}

void	add_x(t_info *info, size_t i, int j)
{
	while (j < info->map_info->line_max)
		info->map_info->final_map[i][j++] = 'X';
	info->map_info->final_map[i][j] = '\0';
}
