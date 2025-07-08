/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_or_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 00:09:14 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/09 00:17:08 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_full_whitespaces(char **map, size_t i, size_t k)
{
	while (map[i][k] && ft_isspace(map[i][k]))
		k++;
	if (!map[i][k])
		return ('1');
	return (0);
}

int	is_space_enclosed(char **map, int i, int j, char **visited)
{
	if (i < 0 || j < 0 || i >= (int)ft_strlenlen(map)
		|| j >= (int)ft_strlen(map[i]))
		return (0);
	if (visited[i][j])
		return (1);
	visited[i][j] = 1;
	if (map[i][j] == '1' || is_player_char(map[i][j]) || map[i][j] == '0')
		return (1);
	if (ft_isspace(map[i][j]))
	{
		return (is_space_enclosed(map, i - 1, j, visited)
			&& is_space_enclosed(map, i + 1, j, visited)
			&& is_space_enclosed(map, i, j - 1, visited)
			&& is_space_enclosed(map, i, j + 1, visited));
	}
	return (1);
}

char	**create_visited_map(t_info *info, char **map)
{
	char	**visited;
	size_t	i;
	size_t	j;

	(void)info;
	visited = malloc(sizeof(char *) * (ft_strlenlen(map) + 1));
	if (!visited)
		return (NULL);
	i = 0;
	while (map[i])
	{
		visited[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (!visited[i])
			return (NULL);
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			visited[i][j] = 0;
			j++;
		}
		visited[i][j] = '\0';
		i++;
	}
	visited[i] = NULL;
	return (visited);
}

void	free_visited_map(char **visited)
{
	size_t	i;

	if (!visited)
		return ;
	i = 0;
	while (visited[i])
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	v_or_x(t_info *info, char **map, size_t i, size_t j)
{
	char	**visited;
	int		result;

	if (i == 0 || j == 0 || i == ft_strlenlen(map) - 1 || j == ft_strlen(map[i])
		- 1)
		return ('X');
	if (is_full_whitespaces(map, i, j))
		return ('X');
	visited = create_visited_map(info, map);
	if (!visited)
		return ('X');
	result = is_space_enclosed(map, (int)i, (int)j, visited);
	free_visited_map(visited);
	if (result)
		return ('V');
	else
		return ('X');
}
