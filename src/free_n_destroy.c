/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:05:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/01 01:49:50 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_all(t_info *info)
{
	if (info->assets->path_no)
		free(info->assets->path_no);
	if (info->assets->path_so)
		free(info->assets->path_so);
	if (info->assets->path_ea)
		free(info->assets->path_ea);
	if (info->assets->path_we)
		free(info->assets->path_we);
	if (info->map_info->stash)
		free_tab(info->map_info->stash);
	if (info->map_info->final_map)
		free_tab(info->map_info->final_map);
	if (info->map_info->first_map)
		free_tab(info->map_info->first_map);
	if (info->radius_buffer)
		free(info->radius_buffer);
	if (info->key)
		free(info->key);
	if (info->assets)
		free(info->assets);
	if (info->mlx)
		free(info->mlx);
	if (info->player)
		free(info->player);
	if (info)
		free(info);
}

void	destroy_all(t_info *info)
{
	if (info->assets->no)
		mlx_destroy_image(info->mlx->mlx, info->assets->no);
	if (info->assets->so)
		mlx_destroy_image(info->mlx->mlx, info->assets->so);
	if (info->assets->ea)
		mlx_destroy_image(info->mlx->mlx, info->assets->ea);
	if (info->assets->we)
		mlx_destroy_image(info->mlx->mlx, info->assets->we);
	if (info->mlx->window)
		mlx_destroy_window(info->mlx->mlx, info->mlx->window);
	if (info)
		mlx_destroy_display(info->mlx->mlx);
}
