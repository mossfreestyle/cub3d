/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:54:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/30 21:54:14 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_key(t_key *key)
{
	key->key_w = 119;
	key->key_s = 115;
	key->key_a = 97;
	key->key_d = 100;
	key->esc = 65307;
	key->press_w = False;
	key->press_s = False;
	key->press_a = False;
	key->press_d = False;
	key->press_turn_left = False;
	key->press_turn_right = False;
}

static void	init_player(t_info *info, t_player *player)
{
	player->angle = 0;
	player->x = info->map_info->x_spawn;
	player->y = info->map_info->y_spawn;
	player->speed = 0.5;
	player->speed_rot = 0.5;
}

static int	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (1);
	mlx->window = mlx_new_window(mlx->mlx, WIDTH_DISPLAY, HEIGHT_DISPLAY,
			"Cub3D");
	if (!mlx->window)
		return (1);
	return (0);
}

static void	init_assets(t_assets *assets)
{
	assets->path_no = NULL;
	assets->path_so = NULL;
	assets->path_ea = NULL;
	assets->path_we = NULL;
	assets->no = NULL;
	assets->so = NULL;
	assets->ea = NULL;
	assets->we = NULL;
}

static void	init_map(t_map *map_info)
{
	map_info->stash = NULL;
	map_info->map = NULL;
	map_info->x_spawn = 5;
	map_info->y_spawn = 5;
}

int	init_all(t_info *info)
{
	info->mlx = malloc(sizeof(t_mlx));
	if (!info->mlx)
		return (1);
	info->player = malloc(sizeof(t_player));
	if (!info->player)
		return (1);
	info->map_info = malloc(sizeof(t_map));
	if (!info->map_info)
		return (1);
	info->key = malloc(sizeof(t_key));
	if (!info->key)
		return (1);
	info->assets = malloc(sizeof(t_assets));
	if (!info->assets)
		return (1);
	info->radius_buffer = malloc(1);
	if (!info->radius_buffer)
		return (1);
	if (init_mlx(info->mlx))
		return (1);
	init_player(info, info->player);
	init_map(info->map_info);
	init_key(info->key);
	init_assets(info->assets);
	return (0);
}
