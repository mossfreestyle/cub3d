/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:39:00 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/30 16:01:14 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s1;
	char	*tab;

	i = 0;
	if (!s)
		return (NULL);
	len_s1 = ft_strlen(s);
	if (start >= len_s1)
		len = 0;
	if (len > len_s1 - start)
		len = len_s1 - start;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = ((char *)s)[start];
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	const char		*str = "";
	unsigned int	c;
	size_t			n;
	char			*tab;

	c = 0;
	n = 0;
	tab = ft_substr(str, c, n);
	printf("%s\n", tab);
	// printf("%s\n", strnstr(str,str2, n));
}
*/