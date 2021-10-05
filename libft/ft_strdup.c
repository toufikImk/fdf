/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:37:06 by tkhattar          #+#    #+#             */
/*   Updated: 2021/07/13 21:52:37 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	lenplus;

	lenplus = ft_strlen(s1) + 1;
	s2 = malloc(lenplus * sizeof(char));
	if (!(s2))
		return (NULL);
	ft_memcpy(s2, s1, lenplus);
	return (s2);
}
