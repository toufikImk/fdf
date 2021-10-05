/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:16:05 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/04 22:16:07 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ifi(int cond, int c1, int c2)
{
	if (cond)
		return (c1);
	else
		return (c2);
}

float	assign_if_float(int cond, float c1, float c2)
{
	if (cond)
		return (c1);
	else
		return (c2);
}

double	ifd(int cond, t_point p, t_point p0, t_point p1)
{
	if (cond)
		return (find_perc(p.x, p1.x, p0.x));
	else
		return (find_perc(p.y, p1.y, p0.y));
}
