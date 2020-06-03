/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_rotz_only.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiordan <agiordan@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:10:25 by agiordan          #+#    #+#             */
/*   Updated: 2020/03/07 21:23:51 by agiordan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			translate_all_poly_rotz_only(t_poly *poly, t_fdot_3d dpos)
{
	while (poly)
	{
		if (poly->object && poly->object->type == BOX &&\
			poly->object->visible == 0)
		{
			poly = poly->next;
			continue ;
		}
		poly->dots_rotz_only[0] = fdot_3d_add(poly->dots_rotz_only[0], dpos);
		poly->dots_rotz_only[1] = fdot_3d_add(poly->dots_rotz_only[1], dpos);
		poly->dots_rotz_only[2] = fdot_3d_add(poly->dots_rotz_only[2], dpos);
		poly->dots_rotz_only[3] = fdot_3d_add(poly->dots_rotz_only[3], dpos);
		poly->equation_rotz_only.d = -scalar_product(\
						poly->equation_rotz_only.v, poly->dots_rotz_only[0]);
		poly = poly->next;
	}
}

void			translate_all_objects_rotz_only(t_object *object,\
												t_fdot_3d dpos)
{
	while (object)
	{
		object->pos_rotz_only = fdot_3d_add(object->pos_rotz_only, dpos);
		object = object->next;
	}
}

void			translate_all_rotz_only(t_map *map, t_poly *poly,\
										t_fdot_3d dpos)
{
	translate_all_poly_rotz_only(poly, dpos);
	translate_all_objects_rotz_only(map->objects, dpos);
	map->sky_box.pos_rotz_only = fdot_3d_add(map->sky_box.pos_rotz_only, dpos);
}
