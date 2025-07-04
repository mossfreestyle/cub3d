/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:27:19 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/04 16:24:23 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_double_comma(t_info *info, char *stash)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	int j = 1;
	while (stash[++i])
	{
		if (stash[i] == ',')
			count++;
	}
	if (count != 2)
		error(info, "Wrong number of comma for rgb values", 1);
	while(ft_isspace(stash[j]))
		j++;
	while(stash[j])
	{
		if (!ft_isdigit(stash[j]) && stash[j] != ',')
			error(info, "only digit and ; are avaible in color", 1);
		j++;
	}
		
}

static void	put_true_to_valid_assets(t_info *info)
{
	if (info->assets->path_no && info->assets->path_so && info->assets->path_we
		&& info->assets->path_ea && info->assets->c_color
		&& info->assets->f_color)
		info->valid_assets = true;
	if (info->assets->valid_cardinals && info->assets->c_color
		&& info->assets->f_color)
		info->valid_assets = true;
}

static char	*check_valid_path(t_info *info, char *stash)
{
	char	*path;
	int		len;

	len = ft_strlen(stash);
	if (ft_strncmp(stash + len - 4, ".xpm", 4))
		error(info, "Need a valid .xpm file", 1);
	path = ft_strdup(stash);
	if (!path)
		error(info, "Malloc failed when allocating for path", 1);
	return (path);
}

static int	check_path(t_info *info, char **stash)
{
	if (stash[0][0] == 'C' || stash[0][0] == 'F')
		return (1);
	if (ft_strlenlen(stash) != 2)
		error(info, "Error cardinals", 1);
	if (!ft_strncmp("NO", stash[0], 2))
	{
		if (info->assets->path_no)
			error(info, "data x2 is forbidden !!!!!!!", 1);
		info->assets->path_no = check_valid_path(info, stash[1]);
	}
	else if (!ft_strncmp("SO", stash[0], 2))
	{
		if (info->assets->path_so)
			error(info, "data x2 is forbidden !!!!!!!", 1);
		info->assets->path_so = check_valid_path(info, stash[1]);
	}
	else if (!ft_strncmp("EA", stash[0], 2))
	{
		if (info->assets->path_ea)
			error(info, "data x2 is forbidden !!!!!!!", 1);
		info->assets->path_ea = check_valid_path(info, stash[1]);
	}
	else if (!ft_strncmp("WE", stash[0], 2))
	{
		if (info->assets->path_we)
			error(info, "data x2 is forbidden !!!!!!!", 1);
		info->assets->path_we = check_valid_path(info, stash[1]);
	}
	else
		error(info, "Wrong cardinals", 1);
	if (info->assets->path_no && info->assets->path_so && info->assets->path_ea
		&& info->assets->path_we)
		info->assets->valid_cardinals = true;
	return (1);
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

void	check_info(t_info *info, char *stash)
{
	char	**tmp;

	tmp = ft_split(stash, " ");
	if (!tmp)
		error(info, "failed malloc", 1);
	if (is_texture_line(tmp))
	{
		check_path(info, tmp);
		free_tab(tmp);
		put_true_to_valid_assets(info);
		return ;
	}
	if (tmp[0][0] == 'C' || tmp[0][0] == 'F')
	{
		free_tab(tmp);
		check_double_comma(info, stash);
		tmp = ft_split(stash, " ,");
		if (!tmp)
			error(info, "Split Failed for RGB values", 1);
		add_rgb(info, tmp, tmp[0][0]);
		free_tab(tmp);
		put_true_to_valid_assets(info);
		return ;
	}
	free_tab(tmp);
}
