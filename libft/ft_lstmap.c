/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 22:34:38 by tkhattar          #+#    #+#             */
/*   Updated: 2021/07/13 22:46:02 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ft_lst;
	t_list	*elem_f;

	if (!lst)
		return (NULL);
	ft_lst = ft_lstnew((*f)(lst->content));
	if (!ft_lst)
		return (NULL);
	tmp = lst->next;
	while (tmp)
	{
		elem_f = ft_lstnew((*f)(tmp->content));
		if (!(elem_f))
		{
			ft_lstclear(&ft_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ft_lst, elem_f);
		tmp = tmp->next;
	}
	return (ft_lst);
}
