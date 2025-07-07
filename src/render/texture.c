/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:03:33 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/07 18:59:11 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_tex_y(int y, int line_h, int tex_h)
{
	int		start;
	double	ratio;
	int		tex_y;

	start = (HEIGHT_DISPLAY - line_h) / 2;
	ratio = (double)(y - start) / line_h;
	tex_y = (int)(ratio * tex_h);
	tex_y = clamp_int(tex_y, 0, tex_h - 1);
	return (tex_y);
}

int	get_tex_x(t_ray *ray, t_mlx *wall, t_player *player)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = player->y + ray->wall_dist * ray->dir_y;
	else
		wall_x = player->x + ray->wall_dist * ray->dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * wall->width);
	if (ray->side == 0 && ray->dir_x < 0)
		tex_x = wall->width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		tex_x = wall->width - tex_x - 1;
	tex_x = clamp_int(tex_x, 0, wall->width - 1);
	return (tex_x);
}

void	load_texture(t_info *cub, t_mlx *tex, char *path)
{
    tex->img = mlx_xpm_file_to_image(cub->mlx->mlx, path, &tex->width, &tex->height);
    //printf("Loading texture: %s\n", path);
    if (!tex->img)
        error_exit(cub, "Texture load failed");
    if (tex->width > MAX_TEX || tex->height > MAX_TEX)
        error_exit(cub, "Texture too large (max 800x800)");
    tex->adr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->size_line,
            &tex->endian);
    if (!tex->adr)
        error_exit(cub, "Get texture addr failed");
}

void	load_textures(t_info *cub)
{
	load_texture(cub, cub->assets->no, cub->assets->path_no);
	load_texture(cub, cub->assets->so, cub->assets->path_so);
	load_texture(cub, cub->assets->we, cub->assets->path_we);
	load_texture(cub, cub->assets->ea, cub->assets->path_ea);
}
