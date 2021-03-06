/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdelim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:45:29 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:46:16 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdelim(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
		c == '\v' || c == '\f' || c == '\r');
}
