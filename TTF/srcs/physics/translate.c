/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiordan <agiordan@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:24:03 by agiordan          #+#    #+#             */
/*   Updated: 2020/03/06 21:46:20 by agiordan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			translate_all_poly(t_poly *poly, t_fdot_3d dpos)
{
	while (poly)
	{
		if (poly->object && poly->object->type == BOX &&\
			poly->object->visible == 0)
		{
			poly = poly->next;
			continue ;
		}
		poly->dots[0] = fdot_3d_add(poly->dots[0], dpos);
		poly->dots[1] = fdot_3d_add(poly->dots[1], dpos);
		poly->dots[2] = fdot_3d_add(poly->dots[2], dpos);
		poly->dots[3] = fdot_3d_add(poly->dots[3], dpos);
		poly->equation.d = -scalar_product(poly->equation.v, poly->dots[0]);
		poly = poly->next;
	}
}

void			translate_all_objects(t_object *object, t_fdot_3d dpos)
{
	while (object)
	{
		object->pos = fdot_3d_add(object->pos, dpos);
		object = object->next;
	}
}

void			translate_all(t_map *map, t_fdot_3d dpos)
{
	translate_all_poly(map->polys, dpos);
	translate_all_objects(map->objects, dpos);
	map->sky_box.pos = fdot_3d_add(map->sky_box.pos, dpos);
}
