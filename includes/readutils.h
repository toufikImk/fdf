/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readutils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:54:32 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 11:54:43 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READUTILS_H
# define READUTILS_H

typedef struct s_coords
{
	int					c;
	int					rgb;
	struct s_coords		*next;
}						t_coords;

t_coords		*new_coord(char *str);
void			del_list(t_coords **list);
int				push_coord(t_coords **head, t_coords *new);
int				countwords(char *line, char delim);

#endif
