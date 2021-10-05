/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:45:46 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:46:16 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long value, int base, char letter)
{
	int		i;
	int		neg;
	char	*res;
	char	c;

	neg = (value < 0) ? 1 : 0;
	value = (value < 0) ? -value : value;
	i = 0;
	while (ft_pow(base, i) - 1 < value)
		i++;
	res = malloc(sizeof(char) * (i + neg));
	c = (letter == 'X') ? 'A' : 'a';
	while ((i--) >= 0)
	{
		res[i + neg] = (value % base) > 9 ? (value % base) - 10 + c :
		(value % base) + '0';
		value /= base;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
