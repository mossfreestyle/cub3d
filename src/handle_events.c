/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 23:22:52 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 18:59:49 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_events(t_info *info)
{
	mlx_hook(info->mlx->window, 17, 0, close_window, info);
	mlx_hook(info->mlx->window, KeyPress, KeyPressMask, key_info, info);
}
