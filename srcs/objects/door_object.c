/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:03:18 by widrye            #+#    #+#             */
/*   Updated: 2020/05/10 17:28:37 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int				orientate_door(t_object *door, t_fdot_3d pos)
{
	int		i;
	t_poly	*poly;
	t_fdot	tmp;
	t_fdot	rotated;
	float	theta;

	theta = door->dir * M_PI / 180;
	poly = door->poly;
	while (poly)
	{
		i = -1;
		while (++i < 4)
		{
			tmp.x = poly->dots_rotz_only[i].x - pos.x;
			tmp.y = poly->dots_rotz_only[i].y - pos.y;
			rotated.x = tmp.x * cos(theta) - tmp.y * sin(theta);
			rotated.y = tmp.x * sin(theta) + tmp.y * cos(theta);
			poly->dots_rotz_only[i].x = rotated.x + pos.x;
			poly->dots_rotz_only[i].y = rotated.y + pos.y;
		}
		poly = poly->next;
	}
	return (1);
}

int				interact_door(t_map *map, t_object *door)
{
	if (!door || door->type != DOOR || !door->poly || !door->poly->next)
		return (0);
	if (door->poly->next->visible && door->poly->next->collide)
	{
		door->poly->next->visible = 0;
		door->poly->next->collide = 0;
		door->poly->visible = 1;
		door->poly->collide = 1;
	}
	else if (door->poly->visible && door->poly->collide)
	{
		door->poly->visible = 0;
		door->poly->collide = 0;
		door->poly->next->visible = 1;
		door->poly->next->collide = 1;
	}
	Mix_PlayChannel(1, map->music->tmusic[6], 0);
	return (1);
}

static t_poly	*set_door_front(t_object *object,
				t_poly *poly, t_fdot_3d box[6])
{
	if (!(poly = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly->next = NULL;
	poly->object = object;
	poly->light_coef = object->light_coef;
	poly->visible = 1;
	poly->collide = 1;
	poly->dots_rotz_only[0] = box[0];
	poly->dots_rotz_only[1] = box[1];
	poly->dots_rotz_only[2] = box[2];
	poly->dots_rotz_only[3] = box[3];
	return (poly);
}

static	t_poly	*set_door_back(t_object *object, t_poly *poly, t_fdot_3d box[6])
{
	if (!(poly = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly->next = NULL;
	poly->object = object;
	poly->light_coef = object->light_coef;
	poly->visible = 0;
	poly->collide = 0;
	poly->dots_rotz_only[0] = box[0];
	poly->dots_rotz_only[1] = box[4];
	poly->dots_rotz_only[2] = box[5];
	poly->dots_rotz_only[3] = box[3];
	return (poly);
}

int				set_door_object(t_object *object, t_fdot_3d pos,
								float width, float height)
{
	t_fdot_3d	box[6];
	t_poly		*poly;

	box[0] = (t_fdot_3d){pos.x, pos.y, pos.z + height};
	box[1] = (t_fdot_3d){pos.x + width, pos.y, pos.z + height};
	box[2] = (t_fdot_3d){pos.x + width, pos.y, pos.z};
	box[3] = (t_fdot_3d){pos.x, pos.y, pos.z};
	box[4] = (t_fdot_3d){pos.x, pos.y + width, pos.z + height};
	box[5] = (t_fdot_3d){pos.x, pos.y + width, pos.z};
	poly = NULL;
	if (!(object->poly = set_door_front(object, poly, box)))
		return (1);
	if ((!(object->poly->next = set_door_back(object, poly, box))))
		return (1);
	object->collide = 0;
	if (object->dir)
		orientate_door(object, pos);
	return (0);
}
