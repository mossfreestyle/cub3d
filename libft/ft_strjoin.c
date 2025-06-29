/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:03:59 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/27 16:15:25 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	s = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		s[i] = ((char *)s1)[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		s[i + j] = ((char *)s2)[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

/*
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*src;
	char	*dest;

	src = "vdvd";
	dest = "";
	printf("src: %s\ndest: %s\ns: %s\n", src, dest, ft_strjoin(dest, src));
	//printf("src: %s dest: %s length: %zu\n", src, dest, strlcat(dest, src,
			n));
}
	*/