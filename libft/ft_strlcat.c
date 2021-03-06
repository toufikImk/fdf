/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:37:28 by tkhattar          #+#    #+#             */
/*   Updated: 2021/07/13 21:54:06 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = ft_strlen(dst);
	if (dstsize < dstlen)
		return (ft_strlen(src) + dstsize);
	while (src[i] && (dstlen + i + 1) < dstsize)
	{
		dst[dstlen + i] = ((char *)src)[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (ft_strlen(src) + dstlen);
}
