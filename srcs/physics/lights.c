/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiordan <agiordan@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:22:02 by agiordan          #+#    #+#             */
/*   Updated: 2020/03/05 18:44:43 by agiordan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static int			is_in_shadow(t_map *map, t_object *light,\
									t_poly *poly_collision, t_fdot_3d collision)
{
	t_poly			*poly;
	t_fdot_3d		intersec;
	t_fdot			coord;
	t_cartesienne	ray;
	t_fdot_3d		vector;

	vector = fdot_3d_sub(collision, light->pos);
	ray = (t_cartesienne){light->pos.x, light->pos.y, light->pos.z,\
							vector.x, vector.y, vector.z,\
							0, NULL, 0, (t_fdot_3d){0, 0, 0}, NULL};
	poly = map->polys;
	while (poly)
	{
		if (poly != light->poly && poly != poly_collision &&\
			(!(poly->object || poly->mob) || ((poly->object &&\
			((poly->object->type == DOOR && poly->visible == 1) ||\
			(poly->object->type != DOOR && poly->object->visible == 1))) ||\
			(poly->mob && poly->mob->alive))) &&\
			intersection_plan_ray(&intersec, poly->equation, ray) &&\
			is_in_segment(intersec, light->pos, collision) &&\
			is_in_poly(poly, &coord, intersec))
			return (1);
		poly = poly->next;
	}
	return (0);
}

int					process_light(t_map *map, t_poly *poly,\
									t_fdot_3d collision, int color)
{
	float			light_coef;
	t_object		*object;

	light_coef = poly->light_coef;
	if (map->view & LIGHT_VIEW)
	{
		light_coef = 0;
		object = map->objects;
		while (object)
		{
			if (object->type == LIGHT &&\
				!is_in_shadow(map, object, poly, collision))
				light_coef += fabs(scalar_product(poly->equation.v,\
							normalize(fdot_3d_sub(collision, object->pos)))) *\
							object->data;
			object = object->next;
		}
		if ((light_coef *= poly->light_coef) > 1)
			light_coef = 1;
	}
	return (0xFF000000 +\
			((int)((color >> 16 & 0xFF) * light_coef) << 16) +\
			((int)((color >> 8 & 0xFF) * light_coef) << 8) +\
			(int)((color & 0xFF) * light_coef));
}
