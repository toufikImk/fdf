/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:47:10 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:51:11 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list *elem, void *(*f)(void *, void *, size_t))
{
	void	*result;

	if (!elem || !f)
		return (NULL);
	result = elem->content;
	while (elem->next)
	{
		if (elem->content && elem->next->content)
		{
			result = f(result, elem->next->content,
				elem->next->content_size);
		}
		elem = elem->next;
	}
	return (result);
}
