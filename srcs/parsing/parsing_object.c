/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:05:29 by aducimet          #+#    #+#             */
/*   Updated: 2020/05/11 11:14:10 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		set_poly_dots_rotz_only(t_poly *poly, t_fdot_3d pos,\
												float width_2, float height_2)
{
	poly->dots_rotz_only[0].x = pos.x - width_2;
	poly->dots_rotz_only[0].y = pos.y;
	poly->dots_rotz_only[0].z = pos.z - height_2;
	poly->dots_rotz_only[1].x = pos.x + width_2;
	poly->dots_rotz_only[1].y = pos.y;
	poly->dots_rotz_only[1].z = pos.z - height_2;
	poly->dots_rotz_only[2].x = pos.x + width_2;
	poly->dots_rotz_only[2].y = pos.y;
	poly->dots_rotz_only[2].z = pos.z + height_2;
	poly->dots_rotz_only[3].x = pos.x - width_2;
	poly->dots_rotz_only[3].y = pos.y;
	poly->dots_rotz_only[3].z = pos.z + height_2;
}

static int		add_object(t_object **object)
{
	t_object	*new_object;

	if (!(new_object = (t_object *)ft_memalloc(sizeof(t_object))))
		return (1);
	new_object->next = *object;
	new_object->collide = 1;
	new_object->visible = 1;
	new_object->width = 50;
	new_object->height = 50;
	new_object->light_coef = 1;
	new_object->data = 1;
	new_object->dir = 0;
	*object = new_object;
	return (0);
}

static int		add_poly_object_norm3(t_object *object, char *type_str)
{
	if (!ft_strcmp(type_str, "BOX"))
	{
		object->type = BOX;
		if (set_box_object(object, object->pos_rotz_only,\
											object->width_2, object->height_2))
			return (1);
		return (0);
	}
	else if (!ft_strcmp(type_str, "DOOR"))
	{
		object->type = DOOR;
		if (set_door_object(object, object->pos_rotz_only,\
												object->width, object->height))
			return (1);
		return (0);
	}
	return (2);
}

static int		add_poly_object_norm(t_object *object, char *type_str)
{
	int ret;

	ret = -1;
	if (type_str == NULL)
	{
		ft_putendl("Error: Type of object is wrong !");
		return (1);
	}
	else if ((ret = add_poly_object_norm3(object, type_str)) == 0 || ret == 1)
		return (ret);
	add_poly_object_norm2(object, type_str);
	if (!(object->poly = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (1);
	set_poly_dots_rotz_only(object->poly, object->pos_rotz_only,\
											object->width_2, object->height_2);
	object->poly->light_coef = object->light_coef;
	object->poly->object = object;
	object->poly->mob = NULL;
	object->poly->next = NULL;
	return (0);
}

int				object_data(char **tab, t_object **object, int i)
{
	char		*type;

	if (add_object(object))
		return (1);
	type = object_data_fill(tab, object, i);
	(*object)->width_2 = (*object)->width / 2;
	(*object)->height_2 = (*object)->height / 2;
	(*object)->data = 1;
	if (add_poly_object_norm(*object, type))
		return (1);
	ft_strdel(&type);
	return (0);
}
