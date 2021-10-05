/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhattar <tkhattar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:18:23 by tkhattar          #+#    #+#             */
/*   Updated: 2021/10/05 11:32:11 by tkhattar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "readutils.h"
#include <stdlib.h>

static void	find_range(t_map *map)
{
	int			min;
	int			max;
	t_point		p;
	int			z;

	min = 2147483647;
	max = -2147483648;
	p.y = 0;
	while (p.y < map->h)
	{
		p.x = 0;
		while (p.x < map->w)
		{
			z = map->coord_arr[p.y * map->w + p.x];
			if (z < min)
				min = z;
			if (z > max)
				max = z;
			p.x++;
		}
		p.y++;
	}
	map->min_z = min;
	map->max_z = max;
	map->rng = max - min;
}

static int	conv_to_arr(t_map *map, t_coords *coords)
{
	int			*coord_arr;
	int			*color_arr;
	t_coords	*coords_head;
	int			i;
	int			success;

	success = 1;
	if (!(map->coord_arr = (int *)malloc(sizeof(int) * map->w * map->h)) || \
		!(map->color_arr = (int *)malloc(sizeof(int) * map->w * map->h)))
		success = 0;
	i = 0;
	coords_head = coords;
	coord_arr = map->coord_arr;
	color_arr = map->color_arr;
	while (coords && success)
	{
		color_arr[i] = (*coords).rgb;
		coord_arr[i++] = (*coords).c;
		coords = coords->next;
	}
	del_list(&coords_head);
	return (success);
}

static int	read_split(char **split, t_map *map, t_coords **coords)
{
	char	**split_h;
	int		success;

	split_h = split;
	success = 1;
	while (*split != NULL && success)
	{
		if (!(push_coord(coords, new_coord(*split))))
			success = 0;
		map->w += 1;
		ft_strdel(&(*split++));
	}
	map->h += 1;
	ft_memdel((void **)&split_h);
	return (success);
}

static int	gnl_cycle(t_map *map, int fd, t_coords **coords)
{
	int			rv;
	int			n;
	char		**split;
	char		*line;
	int			success;

	n = -1;
	success = 1;
	rv = 1;
	while (rv > 0 && success)
	{
		rv = get_next_line(fd, &line);
		if (n == -1)
			n = countwords(line, ' ');
		split = ft_strsplit(line, ' ');
		if (n != countwords(line, ' ') || !(read_split(split, map, coords)))
			success = 0;
		ft_strdel(&line);
	}
	if (rv == -1)
		return (0);
	return (success);
}

t_map	*read_map(int fd)
{
	t_map		*map;
	t_coords	*coords;

	coords = NULL;
	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->w = 0;
	map->h = 0;
	map->cm = 0;
	if (!gnl_cycle(map, fd, &coords))
		return (NULL);
	map->w = map->w / map->h;
	conv_to_arr(map, coords);
	find_range(map);
	return (map);
}
