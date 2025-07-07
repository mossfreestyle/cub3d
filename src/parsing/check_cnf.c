/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cnf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:29:30 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 18:51:18 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	ft_is_rgb(int c)
{
	if (c >= 0 && c <= 255)
		return (true);
	return (false);
}

static int	check_valid_rgb(t_info *info, char c)
{
	if (c == 'C')
	{
		if (!ft_is_rgb(info->assets->ceiling_color[0]))
			return (0);
		else if (!ft_is_rgb(info->assets->ceiling_color[1]))
			return (0);
		else if (!ft_is_rgb(info->assets->ceiling_color[2]))
			return (0);
		return (1);
	}
	else if (c == 'F')
	{
		if (!ft_is_rgb(info->assets->floor_color[0]))
			return (0);
		else if (!ft_is_rgb(info->assets->floor_color[1]))
			return (0);
		else if (!ft_is_rgb(info->assets->floor_color[2]))
			return (0);
		return (1);
	}
	return (0);
}

static void	assign_color(t_info *info, char **tmp, int *color, bool *is_set)
{
	if (*is_set)
	{
		free_tab(tmp);
		error(info, "data x2 is forbidden !!!!!!!", 1);
	}
	color[0] = ft_atoi(tmp[1]);
	color[1] = ft_atoi(tmp[2]);
	color[2] = ft_atoi(tmp[3]);
	*is_set = true;
}

static void	check_color(t_info *info, char **tmp)
{
	if (tmp[0][0] == 'C')
		assign_color(info, tmp, info->assets->ceiling_color,
			&info->assets->c_color);
	else if (tmp[0][0] == 'F')
		assign_color(info, tmp, info->assets->floor_color,
			&info->assets->f_color);
	else
	{
		free_tab(tmp);
		error(info, "Wrong character to add rgb values", 1);
	}
}

int	put_color(t_info *info, char **tmp)
{
	int	i;
	int	j;

	i = 1;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (!ft_isdigit(tmp[i][j]) && !ft_isspace(tmp[i][j]))
				return (1);
			j++;
		}
		if (ft_atoi(tmp[i]) > 255 || ft_atoi(tmp[i]) < 0)
			return (1);
		i++;
	}
	check_color(info, tmp);
	if (!check_valid_rgb(info, tmp[0][0]))
	{
		free_tab(tmp);
		error(info, "Wrong rgb values", 1);
	}
	return (0);
}
