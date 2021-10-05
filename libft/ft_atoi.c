/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:31:59 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:13:11 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		return (0);
	n = str[i] - '0';
	i++;
	while (ft_isdigit(str[i]) == 1)
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
