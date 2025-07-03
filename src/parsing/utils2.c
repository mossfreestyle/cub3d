/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:37:20 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/04 00:15:43 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

size_t	ft_strlenlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	check_map_is_last(t_info *info, char **map)
{
	int	i;

	i = 0;
	while (only_white_spaces(map[i]))
		i++;
	while (is_valid(info, map[i]))
		i++;
	while (map[i])
	{
		if (!only_white_spaces(map[i]))
			return (1);
		i++;
	}
	return (0);
}


// int	check_is_closed(t_info *info, char **map)
// {
// 	int	len;

// 	int y, x;
// 	y = -1;
// 	while (map[++y])
// 	{
// 		len = ft_strlen(map[y]);
// 		x = -1;
// 		while (++x < len)
// 		{
// 			if (map[y][x] == '0' || map[x][y] == (char)info->player->view)
// 			{
// 				if (y == 0 || !map[y + 1] || x == 0
// 					|| x == (int)ft_strlen(map[y]) - 1)
// 					return (1);
// 				if (x >= (int)ft_strlen(map[y - 1]) || map[y - 1][x] == ' '
// 					|| x >= (int)ft_strlen(map[y + 1]) || map[y + 1][x] == ' '
// 					|| map[y][x - 1] == ' ' || x + 1 >= (int)ft_strlen(map[y])
// 					|| map[y][x + 1] == ' ')
// 					return (1);
// 			}
// 		}
// 	}
// 	return (0);
// }



// int	check_is_closed(t_info *info, char **map) //a veirf
// {
//     int	len;
//     int y, x;
    
//     y = -1;
//     while (map[++y])
//     {
//         len = ft_strlen(map[y]);
//         x = -1;
//         while (++x < len)
//         {
//             // ✅ Corrige : map[y][x] pour les deux conditions
//             if (map[y][x] == '0' || map[y][x] == (char)info->player->view)
//             {
//                 // Vérification des bords
//                 if (y == 0 || !map[y + 1] || x == 0 || x == len - 1)
//                     return (1);
                
//                 // Vérifications sécurisées des cases adjacentes
//                 if (y > 0 && (x >= (int)ft_strlen(map[y - 1]) || map[y - 1][x] == 'X'))
//                     return (1);
//                 if (map[y + 1] && (x >= (int)ft_strlen(map[y + 1]) || map[y + 1][x] == 'X'))
//                     return (1);
//                 if (x > 0 && map[y][x - 1] == 'X')
//                     return (1);
//                 if (x < len - 1 && map[y][x + 1] == 'X')
//                     return (1);
//             }
//         }
//     }
//     return (0);
// }


// void print_map(char **map)
// {
// 	int i;
	
// 	i = -1;
// 	while(map[++i])
// 		printf("%s\n",map[i]);
// }


int	check_is_closed(t_info *info, char **map)
{
    int	len;
    int y, x;
    
	(void)info;
    if (!map)  // ✅ Vérification de sécurité
        return (1);
    
    y = 0;  // ✅ Commence à 0
    while (map[y])  // ✅ Vérifie AVANT d'utiliser map[y]
    {
        if (!map[y])  // ✅ Double vérification
            break;
            
        len = ft_strlen(map[y]);
        x = 0;  // ✅ Commence à 0
        while (x < len)
        {
            if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' || 
                map[y][x] == 'E' || map[y][x] == 'O')  // ✅ Plus clair que cast
            {
                // Vérification des bords
                if (y == 0 || !map[y + 1] || x == 0 || x == len - 1)
                    return (1);
                
                // Vérifications sécurisées des cases adjacentes
                if (y > 0 && (x >= (int)ft_strlen(map[y - 1]) || map[y - 1][x] == 'X'))
                    return (1);
                if (map[y + 1] && (x >= (int)ft_strlen(map[y + 1]) || map[y + 1][x] == 'X'))
                    return (1);
                if (x > 0 && map[y][x - 1] == 'X')
                    return (1);
                if (x < len - 1 && map[y][x + 1] == 'X')
                    return (1);
            }
            x++;  // ✅ Incrémente à la fin
        }
        y++;  // ✅ Incrémente à la fin
    }
    return (0);
}