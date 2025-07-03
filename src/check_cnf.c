/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cnf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:29:30 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/03 03:55:02 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static bool ft_is_rgb(int c)
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

void	add_rgb(t_info *info, char **tmp, char c)
{
	char	*str;

	
	if (ft_strlenlen(tmp) != 4)
	{
		free_tab(tmp);
		error(info, "RGB format error", 1);
	}
	if (c != 'C' && c != 'F')
		error(info, "Error rgb", 1);
	// str = tmp[0];
	// if (str[0]== c)
	// {
	// 	str++;
	// 	while (ft_isspace(*str))
	// 		str++;
	// }
	// else
	// {
	// 	free_tab(tmp);
	// 	error(info, "Wrong Format for rgb", 1);
	// }
	if (put_color(info, tmp, str, c))
		error(info, "problem with rgb", 1);
	return ;
}

int	put_color(t_info *info, char **tmp, char *str, char c)
{
	int i;
	int j;

	i = 1;
	while (tmp[i])
	{
		j = 0;
		while(tmp[i][j])
		{
			if (!ft_isdigit(tmp[i][j]))
				return 1;
			if (ft_strlen(tmp[i]) > 3 || ft_atoi(tmp[i]) > 255
					|| ft_atoi(tmp[i]) < 0)
					return 1;
			j++;
		}
		i++;
	}
	if (tmp[0][0] == 'C')
	{
		info->assets->ceiling_color[0] = ft_atoi(tmp[1]);
		info->assets->ceiling_color[1] = ft_atoi(tmp[2]);
		info->assets->ceiling_color[2] = ft_atoi(tmp[3]);
		info->assets->c_color = true;
	}
	else if (tmp[0][0] == 'F')
	{
		info->assets->floor_color[0] = ft_atoi(tmp[1]);
		info->assets->floor_color[1] = ft_atoi(tmp[2]);
		info->assets->floor_color[2] = ft_atoi(tmp[3]);
		info->assets->f_color = true;
	}
	else
	{
		free_tab(tmp);
		error(info, "Wrong character to add rgb values", 1);
	}
	if (!check_valid_rgb(info, tmp[0][0]))
	{
		free_tab(tmp);
		error(info, "Wrong rgb values", 1);
	}
	return (0);
}

