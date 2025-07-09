/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:05:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/09 19:36:07 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_assets(t_info *info)
{
	if (info->assets)
	{
		if (info->assets->path_no)
			free(info->assets->path_no);
		if (info->assets->path_so)
			free(info->assets->path_so);
		if (info->assets->path_ea)
			free(info->assets->path_ea);
		if (info->assets->path_we)
			free(info->assets->path_we);
		if (info->assets->no)
			free(info->assets->no);
		if (info->assets->so)
			free(info->assets->so);
		if (info->assets->ea)
			free(info->assets->ea);
		if (info->assets->we)
			free(info->assets->we);
		free(info->assets);
		if (info->draw)
			free(info->draw);
	}
}

void	free_all(t_info *info)
{
	if (!info)
		return ;
	if (info->map_file > 0)
		close(info->map_file);
	free_assets(info);
	if (info->map_info)
	{
		if (info->map_info->stash)
			free_tab(info->map_info->stash);
		if (info->map_info->final_map)
			free_tab(info->map_info->final_map);
		if (info->map_info->first_map)
			free_tab(info->map_info->first_map);
		free(info->map_info);
	}
	if (info->key)
		free(info->key);
	if (info->player)
		free(info->player);
	if (info->ray)
		free(info->ray);
	if (info->mlx)
		free(info->mlx);
}

void	destroy_all(t_info *info)
{
	if (!info || !info->mlx || !info->mlx->mlx)
		return ;
	if (info->assets)
	{
		if (info->assets->no && info->assets->no->img)
			mlx_destroy_image(info->mlx->mlx, info->assets->no->img);
		if (info->assets->so && info->assets->so->img)
			mlx_destroy_image(info->mlx->mlx, info->assets->so->img);
		if (info->assets->ea && info->assets->ea->img)
			mlx_destroy_image(info->mlx->mlx, info->assets->ea->img);
		if (info->assets->we && info->assets->we->img)
			mlx_destroy_image(info->mlx->mlx, info->assets->we->img);
	}
	if (info->mlx->img)
		mlx_destroy_image(info->mlx->mlx, info->mlx->img);
	if (info->mlx->window)
		mlx_destroy_window(info->mlx->mlx, info->mlx->window);
	if (info->mlx->mlx)
	{
		mlx_destroy_display(info->mlx->mlx);
		free(info->mlx->mlx);
		info->mlx->mlx = NULL;
	}
}
