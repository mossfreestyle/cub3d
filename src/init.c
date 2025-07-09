/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:54:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/09 17:31:08 by rwassim          ###   ########.fr       */
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

int	init_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->window = NULL;
	mlx->img = NULL;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (1);
	mlx->window = mlx_new_window(mlx->mlx, WIDTH_DISPLAY, HEIGHT_DISPLAY,
			"Cub3D");
	if (!mlx->window)
		return (1);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH_DISPLAY, HEIGHT_DISPLAY);
	if (!mlx->img)
		return (1);
	mlx->adr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line,
			&mlx->endian);
	if (!mlx->adr)
		return (1);
	return (0);
}

static int	init_assets(t_assets *assets)
{
	assets->path_no = NULL;
	assets->path_so = NULL;
	assets->path_ea = NULL;
	assets->path_we = NULL;
	assets->no = malloc(sizeof(t_mlx));
	assets->so = malloc(sizeof(t_mlx));
	assets->ea = malloc(sizeof(t_mlx));
	assets->we = malloc(sizeof(t_mlx));
	if (!assets->no || !assets->so || !assets->ea || !assets->we)
	{
		if (assets->no)
			free(assets->no);
		if (assets->so)
			free(assets->so);
		if (assets->ea)
			free(assets->ea);
		if (assets->we)
			free(assets->we);
		return (1);
	}
	ft_bzero(assets->no, sizeof(t_mlx));
	ft_bzero(assets->so, sizeof(t_mlx));
	ft_bzero(assets->ea, sizeof(t_mlx));
	ft_bzero(assets->we, sizeof(t_mlx));
	assets->c_color = false;
	assets->f_color = false;
	assets->floor_col = 0;
	assets->ceiling_col = 0;
	assets->valid_cardinals = false;
	return (0);
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
	info->radius_buffer = malloc(1);
	if (!info->radius_buffer)
		return (1);
	info->in_map = false;
	info->valid_assets = false;
	info->map_copied = false;
	init_player(info->player);
	init_map(info->map_info);
	init_key(info->key);
	if (init_assets(info->assets))
		return (1);
	return (0);
}
