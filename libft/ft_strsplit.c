/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:57:52 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:57:52 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			j++;
		}
	}
	return (j);
}

static int		str_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char		**free_mem(char **splits, int j)
{
	while (j >= 0)
	{
		free(splits[j]);
		splits[j--] = NULL;
	}
	free(splits);
	splits = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**splits;
	int		j;
	int		k;

	if (!s || !(splits = (char **)malloc(sizeof(char *)
		* (count_words(s, c) + 1))))
		return (0);
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			k = str_len(s, c);
			if (!(splits[j] = ft_strndup(s, k * sizeof(char))))
				return (free_mem(splits, j - 1));
			s += k;
			j++;
		}
	}
	splits[j] = NULL;
	return (splits);
}
