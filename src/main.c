/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:17:05 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 19:00:25 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	print_all(t_info *info);

// int	main(int ac, char **av)
// {
// 	t_info	*info;
// 	int		len;

// 	if (ac != 2)
// 		return (check_arg("Only need a map.cub", 1));
// 	len = ft_strlen(av[1]);
// 	if (len < 4 || ft_strncmp(av[1] + len - 4, ".cub", 4))
// 		return (check_arg("Only need a map.cub", 1));
// 	info = malloc(sizeof(t_info));
// 	if (!info)
// 		return (1);
// 	if (init_all(info))
// 		return (error(info, "Problem during the initialisation", 1));
// 	fill_stash(info, av);
// 	if (init_mlx(info->mlx))
// 		return (error(info, "Problem during the initialisation", 1));
// 	// print_all(info);
// 	handle_events(info);
// 	mlx_loop(info->mlx->mlx);
// 	destroy_all(info);
// 	free_all(info);
// 	return (0);
// }

// static void	print_all(t_info *info)
// {
// 	printf("NO=%s\n", info->assets->path_no);
// 	printf("SO=%s\n", info->assets->path_so);
// 	printf("EA=%s\n", info->assets->path_ea);
// 	printf("WE=%s\n", info->assets->path_we);
// 	for (int i = 0; i < 3; i++)
// 		printf("C[%d]=%d\n", i, info->assets->ceiling_color[i]);
// 	for (int j = 0; j < 3; j++)
// 		printf("F[%d]=%d\n", j, info->assets->floor_color[j]);
// 	printf("VALID=%d\n\n", info->valid_assets);
// 		printf("PLAYER_VIEW = ");
//     if (info->player->view == N)
//         printf("N (North)\n");
//     else if (info->player->view == S)
//         printf("S (South)\n");
//     else if (info->player->view == E)
//         printf("E (East)\n");
//     else if (info->player->view == W)
//         printf("W (West)\n");
//     else
//         printf("UNKNOWN\n");
//     printf("SPAWN_POS = (%d, %d)\n", info->map_info->x_spawn, info->map_info->y_spawn);
// 	print_map(info->map_info->first_map);
// 	printf("\n\n===================================\n\n");
// 	print_map(info->map_info->final_map);
// }

/////////////////////////////////////////////////////////////////////////

// static void	convert_colors(t_info *cub)
// {
//     if (cub->assets->c_color)
//     {
//         cub->assets->ceiling_col = (cub->assets->ceiling_color[0] << 16) |
//                                     (cub->assets->ceiling_color[1] << 8) |
//                                     cub->assets->ceiling_color[2];
//     }
//     if (cub->assets->f_color)
//     {
//         cub->assets->floor_col = (cub->assets->floor_color[0] << 16) |
//                                  (cub->assets->floor_color[1] << 8) |
//                                  cub->assets->floor_color[2];
//     }
// }

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

// static void	init_window(t_info *cub)
// {
//     if (init_mlx(cub->mlx))
//         error_exit(cub, "Unable to initialize MLX");
//     if (!cub->assets->path_no || !cub->assets->path_so || 
//         !cub->assets->path_ea || !cub->assets->path_we)
//         error_exit(cub, "Missing texture paths");      
//     load_textures(cub); 
//     cub->mlx->img = mlx_new_image(cub->mlx->mlx, WIDTH_DISPLAY, HEIGHT_DISPLAY);
//     if (!cub->mlx->img)
//         error_exit(cub, "Unable to create image");    
//     cub->mlx->adr = mlx_get_data_addr(cub->mlx->img, &cub->mlx->bpp,
//             &cub->mlx->size_line, &cub->mlx->endian);
//     if (!cub->mlx->adr)
//         error_exit(cub, "Unable to get image data address");
// }

// static void	get_player_position(t_info *cub)
// {
//     int	i;
//     int	j;

//     i = 0;
//     while (i < cub->map_info->nb_lines)
//     {
//         j = 0;
//         while (j < cub->map_info->line_max && cub->map_info->final_map[i][j])
//         {
//             if (ft_strchr("NSWE", cub->map_info->final_map[i][j]))
//             {
//                 cub->player->x = j + 0.5;
//                 cub->player->y = i + 0.5;
//                 set_player_direction(cub, cub->map_info->final_map[i][j]);
//                 cub->map_info->final_map[i][j] = '0';
//                 return ;
//             }
//             j++;
//         }
//         i++;
//     }
// }

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
