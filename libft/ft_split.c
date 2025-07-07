/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:55:38 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 19:01:53 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int			count_words(const char *s, char sep);
// void		free_tab(char **tab);

// char	*ft_copy_sep(const char *s, char sep)
// {
// 	size_t	i;
// 	char	*dst;

// 	i = 0;
// 	while (s[i] && s[i] != sep)
// 		i++;
// 	dst = malloc(i + 1);
// 	if (!dst)
// 		return (NULL);
// 	dst[i] = '\0';
// 	while (i-- > 0)
// 		dst[i] = s[i];
// 	return (dst);
// }

// char	**ft_split(const char *s, char sep)
// {
// 	char	**result;
// 	size_t	word_index;
// 	size_t	i;

// 	result = malloc(sizeof(char *) * (count_words(s, sep) + 1));
// 	if (!result)
// 		return (NULL);
// 	word_index = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == sep)
// 			i++;
// 		if (!s[i])
// 			break ;
// 		result[word_index] = ft_copy_sep(s + i, sep);
// 		if (!result[word_index])
// 		{
// 			free_tab(result);
// 			return (NULL);
// 		}
// 		i += ft_strlen(result[word_index++]);
// 	}
// 	result[word_index] = NULL;
// 	return (result);
// }

// int	count_words(const char *s, char sep)
// {
// 	int		count;
// 	int		is_word;
// 	size_t	i;

// 	is_word = 0;
// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		while (s[i] == sep)
// 		{
// 			is_word = 0;
// 			i++;
// 		}
// 		if (!s[i])
// 			break ;
// 		if (!is_word)
// 		{
// 			is_word = 1;
// 			count++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }

// void	free_tab(char **tab)
// {
// 	size_t	i;

// 	i = 0;
// 	while (tab && tab[i])
// 		free(tab[i++]);
// 	free(tab);
// }

// // #include <stdio.h>
// // int main (int ac, char **av)
// // {
// //     char **tab;
// //     char sep;
// //     int i = 0;

// //     sep = ' ';
// //     tab = ft_split(av[1], sep);
// //     while(tab[i])
// //         printf("%s\n", tab[i++]);
// //     return (0);
// // }

int	in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_letter(char const *str, char *charset, int *k)
{
	int	i;

	*k = 0;
	i = 0;
	while (str[i] && !in_charset(str[i], charset))
		i++;
	return (i);
}

int	count_words(char const *str, char *charset, int *j, int *i)
{
	int	l;
	int	cnt;

	l = 0;
	*i = 0;
	*j = 0;
	cnt = 0;
	while (str[l])
	{
		if (!in_charset(str[l], charset))
		{
			cnt++;
			while (str[l] && !in_charset(str[l], charset))
				l++;
		}
		else
			l++;
	}
	return (cnt);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i++]);
	}
	free(tab);
}

char	**ft_split(char *str, char *charset)
{
	int i;
	int j;
	int k;
	char **res;

	res = malloc(sizeof(char *) * (count_words(str, charset, &j, &i) + 1));
	if (!res)
		return (free(res), NULL);
	while (str[i])
	{
		if (!in_charset(str[i], (char *)charset))
		{
			res[j] = malloc(sizeof(char) * (count_letter(&str[i],
							(char *)charset, &k) + 1));
			if (!res[j])
				return (free_tab(res), NULL);
			while (str[i] && !in_charset(str[i], (char *)charset))
				res[j][k++] = str[i++];
			res[j++][k] = '\0';
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}