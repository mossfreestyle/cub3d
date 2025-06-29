/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:45:21 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/29 17:39:40 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	return (dest);
}

/*
|| dest >= src + n
#include <stdio.h>

int	main(void)
{
	char	i[] = "Hello World";
	char	j[15];
	size_t	n;
	char	*p;
	char	*pp;

	n = sizeof(char) * 5;
	p = ft_memmove(j, i, n);
	pp = memmove(j, i, n);
	printf("%s\n", p);
	printf("%s\n", pp);
}

*/
