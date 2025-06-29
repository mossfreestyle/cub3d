/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:41:15 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/30 18:10:16 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		k = i;
		while (big[k] == little[j] && k < len)
		{
			j++;
			k++;
			if (j == ft_strlen(little))
				return ((char *)&big[i]);
		}
		j = 0;
		i++;
	}
	if (i < len || j != ft_strlen(little))
		return (NULL);
	return ((char *)big);
}

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
if (little[0] == '\0')
		return ((char *)big);
	const char	*str = "abcdefghijklmnopfenrireverrve";
	const char	*str2 = "mno";
	size_t		n;

	n = 20;
	printf("%s\n", ft_strnstr(str, str2, n));
	//printf("%s\n", strnstr(str,str2, n));
}
*/
