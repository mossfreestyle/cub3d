/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:17:05 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/29 00:43:47 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_info *info;
	if (ac != 2)
		return (check_arg("Only need a map", 1));
	info = malloc(sizeof(t_info));
	if (!info)
		return (1);
	init_info(info);
	(void)av;
	handle_events(info);
	return (0);
}