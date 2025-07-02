/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cnf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:29:30 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/02 12:50:04 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


static bool ft_is_rgb(int c)
{
	if (c < 0 && c > 255)
		return (false);
	return (true);
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

	if (!tmp[0] || !tmp[1] || !tmp[2] || tmp[3])
	{
		free_tab(tmp);
		error(info, "RGB format error\n", 1);
	}
	str = tmp[0];
	if (str[0] == c)
	{
		str++;
		while (ft_isspace(*str))
			str++;
	}
	else
	{
		free_tab(tmp);
		error(info, "Wrong Format for rgb\n", 1);
	}
	put_color(info, tmp, str, c);
	return ;
}

void	put_color(t_info *info, char **tmp, char *str, char c)
{
	if (c == 'C')
	{
		info->assets->ceiling_color[0] = ft_atoi(str);
		info->assets->ceiling_color[1] = ft_atoi(tmp[1]);
		info->assets->ceiling_color[2] = ft_atoi(tmp[2]);
		info->assets->c_color = true;
	}
	else if (c == 'F')
	{
		info->assets->floor_color[0] = ft_atoi(str);
		info->assets->floor_color[1] = ft_atoi(tmp[1]);
		info->assets->floor_color[2] = ft_atoi(tmp[2]);
		info->assets->f_color = true;
	}
	else
	{
		free_tab(tmp);
		error(info, "Wrong character to add rgb values\n", 1);
	}
	if (!check_valid_rgb(info, c))
	{
		free_tab(tmp);
		error(info, "Wrong rgb values values\n", 1);
	}
}
