/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:58:29 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:58:29 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!(substr = ft_strnew(len)) || !s)
		return (0);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
