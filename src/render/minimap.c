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

static void	draw_minimap_pixel(t_info *info, int x, int y, int color)
{
	int	i;
	int	j;
	int	scale;

	scale = info->map_scale;
	i = 0;
	while (i < scale)
	{
		j = 0;
		while (j < scale)
		{
			put_pixel(info->mlx, x * scale + i, y * scale + j, color);
			j++;
		}
		i++;
	}
}

static int	get_minimap_color(char c)
{
	if (c == '1')
		return (WHITE);
	else if (c == '0')
		return (BLACK);
	else if (c == 'X')
		return (DARK_GREY);
	else
		return (GREY);
}

static void	draw_player_on_minimap(t_info *info)
{
	int	player_x;
	int	player_y;

	player_x = (int)(info->player->x * info->map_scale);
	player_y = (int)(info->player->y * info->map_scale);
	
	draw_minimap_pixel(info, player_x / info->map_scale, 
		player_y / info->map_scale, RED);
}

void	draw_minimap(t_info *info)
{
    int	x;
    int	y;
    int	color;

    if (!info->minimap || !info->map_info || !info->map_info->final_map)
        return ;
    
    y = 0;
    while (y < info->map_info->nb_lines && y * info->map_scale < HEIGHT_DISPLAY / 4)
    {
        x = 0;
        while (x < info->map_info->line_max && x * info->map_scale < WIDTH_DISPLAY / 4)
        {
            if (x < (int)ft_strlen(info->map_info->final_map[y]) &&
                info->map_info->final_map[y][x])
            {
                color = get_minimap_color(info->map_info->final_map[y][x]);
                draw_minimap_pixel(info, x, y, color);
            }
            x++;
        }
        y++;
    }
    draw_player_on_minimap(info);
}
