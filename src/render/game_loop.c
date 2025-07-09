/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
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

void	handle_movement(t_info *info)
{
	if (info->key->press_w)
		move_forward(info);
	if (info->key->press_s)
		move_backward(info);
	if (info->key->press_a)
		strafe_left(info);
	if (info->key->press_d)
		strafe_right(info);
	if (info->key->press_turn_left)
		rotate(info->player, -ROT_SPEED);
	if (info->key->press_turn_right)
		rotate(info->player, ROT_SPEED);
}

int	game_loop(t_info *info)
{
	handle_movement(info);
	render_frame(info);
	return (0);
}

void	start_game_loop(t_info *info)
{
	mlx_loop_hook(info->mlx->mlx, game_loop, info);
	mlx_loop(info->mlx->mlx);
}
