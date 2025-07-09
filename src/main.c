/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:28:43 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/09 17:29:52 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_mlx	*get_wall_texture(t_info *info)
{
	if (info->ray->side == 0)
	{
		if (info->ray->dir_x > 0)
			return (info->assets->ea);
		else
			return (info->assets->we);
	}
	else
	{
		if (info->ray->dir_y > 0)
			return (info->assets->so);
		else
			return (info->assets->no);
	}
}

static void	check_args(int argc, char **argv)
{
	char	*s;
	int		fd;
	char	*filename;

	if (argc != 2)
		exit_failure("Invalid number of arguments");
	filename = ft_strrchr(argv[1], '/');
	if (filename)
		filename++;
	else
		filename = argv[1];
	if (filename[0] == '.')
		exit_failure("Hidden .cub files are not allowed");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		if (fd >= 0)
			close(fd);
		exit_failure("File does not exist or is a directory");
	}
	close(fd);
	s = ft_strrchr(argv[1], '.');
	if (!s || ft_strncmp(s, ".cub", 4) || ft_strlen(s) != 4)
		exit_failure("Invalid file format");
}

int	main(int argc, char **argv)
{
	t_info	cub;

	check_args(argc, argv);
	ft_bzero(&cub, sizeof(t_info));
	if (init_all(&cub))
		exit_failure("Problem during initialization");
	cub.map_scale = MINIMAP_SCALE;
	cub.controls = 1;
	cub.minimap = 1;
	cub.assets->floor_col = -1;
	cub.assets->ceiling_col = -1;
	fill_stash(&cub, argv);
	if (init_mlx(cub.mlx))
		error_exit(&cub, "Unable to initialize MLX");
	init_render_system(&cub);
	init_hooks(&cub);
	start_game_loop(&cub);
	destroy_all(&cub);
	free_all(&cub);
	return (EXIT_SUCCESS);
}
