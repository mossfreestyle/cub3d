/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:06:32 by mglikenf          #+#    #+#             */
/*   Updated: 2025/05/01 17:12:58 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_unified.h"

static int	append_players(char *line)
{
	char	*set;
	int		i;
	int		count;

	set = "NEWS";
	i = 0;
	count = 0;
	while (line[i])
	{
		if (ft_strchr(set, line[i]))
			count++;
		i++;
	}
	return (count);
}

static int	line_has_invalid_chars(char *line)
{
	char	*valid_set;
	int		i;

	valid_set = "10 NEWS";
	i = 0;
	while (line[i])
	{
		if (!ft_strchr(valid_set, line[i]))
			return (1);
		i++;
	}
	return (0);
}

void	validate_map_lines(t_game *cub, t_map_node *head)
{
	t_map_node	*current;
	int			num_of_players;

	if (!head)
		error_exit(cub, "Missing configuration elements");
	current = head;
	num_of_players = 0;
	while (current)
	{
		if (line_has_invalid_chars(current->line))
			error_exit(cub, "Invalid character in map");
		num_of_players += append_players(current->line);
		current = current->next;
	}
	if (num_of_players != 1)
		error_exit(cub, "Number of players must be exactly one");
}

static void	check_neighbors(int y, int x, t_game *cub)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if (y == 0 || y >= cub->map.height - 1 || x == 0 || x >= cub->map.width - 1)
	{
		if (ft_strchr("NSWE", cub->map.grid[y][x]))
			error_exit(cub, "Map is invalid: player is located on the edge of the map");
		else if (cub->map.grid[y][x] == '0')
			error_exit(cub, "Map is invalid: walkable tile on the edge");
		
	}
	up = cub->map.grid[y - 1][x];
	down = cub->map.grid[y + 1][x];
	left = cub->map.grid[y][x - 1];
	right = cub->map.grid[y][x + 1];
	if (up == ' ' || down == ' ' || left == ' ' || right == ' ')
		error_exit(cub, "Map is invalid: a hole in the wall");
}

void	validate_tiles(t_game *cub)
{
	int		y;
	int		x;
	char	tile;

	y = 0;
	while (y < cub->map.height)
	{
		x = 0;
		while (x < cub->map.width)
		{
			tile = cub->map.grid[y][x];
			if (ft_strchr("NSWE0", tile))
				check_neighbors(y, x, cub);
			x++;
		}
		y++;
	}
}
