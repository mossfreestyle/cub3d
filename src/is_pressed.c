/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pressed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:55:21 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/09 17:24:16 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	is_w(t_info *info, t_player *player)
{
	player->move = m_forward;
	info->key->press_w = True;
}

void	is_s(t_info *info, t_player *player)
{
	player->move = m_backward;
	info->key->press_s = True;
}

void	is_a(t_info *info, t_player *player)
{
	player->move = m_left;
	info->key->press_a = True;
}

void	is_d(t_info *info, t_player *player)
{
	player->move = m_right;
	info->key->press_d = True;
}

void	is_esc(t_info *info)
{
	destroy_all(info);
	free_all(info);
	exit(EXIT_SUCCESS);
}
