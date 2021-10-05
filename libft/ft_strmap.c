/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:55:55 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:56:49 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!new)
		return (0);
	while (*s)
		*new++ = f(*s++);
	*new = '\0';
	return (new - s_len);
}
