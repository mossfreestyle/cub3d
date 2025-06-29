/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:42:38 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/19 11:19:26 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb(int n);
static char	*int_min(int n);

char	*ft_itoa(int n)
{
	char	*tab;
	int		i;

	if (n == -2147483648)
		return (int_min(n));
	if (n == 0)
		return (int_min(n));
	i = ft_nb(n);
	tab = malloc(sizeof(char) * i + 1);
	if (!tab)
		return (NULL);
	tab[i] = '\0';
	if (n < 0)
	{
		tab[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		tab[--i] = (n % 10) + 48;
		n /= 10;
	}
	return (tab);
}

static char	*int_min(int n)
{
	char	*tab;

	if (n == -2147483648)
	{
		(void)n;
		tab = malloc(12);
		if (!tab)
			return (NULL);
		ft_strlcpy(tab, "-2147483648", 12);
		return (tab);
	}
	else if (n == 0)
	{
		tab = malloc(2);
		if (!tab)
			return (NULL);
		tab[0] = '0';
		tab[1] = '\0';
		return (tab);
	}
	return (NULL);
}

static int	ft_nb(int n)
{
	int	u;

	u = 0;
	if (n <= 0)
		u++;
	while (n != 0)
	{
		u++;
		n /= 10;
	}
	return (u);
}

/*
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	// int p = itoa(n);
	printf("%s\n", ft_itoa(-2147483648));
	//	printf("%s\n", p);
}
*/