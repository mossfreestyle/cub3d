/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:01:04 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/30 13:04:57 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			j = i;
			while (s[i])
			{
				if (s[i] == (char)c)
					j = i;
				i++;
			}
			return ((char *)&s[j]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	const char	*str = "";

	printf("%s\n", ft_strrchr(str, 'w'));
	printf("%s\n", strrchr(str, 'w'));
}

*/