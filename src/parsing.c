/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:36:36 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/30 23:01:35 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_stash(t_info *info, char **av)
{
	int	i;

	i = -1;
	info->map_file = open(av[1], O_RDONLY);
	if (info->map_file < 0)
		error(info, "Cant open the file\n", 1);
	while ((info->map_info->stash[++i] = get_next_line(info->map_file)) != NULL)
	{
		if (info->map_info->stash[i][0] == '\n')
			continue ;
		check_info(info, info->map_info->stash[i]);
	}
}

void	check_info(t_info *info, char *stash)
{
	char	**tmp;

	tmp = NULL;
	if (stash[0] == 'N' && stash[1] == 'O')
		info->assets->path_no = check_valid_path(info, stash);
	else if (stash[0] == 'S' && stash[1] == 'O')
		info->assets->path_so = check_valid_path(info, stash);
	else if (stash[0] == 'E' && stash[1] == 'A')
		info->assets->path_ea = check_valid_path(info, stash);
	else if (stash[0] == 'W' && stash[1] == 'E')
		info->assets->path_we = check_valid_path(info, stash);
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
	if (tmp)
		free_tab(tmp);
}

char	*check_valid_path(t_info *info, char *stash)
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
	while (ft_isspace(*str))
		str++;
	if (c == 'C')
	{
		info->assets->ceiling_color[0] = ft_atoi(str);
		info->assets->ceiling_color[1] = ft_atoi(tmp[1]);
		info->assets->ceiling_color[2] = ft_atoi(tmp[2]);
	}
	else if (c == 'F')
	{
		info->assets->floor_color[0] = ft_atoi(str);
		info->assets->floor_color[1] = ft_atoi(tmp[1]);
		info->assets->floor_color[2] = ft_atoi(tmp[2]);
	}
	if (!check_valid_rgb(info, c))
    {
        free_tab(tmp);
		error(info, "Wrong character to add rgb values\n", 1);
    }
	return ;
}

int	check_valid_rgb(t_info *info, char c)
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
