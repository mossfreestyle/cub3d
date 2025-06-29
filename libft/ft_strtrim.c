/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:34:46 by mfernand          #+#    #+#             */
/*   Updated: 2025/04/30 18:06:40 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		len;
	int		start;
	int		end;
	char	*strmalloc;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	end = len - 1;
	while (start < len && is_set(s1[start], set) == 1)
		start++;
	if (start == len)
		return (ft_strdup(""));
	while (end > start && is_set(s1[end], set) == 1)
		end--;
	strmalloc = ft_substr(s1, start, end - start + 1);
	return (strmalloc);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*str = "  \t \t \n   \n\n\n\t";
	char		*c;
	char		*tab;

	c = " ";
	tab = ft_strtrim(str, c);
	printf("%s", tab);
	// printf("%s\n", strnstr(str,str2, n));  squa16
}
*/