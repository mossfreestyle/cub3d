/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:23:11 by rwassim           #+#    #+#             */
/*   Updated: 2025/07/07 18:58:12 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	exit_success(t_info *cub)
{
	exit_code(cub, EXIT_SUCCESS);
	return (0);
}

static int	key_press(int keycode, t_info *cub)
{
	if (keycode == XK_Escape)
		exit_success(cub);
	else if (keycode == XK_w || keycode == XK_W)
		cub->key->key_w = 1;
	else if (keycode == XK_s || keycode == XK_S)
		cub->key->key_s = 1;
	else if (keycode == XK_a || keycode == XK_A)
		cub->key->key_a = 1;
	else if (keycode == XK_d || keycode == XK_D)
		cub->key->key_d = 1;
	else if (keycode == XK_Left)
		cub->key->turn_left = 1;
	else if (keycode == XK_Right)
		cub->key->turn_right = 1;
	else if (keycode == XK_m || keycode == XK_M)
		cub->minimap = !cub->minimap;
	else if (keycode == XK_c || keycode == XK_C)
		cub->controls = !cub->controls;
	else if (keycode == XK_KP_Add && cub->map_scale < MAX_SCALE)
		cub->map_scale++;
	else if (keycode == XK_KP_Subtract && cub->map_scale > MIN_SCALE)
		cub->map_scale--;
	return (0);
}

static int	key_release(int keycode, t_info *cub)
{
	if (keycode == XK_w || keycode == XK_W)
		cub->key->key_w = 0;
	else if (keycode == XK_s || keycode == XK_S)
		cub->key->key_s = 0;
	else if (keycode == XK_a || keycode == XK_A)
		cub->key->key_a = 0;
	else if (keycode == XK_d || keycode == XK_D)
		cub->key->key_d = 0;
	else if (keycode == XK_Left)
		cub->key->turn_left = 0;
	else if (keycode == XK_Right)
		cub->key->turn_right = 0;
	return (0);
}

static int	game_loop(t_info *cub)
{
	if (cub->key->key_w)
		move_forward(cub);
	if (cub->key->key_s)
		move_backward(cub);
	if (cub->key->key_a)
		strafe_left(cub);
	if (cub->key->key_d)
		strafe_right(cub);
	if (cub->key->turn_left)
		rotate(cub->player, -ROT_SPEED);
	if (cub->key->turn_right)
		rotate(cub->player, ROT_SPEED);
	render_frame(cub);
	return (0);
}

void	init_hooks(t_info *cub)
{
	mlx_hook(cub->mlx->window, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx->window, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->mlx->window, 4, 1L << 2, mouse_press, cub);
	mlx_hook(cub->mlx->window, 5, 1L << 3, mouse_release, cub);
	mlx_hook(cub->mlx->window, 6, 1L << 6, mouse_move, cub);
	mlx_hook(cub->mlx->window, 17, 0L, exit_success, cub);
	mlx_loop_hook(cub->mlx, game_loop, cub);
}