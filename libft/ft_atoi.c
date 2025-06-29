/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:10:36 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/30 11:06:32 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	i = 0;
	sign = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{	
		if (nptr[i] == '-')
			sign = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	if (sign == 1)
		result *= -1;
	return (result);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("\t\n\r\v\f  469 \n"));
	printf("%d\n", atoi("\t\n\r\v\f  469 \n"));
}

*/