/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 22:12:26 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/28 14:58:48 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			add_existing_object(t_object **objects, t_object *new_object)
{
	if (new_object)
	{
		new_object->next = *objects;
		*objects = new_object;
	}
}

static void		rotate_object(t_player *player, t_poly *poly, t_fdot_3d origin)
{
	poly->equation_rotz_only.v = rotate_dot(\
						poly->equation_rotz_only.v, player->rz);
	poly->dots_rotz_only[0] = fdot_3d_add(rotate_dot(\
	fdot_3d_sub(poly->dots_rotz_only[0], origin), player->rz), origin);
	poly->dots_rotz_only[1] = fdot_3d_add(rotate_dot(\
	fdot_3d_sub(poly->dots_rotz_only[1], origin), player->rz), origin);
	poly->dots_rotz_only[2] = fdot_3d_add(rotate_dot(\
	fdot_3d_sub(poly->dots_rotz_only[2], origin), player->rz), origin);
	poly->dots_rotz_only[3] = fdot_3d_add(rotate_dot(\
	fdot_3d_sub(poly->dots_rotz_only[3], origin), player->rz), origin);
}

void			rotate_all_objects(t_player *player, t_object *object)
{
	t_fdot_3d	origin;
	int			i;

	while (object)
	{
		if (object->type != BOX && object->type != DOOR)
		{
			origin = mid_segment(object->poly->dots_rotz_only[0],\
								object->poly->dots_rotz_only[2]);
			i = 0;
			while (++i < OBJECT_ROTATION_VELOCITY)
				rotate_object(player, object->poly, origin);
		}
		object = object->next;
	}
}
