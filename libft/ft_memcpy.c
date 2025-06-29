/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:26:44 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/30 17:13:49 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	i[] = "zyxwvutsrqponmlkjihgfedcba";
	char	j[14];
	size_t	n;
	char	*p;
	char	*pp;

	n = sizeof(char) * 10;
	p = ft_memcpy(j, i, n);
	//pp = memcpy(j, i, n);
	printf("%s\n", p);
	//printf("%s\n", pp);
}

*/