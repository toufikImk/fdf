/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:53:30 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:56:49 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr(unsigned long long n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}
