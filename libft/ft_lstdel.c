/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:46:53 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 13:51:11 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		tmp = *alst;
		if (tmp->content)
			del(tmp->content, tmp->content_size);
		*alst = (*alst)->next;
		free(tmp);
		tmp = NULL;
	}
}
