/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_us.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:49:09 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/04 11:34:44 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_us(unsigned int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	nb = n;
	if (n < 0)
	{
		n = 4294967295 - nb;
	}
	if (n >= 10)
		count += ft_putnbr_us(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
