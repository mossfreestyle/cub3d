/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:36:36 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 18:51:51 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_double_comma(t_info *info, char *stash)
{
	int	i;
	int	count;
	int	j;

	i = -1;
	count = 0;
	j = 1;
	while (stash[++i])
	{
		if (stash[i] == ',')
			count++;
	}
	if (count != 2)
		error(info, "Wrong number of comma for rgb values", 1);
	while (ft_isspace(stash[j]))
		j++;
	while (stash[j])
	{
		if (!ft_isdigit(stash[j]) && stash[j] != ',' && !ft_isspace(stash[j]))
			error(info, "only digit and ; are avaible in color", 1);
		j++;
	}
}

int	is_texture_line(char **stash)
{
	if (!stash[0])
		return (0);
	return (!ft_strncmp("NO", stash[0], 2) || !ft_strncmp("SO", stash[0], 2)
		|| !ft_strncmp("EA", stash[0], 2) || !ft_strncmp("WE", stash[0], 2));
}

int	is_texture(char *stash)
{
	if (!stash)
		return (0);
	return (!ft_strncmp("NO", stash, 2) || !ft_strncmp("SO", stash, 2)
		|| !ft_strncmp("EA", stash, 2) || !ft_strncmp("WE", stash, 2)
		|| !ft_strncmp("C", stash, 1) || !ft_strncmp("F", stash, 1));
}

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

	if (!str)
		return (1);
	i = -1;
	while (str[++i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
	}
	return (1);
}
