/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:21:13 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/09 17:32:19 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_info *info)
{
	destroy_all(info);
	free_all(info);
	exit(EXIT_SUCCESS);
}

int	check_arg(char *msg, int exit_code)
{
	ft_putstr_fd(ERROR_MSG, 2);
	ft_putendl_fd(msg, 2);
	return (exit_code);
}

int	error(t_info *info, char *msg, int exit_code)
{
	destroy_all(info);
	free_all(info);
	ft_putstr_fd(ERROR_MSG, 2);
	ft_putendl_fd(msg, 2);
	exit(exit_code);
}

int	move(t_info *info)
{
	t_key	*key_pressed;

	key_pressed = info->key;
	if (key_pressed->press_w)
		info->player->y -= 1;
	else if (key_pressed->press_s)
		info->player->y += 1;
	else if (key_pressed->press_a)
		info->player->x -= 1;
	else if (key_pressed->press_d)
		info->player->x += 1;
	return (0);
}

bool	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}
