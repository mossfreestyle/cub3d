/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:40:13 by mglikenf          #+#    #+#             */
/*   Updated: 2025/04/28 14:38:50 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_unified.h"

void	check_map_size(t_game *cub, int w, int h)
{
	if (w > MAX_MAP || h > MAX_MAP)
		error_exit(cub, "Map too big (max 70x70)");
}

void	calculate_grid_dimensions(t_game *cub)
{
	t_map_node	*current;
	int			max_width;
	int			height;

	current = cub->map.temp_list;
	max_width = 0;
	height = 0;
	while (current && !line_is_empty(current->line))
	{
		height++;
		if ((int)ft_strlen(current->line) > max_width)
			max_width = ft_strlen(current->line);
		current = current->next;
	}
	check_map_size(cub, max_width, height);
	cub->map.height = height;
	cub->map.width = max_width;
}

void	fill_grid(t_game *cub)
{
	t_map_node	*current;
	int			i;
	int			line_len;

	i = 0;
	current = cub->map.temp_list;
	while (i < cub->map.height && current)
	{
		cub->map.grid[i] = malloc((cub->map.width + 1));
		if (!cub->map.grid[i])
			error_exit(cub, "Malloc failed");
		line_len = ft_strlen(current->line);
		ft_memset(cub->map.grid[i], ' ', cub->map.width);
		ft_memcpy(cub->map.grid[i], current->line, line_len);
		cub->map.grid[i][cub->map.width] = '\0';
		current = current->next;
		i++;
	}
}

void	save_map_to_grid(t_game *cub)
{
	calculate_grid_dimensions(cub);
	cub->map.grid = malloc(sizeof(char *) * (cub->map.height + 1));
	if (!cub->map.grid)
		error_exit(cub, "Malloc failed");
	fill_grid(cub);
	cub->map.grid[cub->map.height] = NULL;
}
