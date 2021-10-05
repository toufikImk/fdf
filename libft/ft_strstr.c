/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:58:07 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:58:07 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (!little[i])
		return ((char *)big);
	else
		while (big[i])
		{
			j = 0;
			while (little[j])
			{
				if (little[j] != big[i + j])
					break ;
				j++;
			}
			if (j == ft_strlen(little))
				return ((char *)big + i);
			i++;
		}
	return (0);
}
