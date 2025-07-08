/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:00:00 by rwassim          #+#    #+#             */
/*   Updated: 2025/07/07 19:00:00 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	draw_minimap_pixel(t_info *info, int x, int y, int color)
// {
// 	int	i;
// 	int	j;
// 	int	scale;

// 	scale = info->map_scale;
// 	i = 0;
// 	while (i < scale)
// 	{
// 		j = 0;
// 		while (j < scale)
// 		{
// 			put_pixel(info->mlx, x * scale + i, y * scale + j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static int	get_minimap_color(char c)
// {
// 	if (c == '1')
// 		return (WHITE);
// 	else if (c == '0')
// 		return (BLACK);
// 	else if (c == 'X')
// 		return (DARK_GREY);
// 	else
// 		return (GREY);
// }

// static void	draw_player_on_minimap(t_info *info)
// {
// 	int	player_x;
// 	int	player_y;

// 	player_x = (int)(info->player->x * info->map_scale);
// 	player_y = (int)(info->player->y * info->map_scale);
	
// 	draw_minimap_pixel(info, player_x / info->map_scale, 
// 		player_y / info->map_scale, RED);
// }

// void	draw_minimap(t_info *info)
// {
//     int	x;
//     int	y;
//     int	color;

//     if (!info->minimap || !info->map_info || !info->map_info->final_map)
//         return ;
    
//     y = 0;
//     while (y < info->map_info->nb_lines && y * info->map_scale < HEIGHT_DISPLAY / 4)
//     {
//         x = 0;
//         while (x < info->map_info->line_max && x * info->map_scale < WIDTH_DISPLAY / 4)
//         {
//             if (x < (int)ft_strlen(info->map_info->final_map[y]) &&
//                 info->map_info->final_map[y][x])
//             {
//                 color = get_minimap_color(info->map_info->final_map[y][x]);
//                 draw_minimap_pixel(info, x, y, color);
//             }
//             x++;
//         }
//         y++;
//     }
//     draw_player_on_minimap(info);
// }

static int	cell_color(t_info *cub, int x, int y)
{
	char	tile;

	tile = cub->map_info->final_map[y][x];
	if (tile == '1')
		return (DARK_GREY);
	if (tile == '0')
		return (GREY);
	return (-1);
}

static void	draw_cell(t_info *cub, int x, int y, int scale)
{
	int	color;
	int	i;
	int	j;

	color = cell_color(cub, x, y);
	if (color == -1)
		return ;
	i = 0;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			put_pixel(cub->mlx, x * scale + i, y * scale + j, color);
			j++;
		}
		i++;
	}
}

static void	dir_line(t_info *cub, int px, int py)
{
	int	i;
	int	dx;
	int	dy;

	i = 0;
	while (i < DIR_LEN)
	{
		dx = (int)(cub->player->dir_x * i);
		dy = (int)(cub->player->dir_y * i);
		put_pixel(cub->mlx, px + dx, py + dy, RED);
		i++;
	}
}

static void	draw_player(t_info *cub, int scale)
{
	int	px;
	int	py;
	int	i;
	int	j;

	px = cub->player->x * scale;
	py = cub->player->y * scale;
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			put_pixel(cub->mlx, px + i, py + j, RED);
			j++;
		}
		i++;
	}
	dir_line(cub, px, py);
}

void	draw_minimap(t_info *cub)
{
	int	x;
	int	y;

	y = 0;
	while (y < cub->map_info->nb_lines)
	{
		x = 0;
		while (x < cub->map_info->line_max)
		{
			draw_cell(cub, x, y, cub->map_scale);
			x++;
		}
		y++;
	}
	draw_player(cub, cub->map_scale);
}
