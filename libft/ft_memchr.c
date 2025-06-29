/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:14:51 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/30 13:04:00 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (((char *)s)[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char			i[500] = "hello world";
	char			j[500] = "hello world";
	size_t			n;
	unsigned char	*p;
	unsigned char	*pp;

	n = 15;
	p = ft_memchr(i, 'w', n);
	pp = memchr(j, 'w', n);
	printf("%s\n", p);
	printf("%s\n", pp);
	//printf("%p\n", ft_memchr(i, 4, 9));
	//printf("%p\n", memchr(i, 4, 9));
}

*/