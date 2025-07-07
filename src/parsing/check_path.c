/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:27:19 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 18:51:26 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

static char	*check_valid_path(t_info *info, char *stash, char **tmp)
{
	char	*path;
	int		len;

	len = ft_strlen(stash);
	if (len < 4)
	{
		free_tab(tmp);
		error(info, "Path too short, need .xpm extension", 1);
	}
	if (ft_strncmp(stash + len - 4, ".xpm", 4))
	{
		free_tab(tmp);
		error(info, "Need a valid .xpm file", 1);
	}
	path = ft_strdup(stash);
	if (!path)
	{
		free_tab(tmp);
		error(info, "Malloc failed when allocating for path", 1);
	}
	return (path);
}

static char	*assign_path(t_info *info, char *path, char **stash)
{
	if (path)
	{
		free_tab(stash);
		error(info, "data x2 is forbidden !!!!!!!", 1);
	}
	path = check_valid_path(info, stash[1], stash);
	if (!path)
		return (NULL);
	return (path);
}

static int	check_path(t_info *info, char **stash)
{
	if (stash[0][0] == 'C' || stash[0][0] == 'F')
		return (1);
	if (ft_strlenlen(stash) != 2)
		error(info, "Error cardinals", 1);
	if (!ft_strncmp("NO", stash[0], 2))
		info->assets->path_no = assign_path(info, info->assets->path_no, stash);
	else if (!ft_strncmp("SO", stash[0], 2))
		info->assets->path_so = assign_path(info, info->assets->path_so, stash);
	else if (!ft_strncmp("EA", stash[0], 2))
		info->assets->path_ea = assign_path(info, info->assets->path_ea, stash);
	else if (!ft_strncmp("WE", stash[0], 2))
		info->assets->path_we = assign_path(info, info->assets->path_we, stash);
	else
		error(info, "Wrong cardinals", 1);
	if (info->assets->path_no && info->assets->path_so && info->assets->path_ea
		&& info->assets->path_we)
		info->assets->valid_cardinals = true;
	return (1);
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
