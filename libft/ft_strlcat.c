/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:53:44 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/30 12:50:27 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (siz == 0)
		return (len_src);
	if (!src)
		return (len_dst);
	if (siz <= len_dst)
		return (siz + len_src);
	while ((i + len_dst < siz - 1) && src[i])
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	dst[i + len_dst] = '\0';
	return (len_dst + len_src);
}

/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*src;
	size_t	n;

	src = "bfbffbf";
	char		dest[2]= "55";
	n = 0;
	printf("src: %s dest: %s length: %zu\n", src, dest, ft_strlcat(dest,
			src,n));
	printf("src: %s dest: %s length: %zu\n", src, dest, strlcat(dest, src, n));
}
*/

/*
i +
	if (!src)
		return (i);
		&& i < ft_strlen(dst) + ft_strlen(src)
		*/