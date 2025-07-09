/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:54:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/09 19:48:46 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_key(t_key *key)
{
	key->key_w = 0;
	key->key_s = 0;
	key->key_a = 0;
	key->key_d = 0;
	key->key_down = 0;
	key->turn_left = 0;
	key->turn_right = 0;
	key->x_old = 0;
	key->esc = 0;
	key->press_w = false;
	key->press_s = false;
	key->press_a = false;
	key->press_d = false;
	key->press_turn_left = false;
	key->press_turn_right = false;
}

static void	init_player(t_player *player)
{
	player->view = N;
	player->move = m_forward;
	player->angle = 0;
	player->x = 0;
	player->y = 0;
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
	player->speed = 0.5;
	player->speed_rot = 0.5;
}

static void	init_map(t_map *map_info)
{
	map_info->stash = NULL;
	map_info->final_map = NULL;
	map_info->first_map = NULL;
	map_info->x_spawn = 5;
	map_info->y_spawn = 5;
	map_info->line_max = 0;
	map_info->closed = false;
	map_info->map_ready = false;
	map_info->distance_to_wall = 0;
	map_info->nb_players = 0;
	map_info->x_max = 0;
	map_info->y_max = 0;
	map_info->nb_lines = 0;
}

void	init_other(t_info *info)
{
	info->in_map = false;
	info->valid_assets = false;
	info->map_copied = false;
	info->draw = malloc(sizeof(t_draw));
	if (!info->draw)
		error(info, "malloc tdraw failed", 1);
	ft_bzero(info->draw, sizeof(t_draw));
	init_player(info->player);
	init_map(info->map_info);
	init_key(info->key);
	info->ray = malloc(sizeof(t_ray));
	if (!info->ray)
		error_exit(info, "Ray allocation failed");
	ft_bzero(info->ray, sizeof(t_ray));
}

int	init_all(t_info *info)
{
	info->mlx = malloc(sizeof(t_mlx));
	if (!info->mlx)
		return (1);
	ft_bzero(info->mlx, sizeof(t_mlx));
	info->player = malloc(sizeof(t_player));
	if (!info->player)
		return (1);
	ft_bzero(info->player, sizeof(t_player));
	info->map_info = malloc(sizeof(t_map));
	if (!info->map_info)
		return (1);
	ft_bzero(info->map_info, sizeof(t_map));
	info->key = malloc(sizeof(t_key));
	if (!info->key)
		return (1);
	ft_bzero(info->key, sizeof(t_key));
	info->assets = malloc(sizeof(t_assets));
	if (!info->assets)
		return (1);
	ft_bzero(info->assets, sizeof(t_assets));
	init_other(info);
	if (init_assets(info->assets))
		return (1);
	return (0);
}
