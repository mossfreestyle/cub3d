/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:26:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/04 02:22:22 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_stash(t_info *info, char **av)
{
	int		i;
	int		j;
	char *str;

	i = -1;
	j = 0;
	info->map_file = open(av[1], O_RDONLY);
	if (info->map_file < 0)
		error(info, "Cant open the file", 1);
	str = recup_gnl(info->map_file);
	if (!str)
		error(info, "error recup gnl", 1);
	info->map_info->stash = ft_split(str, "\n");
	free(str);
	i = -1;
	while (info->map_info->stash[++i] != NULL)
	{
		if (info->in_map)
		{
			if (!info->map_info->first_map)
			{
				info->map_info->first_map = malloc(sizeof(char *) * (get_nb_lines(info->map_info->stash + i) + 1));
				if (!info->map_info->first_map)
					error(info, "probelem malloc", 1);
			}
			info->map_info->first_map[j++] = ft_strdup(info->map_info->stash[i]);
			if (!info->map_info->first_map[j - 1])
				error(info, "Problem during allocation when reading the map",
					1);
		}
		if (!ft_strncmp(info->map_info->stash[i], "\n", 1))
			continue ;
		if (!info->valid_assets)
		{
			check_info(info, info->map_info->stash[i]);
			if (info->valid_assets)
				info->in_map = true;
			continue ;
		}
		info->in_map = true;
	}
	close(info->map_file);
	// printf("NO=%s\n", info->assets->path_no);
	// printf("SO=%s\n", info->assets->path_so);
	// printf("EA=%s\n", info->assets->path_ea);
	// printf("WE=%s\n", info->assets->path_we);
	// for (int i = 0; i < 3; i++)
	// 	printf("C[%d]=%d\n", i, info->assets->ceiling_color[i]);
	// for (int j = 0; j < 3; j++)
	// 	printf("F[%d]=%d\n", j, info->assets->floor_color[j]);
	// printf("VALID=%d\n\n", info->valid_assets);
	info->map_info->first_map[j] = NULL;
	print_map(info->map_info->first_map);
	if (check_map_is_last(info, info->map_info->first_map))
		error(info, "Map format isnt good", 1);
	// parse_map(info);
	// info->map_info->final_map = add_tmp(info, tmp);
	// permet de choisir le bout de map ou se trouve le player
	// free_tab(tmp);
	set_up_final_map(info);
	printf("\n\n===================================\n\n");
	print_map(info->map_info->final_map);
	// check_final_map_is_valid();
	// setup struct genre indice de spawn, x max, y max, etc ...
}


// char	*ft_strjoin_to_line_max(char *src, int limit)
// {
// 	int		i;
// 	char	*res;

// 	i = -1;
// 	res = malloc(sizeof(char) * (limit + 1));
// 	if (!res)
// 		return (NULL);
// 	ft_strlcpy(res, src, limit + 1);
// 	i = ft_strlen(res);
// 	while (i < limit)
// 		res[i++] = 'X';
// 	res[i] = '\0';
// 	return (res);
// }

char	*ft_strjoin_to_line_max(char *src, int limit)
{
    char	*res;
    int		i;

    res = malloc(sizeof(char) * (limit + 1));
    if (!res)
        return (NULL);
    i = 0;
    while (src[i] && i < limit)
    {
        res[i] = src[i];
        i++;
    }
    while (i < limit)
        res[i++] = 'X';
    res[i] = '\0';
    return (res);
}