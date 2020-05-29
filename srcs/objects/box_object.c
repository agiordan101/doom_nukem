/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:25:38 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/16 23:27:57 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static t_poly	*set_box_1(t_object *object, t_poly *poly, t_fdot_3d box[8])
{
	if (!(object->poly = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly = object->poly;
	poly->object = object;
	poly->light_coef = object->light_coef;
	poly->dots_rotz_only[0] = box[0];
	poly->dots_rotz_only[1] = box[1];
	poly->dots_rotz_only[2] = box[3];
	poly->dots_rotz_only[3] = box[2];
	if (!(poly->next = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly = poly->next;
	poly->object = object;
	poly->light_coef = object->light_coef;
	poly->dots_rotz_only[0] = box[4];
	poly->dots_rotz_only[1] = box[5];
	poly->dots_rotz_only[2] = box[7];
	poly->dots_rotz_only[3] = box[6];
	return (poly);
}

static t_poly	*set_box_2(t_object *object, t_poly *poly, t_fdot_3d box[8])
{
	if (!(poly->next = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly = poly->next;
	poly->object = object;
	poly->light_coef = object->light_coef;
	poly->dots_rotz_only[0] = box[0];
	poly->dots_rotz_only[1] = box[2];
	poly->dots_rotz_only[2] = box[6];
	poly->dots_rotz_only[3] = box[4];
	if (!(poly->next = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly = poly->next;
	poly->object = object;
	poly->light_coef = object->light_coef;
	poly->dots_rotz_only[0] = box[2];
	poly->dots_rotz_only[1] = box[3];
	poly->dots_rotz_only[2] = box[7];
	poly->dots_rotz_only[3] = box[6];
	return (poly);
}

static t_poly	*set_box_3(t_object *object, t_poly *poly, t_fdot_3d box[8])
{
	if (!(poly->next = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly = poly->next;
	poly->object = object;
	poly->light_coef = object->light_coef;
	poly->dots_rotz_only[0] = box[3];
	poly->dots_rotz_only[1] = box[1];
	poly->dots_rotz_only[2] = box[5];
	poly->dots_rotz_only[3] = box[7];
	if (!(poly->next = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly = poly->next;
	poly->object = object;
	poly->light_coef = object->light_coef;
	poly->dots_rotz_only[0] = box[1];
	poly->dots_rotz_only[1] = box[0];
	poly->dots_rotz_only[2] = box[4];
	poly->dots_rotz_only[3] = box[5];
	return (poly);
}

int				set_box_object(t_object *object, t_fdot_3d pos,\
								float width_2, float height_2)
{
	t_fdot_3d	box[8];
	t_poly		*poly;

	box[0] = (t_fdot_3d){pos.x + width_2, pos.y - width_2, pos.z + height_2};
	box[1] = (t_fdot_3d){pos.x + width_2, pos.y + width_2, pos.z + height_2};
	box[2] = (t_fdot_3d){pos.x - width_2, pos.y - width_2, pos.z + height_2};
	box[3] = (t_fdot_3d){pos.x - width_2, pos.y + width_2, pos.z + height_2};
	box[4] = (t_fdot_3d){pos.x + width_2, pos.y - width_2, pos.z - height_2};
	box[5] = (t_fdot_3d){pos.x + width_2, pos.y + width_2, pos.z - height_2};
	box[6] = (t_fdot_3d){pos.x - width_2, pos.y - width_2, pos.z - height_2};
	box[7] = (t_fdot_3d){pos.x - width_2, pos.y + width_2, pos.z - height_2};
	poly = NULL;
	if (!(poly = set_box_1(object, poly, box)))
		return (1);
	if (!(poly = set_box_2(object, poly, box)))
		return (1);
	if (!(poly = set_box_3(object, poly, box)))
		return (1);
	return (0);
}
