/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:34:23 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 18:51:39 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_player(t_info *info, int count, char c)
{
	if (count == 1)
	{
		if (c == 'N')
			info->player->view = N;
		else if (c == 'S')
			info->player->view = S;
		else if (c == 'E')
			info->player->view = E;
		else if (c == 'W')
			info->player->view = W;
	}
}

static char	assign_player(t_info *info, int i, int j, char value_pos_player)
{
	char	c;

	c = value_pos_player;
	info->map_info->x_spawn = j;
	info->map_info->y_spawn = i;
	return (c);
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
					|| map[i][j] == 'W'))
			{
				count++;
				if (count == 1)
					c = assign_player(info, i, j, map[i][j]);
			}
		}
	}
	check_player(info, count, c);
	return (count);
}

int	find_longuest_line(char **map)
{
	int	max;
	int	len;
	int	i;

	max = 0;
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max && !only_white_spaces(map[i]))
			max = len;
		i++;
	}
	return (max);
}

char	*recup_gnl(int fd)
{
	char	*str;
	char	*tmp;
	int		i;

	str = NULL;
	if (fd == -1)
		return (NULL);
	while (1)
	{
		i = -1;
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		while (tmp[++i])
			if (!ft_isprint(tmp[i]) && tmp[i] != '\n' && tmp[i] != '\0'
				&& tmp[i] != '\t')
				return (free(str), free(tmp), get_next_line(-1), close(fd),
					NULL);
		str = ft_strjoin(str, tmp);
		if (!str)
			return (close(fd), NULL);
	}
	close(fd);
	return (str);
}
