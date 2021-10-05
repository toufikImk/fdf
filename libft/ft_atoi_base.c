/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:43:38 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:44:29 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ind(char digit, int base)
{
	int			ind;
	const char	*abc = "0123456789abcdef";

	ind = 0;
	while (ind < base && \
		(digit != abc[ind] && digit != ft_toupper(abc[ind])))
		ind++;
	return (ind);
}

int	ft_atoi_base(char *num, int base)
{
	int		res;
	int		len;
	int		i;

	if (base <= 10)
		return (ft_atoi(num));
	len = ft_strlen(num);
	res = 0;
	i = num[0] == '-' ? 1 : 0;
	while (i < len)
	{
		res *= base;
		res += ind(num[i++], base);
	}
	return (num[0] == '-' ? -res : res);
}
