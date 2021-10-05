/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:35:37 by tkhattar          #+#    #+#             */
/*   Updated: 2021/07/13 22:47:40 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_c;
	const unsigned char	*src_c;

	if (!dst && !src)
		return (dst);
	i = 0;
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		i++;
	}
	return (dst_c);
}
