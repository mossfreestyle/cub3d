/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:19:35 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/27 12:25:21 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>
#include <strings.h>

int	main(void)
{
	int	i;

	i = {0,1,4,5};
	printf("%p\n", ft_bzero(i, 14));
	//printf("%p\n", bzero(i, 14));
}
 */