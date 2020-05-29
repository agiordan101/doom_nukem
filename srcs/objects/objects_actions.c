/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:59:27 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/24 15:16:02 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static t_object	*catch_box(t_player *player, t_object *object,\
															t_cartesienne ray)
{
	t_fdot_3d	collision;
	t_fdot		coord;
	t_poly		*poly;
	int			i;

	while (object)
	{
		i = 0;
		poly = object->poly;
		while ((object->type == BOX || object->type == DOOR) &&\
				object->visible && poly)
		{
			if (intersection_plan_my_ray(&collision, poly->equation, &ray) &&\
				collision.x > 0 &&\
				is_in_poly(poly, &coord, collision) &&\
				mag(collision) < player->width * 3)
				return (object);
			if ((++i > 5 && object->type == BOX) ||\
				(i > 1 && object->type == DOOR))
				break ;
			poly = poly->next;
		}
		object = object->next;
	}
	return (NULL);
}

void			drop_box(t_map *map, t_player *player)
{
	t_object	*object;

	object = map->objects;
	while (object)
	{
		if (object->type == BOX && !object->visible && !object->collide)
		{
			rotate_box(player, object);
			object->collide = 1;
			object->visible = 1;
			return ;
		}
		object = object->next;
	}
}

void			objects_actions(t_map *map, t_player *player,\
								t_object *object)
{
	if (object->type == HEAL)
		player->inventory->item[0]->nb++;
	if (object->type == ARMOR)
		player->inventory->item[1]->nb++;
	if (object->type == DOOR)
		return ;
	if (object->type == GUN)
		player->inventory->weapon = 1;
	if (object->type == BULLET)
		player->inventory->item[3]->nb += 1;
	if (object->type == GRAVITY_INV)
	{
		map->gravity = -map->gravity;
		start_cooldown(&(map->gravity_inv_time), 5000);
	}
	if (object->type == END)
		player->end = 1;
	object->collide = 0;
	object->visible = 0;
}

void			objects_movements(t_map *map, t_player *player,\
															t_object *objects)
{
	t_object	*object;

	if (test_timer_refresh(&(map->objects_animation)))
		rotate_all_objects(player, objects);
	if (map->gravity < 0 && test_timer(&(map->gravity_inv_time)))
		map->gravity = -map->gravity;
	if (player->interaction_inventaire &&\
		(object = catch_box(player, objects, (t_cartesienne){0, 0, 0,\
															1, 0, 0,\
									0, NULL, 0, (t_fdot_3d){0, 0, 0}, NULL})))
	{
		if (object->type == DOOR)
			interact_door(map, object);
		else
		{
			player->inventory->item[4]->nb++;
			object->rot_y_save = player->rot_y;
			object->collide = 0;
			object->visible = 0;
		}
	}
}
