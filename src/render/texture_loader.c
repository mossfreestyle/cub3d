/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/07/07 19:00:00 by rwassim          #+#    #+#             */
/*   Updated: 2025/07/07 19:00:00 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_file_exists(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static void	load_single_texture(t_info *info, t_mlx *texture, char *path)
{
	if (!check_file_exists(path))
		error(info, "Texture file not found", 1);
	texture->mlx = info->mlx->mlx;
	texture->img = mlx_xpm_file_to_image(info->mlx->mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
		error(info, "Failed to load texture", 1);
	texture->adr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (!texture->adr)
		error(info, "Failed to get texture address", 1);
}

void	load_textures(t_info *info)
{
	if (!info->assets->path_no || !info->assets->path_so
		|| !info->assets->path_ea || !info->assets->path_we)
		error(info, "Missing texture paths", 1);
	load_single_texture(info, info->assets->no, info->assets->path_no);
	load_single_texture(info, info->assets->so, info->assets->path_so);
	load_single_texture(info, info->assets->ea, info->assets->path_ea);
	load_single_texture(info, info->assets->we, info->assets->path_we);
}

void	free_textures(t_info *info)
{
	if (!info || !info->assets)
		return ;
	if (info->assets->no && info->assets->no->img)
		mlx_destroy_image(info->mlx->mlx, info->assets->no->img);
	if (info->assets->so && info->assets->so->img)
		mlx_destroy_image(info->mlx->mlx, info->assets->so->img);
	if (info->assets->ea && info->assets->ea->img)
		mlx_destroy_image(info->mlx->mlx, info->assets->ea->img);
	if (info->assets->we && info->assets->we->img)
		mlx_destroy_image(info->mlx->mlx, info->assets->we->img);
}
