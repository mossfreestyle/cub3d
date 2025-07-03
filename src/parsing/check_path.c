/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:27:19 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/03 21:35:17 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_double_comma(t_info *info, char *stash)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (stash[++i])
	{
		if (stash[i] == ',')
			count++;
	}
	if (count != 2)
		error(info, "Wrong number of comma for rgb values", 1);
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
	int		i;

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

// void	check_info(t_info *info, char *stash)
// {
// 	char	**tmp;

// 	tmp = ft_split(stash, " ");
// 	if (!tmp)
// 	{
// 		free_tab(tmp);
// 		error(info, "failed malloc", 1);
// 	}
// 	printf("%s\n", stash);
// 	if (!info->assets->valid_cardinals && check_path(info, tmp))
// 		return (free_tab(tmp));
// 	free_tab(tmp);
// 	printf("%s\n", info->assets->path_no);
// 	printf("%s\n", info->assets->path_so);
// 	printf("%s\n", info->assets->path_ea);
// 	printf("%s\n", info->assets->path_we);
// 	for (int i = 0; i < 3;i++)
// 		printf("%d\n", info->assets->ceiling_color[i]);
// 	for (int j = 0; j < 3;j++)
// 		printf("%d\n", info->assets->ceiling_color[j]);
// 	check_double_comma(info, stash);
// 	tmp = ft_split(stash, " ,");
// 	if (!tmp)
// 		error(info, "Split Failed for floor value", 1);
// 	add_rgb(info, tmp, tmp[0][0]);
// 	free_tab(tmp);
// 	put_true_to_valid_assets(info);
// 	printf("%d\n", info->valid_assets);
// }

static int	is_texture_line(char **stash)
{
	if (!stash[0])
		return (0);
	return (!ft_strncmp("NO", stash[0], 2) || !ft_strncmp("SO", stash[0], 2)
		|| !ft_strncmp("EA", stash[0], 2) || !ft_strncmp("WE", stash[0], 2));
}

// void	check_info(t_info *info, char *stash)
// {
// 	char	**tmp;

// 	tmp = ft_split(stash, " ");
// 	if (!tmp)
// 		error(info, "failed malloc", 1);
// 	printf("Processing: %s\n", stash);
// 	// Traite les textures (NO, SO, EA, WE)
// 	if (!info->assets->valid_cardinals && is_texture_line(tmp))
// 	{
// 		check_path(info, tmp);
// 		free_tab(tmp);
// 		return ;
// 	}
// 	if (tmp[0][0] == 'C' || tmp[0][0] == 'F')
// 	{
// 		free_tab(tmp);
// 		check_double_comma(info, stash);
// 		tmp = ft_split(stash, " ,");
// 		if (!tmp)
// 			error(info, "Split Failed for RGB values", 1);
// 		add_rgb(info, tmp, tmp[0][0]);
// 		free_tab(tmp);
// 		if (!info->assets->c_color ||!info->assets->f_color)
// 			return ;
// 	}
// 	else
// 		return ;
// 	put_true_to_valid_assets(info);
// 	free_tab(tmp);
// 	// Debug final
// 	printf("save\n");
// 	if (info->valid_assets)
// 	{
// 		printf("NO: %s\n", info->assets->path_no);
// 		printf("SO: %s\n", info->assets->path_so);
// 		printf("EA: %s\n", info->assets->path_ea);
// 		printf("WE: %s\n", info->assets->path_we);
// 		printf("Ceiling colors: ");
// 		for (int i = 0; i < 3; i++)
// 			printf("%d ", info->assets->ceiling_color[i]);
// 		printf("\nFloor colors: ");
// 		for (int j = 0; j < 3; j++)
// 			printf("%d ", info->assets->floor_color[j]);
// 		printf("\n%d ", info->assets->f_color);
// 		printf("%d ", info->assets->c_color);
		// printf("\nValid assets: %d\n", info->valid_assets);
	// }
// }

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
    
    // Traite les couleurs (C, F)
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
