/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mglikenf <mglikenf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:57:56 by mglikenf          #+#    #+#             */
/*   Updated: 2025/05/01 19:46:43 by mglikenf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_unified.h"

static char *check_syntax(char *trimmed, int n)
{
	int i = 0;

	if (n < 0 || n > 255)
		return ("RGB value must be in range 0-255");
	while (trimmed[i] == ' ' || trimmed[i] == '\t')
		i++;
	if (trimmed[i] == '+' || trimmed[i] == '-')
		i++;
	if (!ft_isdigit(trimmed[i]))
		return ("RGB format is invalid");
	while (ft_isdigit(trimmed[i]))
		i++;
	while (trimmed[i] == ' ' || trimmed[i] == '\t')
		i++;
	if (trimmed[i] != '\0')
		return ("RGB format is invalid");
	return (NULL);
}

static int parse_component(char *trimmed, t_game *cub, char **subs, char *line)
{
	char	*msg;
	int		n;

	n = ft_atoi(trimmed);
	msg = check_syntax(trimmed, n);
	if (msg != NULL)
	{
		free(line);
		free(trimmed);
		free_tab(subs);
		error_close_exit(cub, msg);
	}
	free(trimmed);
	return (n);
}

static int	convert_rgb(t_game *cub, char **subs, char *line)
{
	int		r;
	int		g;
	int		b;

	r = parse_component(ft_strtrim(subs[0], " \t"), cub, subs, line);
	g = parse_component(ft_strtrim(subs[1], " \t"), cub, subs, line);
	b = parse_component(ft_strtrim(subs[2], " \t"), cub, subs, line);
	return ((r << 16) | (g << 8) | b);
}

int	parse_rgb_line(t_game *cub, char *line, int *dst)
{
	char	*tmp;
	int		rgb;
	char	**subs;

	if (*dst != -1)
	{
		free(line);
		error_close_exit(cub, "Duplicate configuration for color");
	}
	tmp = line;
	++line;
	subs = ft_split(line, ',');
	if (!subs || !subs[0] || !subs[1] || !subs[2] || subs[3])
	{
		free_tab(subs);
		free(tmp);
		error_close_exit(cub, "RGB: need exactly three numbers");
	}
	rgb = convert_rgb(cub, subs, tmp);
	free_tab(subs);
	return (rgb);
}
