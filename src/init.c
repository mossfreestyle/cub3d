/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:54:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/28 23:45:08 by mfernand         ###   ########.fr       */
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
}
void	init_info(t_info *info)
{
	info->mlx = malloc(sizeof(t_mlx));
	if (!info->mlx)
		return ;
	info->player = malloc(sizeof(t_player));
	if (!info->player)
		return ;
	info->map_info = malloc(sizeof(t_map));
	if (!info->map_info)
		return ;
	info->key = malloc(sizeof(t_key));
	if (!info->key)
		return ;
	info->assets = malloc(sizeof(t_assets));
	if (!info->assets)
		return ;
	// init_mlx();
	init_player(info, info->player);
	// init_map();
	init_key(info->key);
	// init_assets();
}


// void	init_info(t_info *info)
// {
//     info->mlx = malloc(sizeof(t_mlx));
//     if (!info->mlx)
//         return ;
//     info->player = malloc(sizeof(t_player));
//     if (!info->player)
//         return ;
//     info->map_info = malloc(sizeof(t_map));
//     if (!info->map_info)
//         return ;
//     info->key = malloc(sizeof(t_key));
//     if (!info->key)
//         return ;
//     info->assets = malloc(sizeof(t_assets));
//     if (!info->assets)
//         return ;
//     // init_mlx();
//     init_player(info, info->player);
//     // init_map();
//     init_key(info->key);
//     // init_assets();
// }