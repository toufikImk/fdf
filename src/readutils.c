/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:33:24 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/03 04:08:41 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "readutils.h"
#include <stdlib.h>

t_coords	*new_coord(char *str)
{
	t_coords	*new;

	new = (t_coords *)malloc(sizeof(t_coords));
	if (!new)
		return (NULL);
	new->c = ft_atoi(str);
	while (*str && *str != 'x')
		str++;
	new->rgb = (*str) ? ft_atoi_base(str++, 16) : -1;
	new->next = NULL;
	return (new);
}

void	del_list(t_coords **list)
{
	t_coords	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		ft_memdel((void **)&tmp);
	}
}

int	push_coord(t_coords **head, t_coords *new)
{
	if (!new)
	{
		del_list(head);
		return (0);
	}
	new->next = *head;
	*head = new;
	return (1);
}

int	countwords(char *line, char delim)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] && line[i] == delim)
			i++;
		if (line[i] && line[i] != delim)
		{
			while (line[i] && line[i] != delim)
				i++;
			count++;
		}
	}
	return (count);
}
