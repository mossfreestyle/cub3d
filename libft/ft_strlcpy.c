/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:34:05 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/29 17:47:00 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	if (siz == 0)
		return (ft_strlen(src));
	while (i < siz - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//if (siz > ft_strlen(src))
	//	siz = ft_strlen(src);

int	main(void)
{
	const char	*src = "";
	char		dest[14];
	size_t		n;

	n = 5;
	printf("src: %s dest: %s length: %zu\n",src, dest, ft_strlcpy(dest, src,
			n));
	printf("src: %s dest: %s length: %zu\n",src, dest, strlcpy(dest, src, n));
	// printf("%zu\n", strlcat(dest, src, n));
}
*/