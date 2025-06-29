/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:22:52 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/29 00:40:44 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_events(t_info *info)
{
	mlx_hook(info->mlx->window, 17, 0, close_window, info);
	mlx_hook(info->mlx->window, KeyPress, KeyPressMask, key_info, info);
}