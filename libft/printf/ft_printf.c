/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:26:34 by mfernand          #+#    #+#             */
/*   Updated: 2025/05/05 15:27:38 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags(va_list args, char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_us(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		sum;
	size_t	i;

	sum = 0;
	i = 0;
	va_start(ap, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			sum += check_flags(ap, s[++i]);
		else
			sum += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (sum);
}

// int main(void)
// {
//     int     x = 42;
//     char    c = 'A';
//     char    *str = "Hello, world!";
//     void    *ptr = &x;
//     int     sint = -123;
//     unsigned int uint = 123;
//     unsigned int hexmin = 0xabcdef;
//     unsigned int hexmax = 0xABCDEF;
//     int ft_ret = ft_printf("\nft_printf:\n"
//         "Char: %c\n"
//         "String: %s\n"
//         "Pointer: %p\n"
//         "Signed int: %d\n"
//         "Signed int (i): %i\n"
//         "Unsigned int: %u\n"
//         "Hexadecimal (min): %x\n"
//       	"Hexadecimal (maj): %X\n"
//         "Percent: %%\n",
//        c ,str, ptr, sint, sint , uint, hexmin, hexmax);
//     int real_ret = printf("\nfx_printf:\n"
//         "Char: %c\n"
//         "String: %s\n"
//         "Pointer: %p\n"
//         "Signed int: %d\n"
//         "Signed int (i): %i\n"
//         "Unsigned int: %u\n"
//         "Hexadecimal (min): %x\n"
//         "Hexadecimal (maj): %X\n"
//         "Percent: %%\n",
//         c, str, ptr, sint, sint, uint, hexmin, hexmax);

//     printf("\nReturn values:\n");
//     printf("ft_printf returned: %d\n", ft_ret);
//     printf("printf returned: %d\n", real_ret);

//     return (0);
// }