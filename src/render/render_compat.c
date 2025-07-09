/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_compat.c                                    :+:      :+:    :+:   */
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

void	init_key_codes(t_info *info)
{
	info->key->esc = XK_Escape;
	info->key->key_w = XK_w;
	info->key->key_s = XK_s;
	info->key->key_a = XK_a;
	info->key->key_d = XK_d;
	info->key->turn_left = XK_Left;
	info->key->turn_right = XK_Right;
}

int	move_player(t_info *info)
{
	handle_movement(info);
	render_frame(info);
	return (0);
}

void	start_rendering(t_info *info)
{
	init_render_system(info);
	init_hooks(info);
	mlx_loop_hook(info->mlx->mlx, game_loop, info);
}
