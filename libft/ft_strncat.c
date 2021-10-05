/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:56:19 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:59:23 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*p;
	size_t	i;

	p = s1;
	i = 0;
	while (*s1)
		s1++;
	while (*s2 && i < n)
	{
		*(s1++) = *(s2++);
		i++;
	}
	*s1 = '\0';
	return (p);
}
