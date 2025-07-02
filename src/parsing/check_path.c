/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:27:19 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/02 14:13:53 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	put_true_to_valid_assets(t_info *info)
{
	if (info->assets->path_no && info->assets->path_so && info->assets->path_we
		&& info->assets->path_ea && info->assets->c_color
		&& info->assets->f_color)
		info->valid_assets = true;
}

static char	*check_valid_path(t_info *info, char *stash)
{
	char	*path;
	int		len;

	len = ft_strlen(stash);
	if (len < 4 || ft_strncmp(stash + len - 4, ".xpm", 4))
		error(info, "Need a valid .xpm file\n", 1);
	stash += 2;
	while (ft_isspace(*stash))
		stash++;
	path = ft_strdup(stash);
	if (!path)
		error(info, "Malloc failed when allocating for path\n", 1);
	return (path);
}

static int	check_path(t_info *info, char *stash)
{
	if (stash[0] == 'N' && stash[1] == 'O')
		info->assets->path_no = check_valid_path(info, stash);
	else if (stash[0] == 'S' && stash[1] == 'O')
		info->assets->path_so = check_valid_path(info, stash);
	else if (stash[0] == 'E' && stash[1] == 'A')
		info->assets->path_ea = check_valid_path(info, stash);
	else if (stash[0] == 'W' && stash[1] == 'E')
		info->assets->path_we = check_valid_path(info, stash);
	else
		return (0);
	return (1);
}

void	check_info(t_info *info, char *stash)
{
	char	**tmp;

	tmp = NULL;
	if (check_path(info, stash))
		return ;
	else if (stash[0] == 'C' && ft_isspace(stash[1]))
	{
		tmp = ft_split(stash, ',');
		if (!tmp)
			error(info, "Split Failed for ceiling value\n", 1);
		add_rgb(info, tmp, 'C');
	}
	else if (stash[0] == 'F' && ft_isspace(stash[1]))
	{
		tmp = ft_split(stash, ',');
		if (!tmp)
			error(info, "Split Failed for floor value\n", 1);
		add_rgb(info, tmp, 'F');
	}
	else
		error(info, "File contains bad data\n", 1);
	if (tmp)
		free_tab(tmp);
	put_true_to_valid_assets(info);
}
