/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:47:33 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:51:11 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char *)malloc(size);
	if (mem)
	{
		while (size > 0)
			mem[size--] = 0;
		mem[0] = 0;
	}
	return (mem);
}
