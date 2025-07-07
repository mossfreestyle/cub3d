/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:33:09 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/07 18:59:15 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_code(t_info *cub, int code)
{
	if (!cub)
		exit(code);
	free_tab(cub->map_info->final_map);
	free_all(cub);
	if (cub->mlx->img)
		mlx_destroy_image(cub->mlx, cub->mlx->img);
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
	{
		mlx_destroy_display(cub->mlx);
		free(cub->mlx);
	}
	exit(code);
}

void	error_exit(t_info *cub, char *msg)
{
    ft_putendl_fd("Error", 2);
    ft_putendl_fd(msg, 2);
    
    if (cub)
    {
        destroy_all(cub);
        free_all(cub);
    }
    
    exit(EXIT_FAILURE);
}

void	exit_failure(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	purge_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

void	error_close_exit(t_info *cub, char *msg)
{
	purge_gnl(cub->map_info->fd);
	close(cub->map_info->fd);
	error_exit(cub, msg);
}
