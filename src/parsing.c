/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:36:36 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/01 11:59:18 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_stash(t_info *info, char **av)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	j = 0;
	info->map_file = open(av[1], O_RDONLY);
	if (info->map_file < 0)
		error(info, "Cant open the file\n", 1);
	while ((info->map_info->stash[++i] = get_next_line(info->map_file)) != NULL)
	{
		if (info->in_map)
			info->map_info->first_map[j++] = ft_strdup(info->map_info->stash[i]);
		else if (info->map_info->stash[i][0] == '\n')
			continue ;
		else if (!info->valid_assets)
			check_info(info, info->map_info->stash[i]);
		info->in_map = true;
	}
	tmp = parse_map(info);
	info->map_info->final_map = add_tmp(info, tmp); // permet de choisir le bout de map ou se trouve le player
	free_tab(tmp);
	// check_final_map_is_valid();
	// setup struct genre indice de spawn, x max, y max, etc ...
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
	if (tmp)
		free_tab(tmp);
	if (info->assets->path_no && info->assets->path_so && info->assets->path_we
		&& info->assets->path_ea && info->assets->c_color
		&& info->assets->f_color)
		info->valid_assets = true;
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
	put_color(info, tmp, str, c);
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

int	check_path(t_info *info, char *stash)
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
char	**parse_map(t_info *info)
{
	int		i;
	t_map	*map;
	char	**tab;
	int		j;

	i = -1;
	j = 0;
	map = info->map_info;
	map->line_max = find_longuest_line(map->first_map);
	map->nb_lines = get_nb_lines(map->first_map);
	map->nb_players = get_nb_players(info, map->first_map);
	if (map->nb_players != 1)
		error(info, "Wrong number of players\n", 1);
	tab = malloc(sizeof(char *) * (map->nb_lines + 1));
	if (!tab)
		error(info, "Error when during the allocation of the map\n", 1);
	while (++i < map->nb_lines)
	{
		if (only_white_spaces(map->first_map[i])
			|| map->first_map[i][0] == '\n')
			continue ;
		if (!is_valid(info, map->first_map[i]))
			error(info, "Invalid character in map\n", 1);
		tab[j] = ft_strjoin_to_line_max(map->first_map[i], map->line_max);
		if (!tab[j++])
		{
			free_tab(tab);
			error(info, "Error of allocation when add empty char the map\n", 1);
		}
	}
	tab[j] = NULL;
	return (tab);
}

int	find_longuest_line(char **map)
{
	int	i;
	int	max_line;

	i = -1;
	max_line = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > max_line)
			max_line = ft_strlen(map[i]);
	}
	return (max_line);
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

	i = -1;
	if (!str)
		return (1);
	while (str[++i])
	{
		if (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i] != '\n'
			&& str[i])
			continue ;
		return (0);
	}
	return (1);
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
					|| map[i][j] == 'O'))
			{
				count++;
				if (count == 1)
					c = map[i][j];
			}
		}
	}
	if (count == 1)
		info->player->view = c;
	return (count);
}
int	is_valid(t_info *info, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '\n'
			|| str[i] == info->player->view)
			continue ;
		else
			return (0);
	}
	return (1);
}
char	*ft_strjoin_to_line_max(char *src, int limit)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = -1;
	j = 0;
	res = malloc(sizeof(char) * (limit + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, limit + 1);
	i = ft_strlen(res);
	while (i < limit)
		res[i++] = '1';
	res[i] = '\0';
	return (res);
}

char	**add_tmp(t_info *info, char **tmp)
{
	int		i;
	int		first;
	int		last;
	char	**res;

	i = -1;
	while (tmp[i] && only_white_spaces(tmp[i]))
		i++;
	if (tmp[i])
		first = i;
	while (tmp[i] && !only_white_spaces(tmp[i]))
		i++;
	if (tmp[i])
		last = i;
	res = malloc(sizeof(char *) * (last - first + 2));
	if (!res)
	{
		free_tab(tmp);
		error(info, "Problem during allocation to crop the map\n", 1);
	}
	i = first;
	while (i <= last)
	{
		res[i - first] = ft_strdup(tmp[i]);
		if (!res)
		{
			free_tab(res);
			free_tab(tmp);
			error(info, "Problem when copy the good part of map\n", 1);
		}
		i++;
	}
	res[last - first + 1] = NULL;
	return (res);
}
