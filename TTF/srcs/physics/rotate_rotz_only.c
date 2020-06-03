/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rotz_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:06:48 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/20 11:54:27 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			rotate_all_objects_rotz_only(t_object *object, t_matrix matrix)
{
	while (object)
	{
		object->pos_rotz_only = rotate_dot(object->pos_rotz_only, matrix);
		object = object->next;
	}
}

void			rotate_all_rotz_only(t_map *map, t_poly *poly, t_matrix matrix)
{
	while (poly)
	{
		if (poly->object && poly->object->type == BOX &&\
				poly->object->visible == 0)
		{
			poly = poly->next;
			continue ;
		}
		poly->equation_rotz_only.v = rotate_dot(poly->equation_rotz_only.v,\
												matrix);
		poly->dots_rotz_only[0] = rotate_dot(poly->dots_rotz_only[0], matrix);
		poly->dots_rotz_only[1] = rotate_dot(poly->dots_rotz_only[1], matrix);
		poly->dots_rotz_only[2] = rotate_dot(poly->dots_rotz_only[2], matrix);
		poly->dots_rotz_only[3] = rotate_dot(poly->dots_rotz_only[3], matrix);
		poly->i_rotz_only = fdot_3d_sub(poly->dots_rotz_only[1],\
										poly->dots_rotz_only[0]);
		poly->j_rotz_only = fdot_3d_sub(poly->dots_rotz_only[N_DOTS_POLY - 1],\
										poly->dots_rotz_only[0]);
		poly = poly->next;
	}
	rotate_all_objects_rotz_only(map->objects, matrix);
	map->sky_box.pos_rotz_only = rotate_dot(map->sky_box.pos_rotz_only, matrix);
	map->sky_box.i_rotz_only = rotate_dot(map->sky_box.i_rotz_only, matrix);
	map->sky_box.j_rotz_only = rotate_dot(map->sky_box.j_rotz_only, matrix);
}

static void		copy_rotate_objects_rotz_only(t_object *object, t_matrix matrix)
{
	while (object)
	{
		object->pos = rotate_dot(object->pos_rotz_only, matrix);
		object = object->next;
	}
}

void			copy_rotate_rotz_only(t_map *map, t_poly *poly, t_matrix matrix)
{
	while (poly)
	{
		if (poly->object && poly->object->type == BOX &&\
			poly->object->visible == 0)
		{
			poly = poly->next;
			continue ;
		}
		poly->equation.v = rotate_dot(poly->equation_rotz_only.v, matrix);
		poly->equation.d = poly->equation_rotz_only.d;
		poly->dots[0] = rotate_dot(poly->dots_rotz_only[0], matrix);
		poly->dots[1] = rotate_dot(poly->dots_rotz_only[1], matrix);
		poly->dots[2] = rotate_dot(poly->dots_rotz_only[2], matrix);
		poly->dots[3] = rotate_dot(poly->dots_rotz_only[3], matrix);
		poly->i = fdot_3d_sub(poly->dots[1],\
								poly->dots[0]);
		poly->j = fdot_3d_sub(poly->dots[N_DOTS_POLY - 1],\
								poly->dots[0]);
		poly = poly->next;
	}
	copy_rotate_objects_rotz_only(map->objects, matrix);
	map->sky_box.pos = rotate_dot(map->sky_box.pos_rotz_only, matrix);
	map->sky_box.i = rotate_dot(map->sky_box.i_rotz_only, matrix);
	map->sky_box.j = rotate_dot(map->sky_box.j_rotz_only, matrix);
}
