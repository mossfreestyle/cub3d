/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:42:28 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/29 17:17:14 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>

int	main(void)
{
	char	i[] = "0";
	int		c;
	size_t	n;
	char	*p;
	char	*pp;

	c = 'e';
	n = sizeof(char) * 50;
	p = ft_memset(i,c, n);
	pp = memset(i, c, n);
	printf("%s\n", p);
	printf("%s\n", pp);
}	

*/