/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:51:48 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/09 17:55:24 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_assets *assets)
{
	assets->path_no = NULL;
	assets->path_so = NULL;
	assets->path_ea = NULL;
	assets->path_we = NULL;
	assets->c_color = false;
	assets->f_color = false;
	assets->floor_col = 0;
	assets->ceiling_col = 0;
	assets->valid_cardinals = false;
}

int	init_assets(t_assets *assets)
{
	init_data(assets);
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
	return (0);
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

void	init_player_position(t_info *info)
{
	info->player->x = (double)info->map_info->x_spawn + 0.5;
	info->player->y = (double)info->map_info->y_spawn + 0.5;
	info->player->speed = MOVE_SPEED;
	info->player->speed_rot = ROT_SPEED;
}

void	rotate(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle) - player->plane_y
		* sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}
