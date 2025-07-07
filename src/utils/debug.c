/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 23:50:55 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/07 16:42:12 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_unified.h"

void	print_image_data(const t_image *image)
{
	printf("Image Data:\n");
	printf("  img: %p\n", image->img);
	printf("  addr: %p\n", image->addr);
	printf("  bits_per_pixel: %d\n", image->bpp);
	printf("  line_length: %d\n", image->line_len);
	printf("  endian: %d\n", image->endian);
	printf("\n");
}

void	print_player_data(const t_player *player)
{
	printf("Player Data:\n");
	printf("  pos_x: %.2f\n", player->pos_x);
	printf("  pos_y: %.2f\n", player->pos_y);
	printf("  dir_x: %.2f\n", player->dir_x);
	printf("  dir_y: %.2f\n", player->dir_y);
	printf("  plane_x: %.2f\n", player->plane_x);
	printf("  plane_y: %.2f\n", player->plane_y);
	printf("\n");
}

void	print_map_data(const t_map *map)
{
	int	i;

	printf("Map Data:\n");
	printf("  width: %d\n", map->width);
	printf("  height: %d\n", map->height);
	printf("  grid:\n");
	if (map->grid)
	{
		for (i = 0; i < map->height; i++)
		{
			printf("    |%s|\n", map->grid[i]);
		}
	}
	else
		printf("    (null)\n");
	printf("  north_texture: %s\n",
		map->no_texture ? map->no_texture : "(null)");
	printf("  south_texture: %s\n",
		map->so_texture ? map->so_texture : "(null)");
	printf("  west_texture: %s\n",
		map->we_texture ? map->we_texture : "(null)");
	printf("  east_texture: %s\n",
		map->ea_texture ? map->ea_texture : "(null)");
	printf("  floor_rgb: %d\n", map->floor_rgb);
	printf("  ceiling_rgb: %d\n", map->ceiling_rgb);
	printf("\n");
}

void	print_data(const t_game *cub)
{
	//printf("Game Data:\n");
	//printf("  mlx: %p\n", cub->mlx);
	//printf("  win: %p\n\n", cub->win);
	//print_image_data(&cub->image);
	//print_player_data(&cub->player);
	print_map_data(&cub->map);
}

void    print_temp_list(t_map_node *map_lines)
{
    t_map_node  *current = map_lines;

	printf("----- TEMPORARY LINKED LIST -----\n");
    while (current)
    {
        printf("|%s|\n", current->line);
        current = current->next;
    }
	printf("----- TEMPORARY LINKED LIST -----\n");
}
