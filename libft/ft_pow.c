/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:51:07 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:52:03 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_pow(long long nb, int pow)
{
	long long	res;

	res = 1;
	if (pow == 0)
		return (1);
	while (pow > 0)
	{
		res *= nb;
		pow--;
	}
	return (res);
}
