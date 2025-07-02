/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:34:23 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/02 12:48:40 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


int	get_nb_lines(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		continue ;
	return (i);
}

int	only_white_spaces(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	while (str[++i])
	{
		if (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i] != '\n'
			&& str[i])
			continue ;
		return (0);
	}
	return (1);
}


int	get_nb_players(t_info *info, char **map)
{
	int		i;
	int		j;
	int		count;
	char	c;

	c = 0;
	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S'
					|| map[i][j] == 'O'))
			{
				count++;
				if (count == 1)
				{
					c = map[i][j];
					info->map_info->x_spawn = j;
					info->map_info->y_spawn = i;
				}
			}
		}
	}
	if (count == 1)
		info->player->view = c;
	return (count);
}

int	find_longuest_line(char **map)
{
	int		i;
	size_t	max_line;

	i = -1;
	max_line = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > max_line)
			max_line = ft_strlen(map[i]);
	}
	return (max_line);
}

int	is_valid(t_info *info, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '\n' || str[i] == ' '
			|| str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'O')
			continue ;
		else
			return (0);
	}
	return (1);
}
