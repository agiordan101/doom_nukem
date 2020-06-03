/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_is_poly_printable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:21:27 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 17:33:29 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static SDL_bool		ed_is_mob_poly(const t_map *map, const t_poly *poly)
{
	const t_mob	*m;

	m = map->mob;
	while (m)
	{
		if (m->poly == poly)
			return (SDL_TRUE);
		m = m->next;
	}
	return (SDL_FALSE);
}

static SDL_bool		ed_is_object_poly(const t_map *map, const t_poly *poly)
{
	const t_object	*obj;
	int				i;
	t_poly			*p;

	obj = map->objects;
	while (obj)
	{
		if (obj->type == BOX || obj->type == DOOR)
		{
			i = 0;
			p = obj->poly;
			while (i < ed_get_object_poly_count(obj) && p)
			{
				if (p == poly)
					return (SDL_TRUE);
				p = p->next;
				i++;
			}
		}
		else if (obj->poly == poly)
			return (SDL_TRUE);
		obj = obj->next;
	}
	return (SDL_FALSE);
}

SDL_bool			ed_is_poly_point(const t_poly *poly)
{
	if (poly)
	{
		if (poly->dots[0].x == poly->dots[1].x
			&& poly->dots[0].y == poly->dots[1].y &&
			poly->dots[1].x == poly->dots[2].x
			&& poly->dots[1].y == poly->dots[2].y &&
			poly->dots[2].x == poly->dots[3].x
			&& poly->dots[2].y == poly->dots[3].y)
			return (SDL_TRUE);
	}
	return (SDL_FALSE);
}

SDL_bool			ed_is_real_poly(const t_map *map, const t_poly *poly)
{
	return (!(ed_is_mob_poly(map, poly) || ed_is_object_poly(map, poly)));
}

SDL_bool			ed_is_poly_printable(const t_map *map, const t_poly *poly)
{
	int	inter;
	int	min;
	int	max;

	if (!ed_is_real_poly(map, poly))
		return (0);
	inter = ft_abs(map->editor.max_pos_z - map->editor.min_pos_z);
	min = map->editor.min_pos_z + inter * (map->editor.z_min / 100.f);
	max = map->editor.min_pos_z + inter * (map->editor.z_max / 100.f);
	if ((poly->dots[0].z >= min && poly->dots[0].z <= max) ||
			(poly->dots[1].z >= min && poly->dots[1].z <= max) ||
			(poly->dots[2].z >= min && poly->dots[2].z <= max) ||
			(poly->dots[3].z >= min && poly->dots[3].z <= max))
		return (1);
	else
		return (0);
}
