/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:25:05 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/27 12:59:25 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if (size != 0 && nmemb > 4294967295 + size)
		return (NULL);
	if (size == 0 || nmemb == 0)
	{
		tab = malloc(0);
		if (!tab)
			return (NULL);
		return (tab);
	}
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size * nmemb);
	return (tab);
}

/*
#include <stdio.h>

int	main(void)
{
	size_t	nb;
	size_t	len;
	int		*p;
	int		*pp;

	nb = 0;
	len = sizeof(int);
	p = ft_calloc(nb, len);
	pp = calloc(nb, len);
	printf("%d\n", *(p + 0));
	printf("%d\n", *(pp + 0));
	printf("%d\n", *(p + 1));
	printf("%d\n", *(pp + 1));
	printf("%d\n", *(p + 2));
	printf("%d\n", * (pp + 2));
	printf ("--------------\n");
	printf("%p\n", p + 0);
	printf("%p\n", pp + 0);
	printf("%p\n", p + 1);
	printf("%p\n", pp + 1);
	printf("%p\n", p + 2);
	printf("%p\n", pp + 2);
}

*/