/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:34:23 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/04 02:18:11 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_nb_lines(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		continue ;
	return (i);
}

int	only_white_spaces(char *str)
{
    int	i;

    if (!str)
        return (1);
    i = -1;
    while (str[++i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return (0);
    }
    return (1);
}

int	get_nb_players(t_info *info, char **map)
{
	int		i;
	int		j;
	int		count;
	char	c;

	c = 0;
	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S'
					|| map[i][j] == 'W'))
			{
				count++;
				if (count == 1)
				{
					c = map[i][j];
					info->map_info->x_spawn = j;
					info->map_info->y_spawn = i;
				}
			}
		}
	}
	if (count == 1)
	{
		if (c == 'N')
			info->player->view = N;
		else if (c == 'S')
			info->player->view = S;
		else if (c == 'E')
			info->player->view = E;
		else if (c == 'W')
			info->player->view = W;
	}
	return (count);
}

int	find_longuest_line(char **map)
{
	int		i;
	size_t	max_line;

	i = -1;
	max_line = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > max_line)
			max_line = ft_strlen(map[i]);
	}
	return (max_line);
}

int	is_valid(t_info *info, char *str)
{
    int	i;

    if (!str)
        return (0);
    (void)info;
    i = -1;
    while (str[++i])
    {
        if (str[i] == '0' || str[i] == '1' || str[i] == '\n' || str[i] == ' '
            || str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
            continue;
        else
            return (0);
    }
    return (1);
}


char	*recup_gnl(int fd)
{
	char	*str;
	char	*tmp;
	int		i;

	str = NULL;
	if (fd == -1)
		return (NULL);
	while (1)
	{
		i = -1;
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		while (tmp[++i])
			if (!ft_isprint(tmp[i]) && tmp[i] != '\n' && tmp[i] != '\0')
				return (free(str), free(tmp), get_next_line(-1), NULL);
		str = ft_strjoin(str, tmp);
		if (!str)
			return (NULL);
	}
	close(fd);
	return (str);
}

// char	*recup_gnl(int fd) //new version
// {
//     char	*str;
//     char	*tmp;
//     char	*new_str;
//     int		i;

//     str = NULL;
//     if (fd == -1)
//         return (NULL);
//     while (1)
//     {
//         tmp = get_next_line(fd);
//         if (!tmp)
//             break ;
        
//         i = -1;
//         while (tmp[++i])
//         {
//             if (!ft_isprint(tmp[i]) && tmp[i] != '\n' && tmp[i] != '\0')
//             {
//                 free(str);
//                 free(tmp);
//                 get_next_line(-1);
//                 close(fd);
//                 return (NULL);
//             }
//         }
        
//         new_str = ft_strjoin(str, tmp);
//         free(tmp);  // ✅ Libère tmp
//         if (!new_str)
//         {
//             free(str);  // ✅ Libère str
//             close(fd);
//             return (NULL);
//         }
//         free(str);  // ✅ Libère l'ancien str
//         str = new_str;
//     }
//     close(fd);
//     return (str);
// }
