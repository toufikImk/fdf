/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:54:55 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 11:54:58 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

typedef struct s_eulers
{
	float				sin;
	float				cos;
}						t_eulers;

t_eulers				get_eulers(float angle);

#endif