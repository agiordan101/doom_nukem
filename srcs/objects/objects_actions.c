#include "doom_nukem.h"

// static void			tp(t_map *map, t_object *objects, t_object *object)
// {
// 	// t_fdot_3d		translate;

// 	// while (objects)
// 	// {
// 	// 	if (objects->type == TP && objects != object && objects->data == object->data)
// 	// 	{
// 	// 		translate_all_rotz_only(map, map->polys,\
// 	// 						translate = fdot_3d_sub(object->pos_rotz_only, objects->pos_rotz_only));
// 	// 		printf("Translate : %f %f %f\n", translate.x, translate.y, translate.z);
// 	// 		object->collide = 0;
// 	// 		object->poly->light_coef /= 3;
// 	// 		printf("TtttttppppppP\n");
// 	// 		return ;
// 	// 	}
// 	// 	objects = objects->next;
// 	// }
// 	map = NULL;
// 	objects = NULL;
// 	object = NULL;
// }

static t_object		*catch_box(t_player *player, t_object *object)
{
	t_fdot_3d		collision;
	t_fdot			coord;
	t_poly			*poly;
	t_cartesienne	ray;
	int				i;

	ray = (t_cartesienne){0, 0, 0, 1, 0, 0, 0, NULL, 0, (t_fdot_3d){}, NULL};
	while (object)
	{
		i = 0;
		poly = object->poly;
		while ((object->type == BOX || object->type == DOOR) && object->visible && poly)
		{
			if (intersection_plan_my_ray(&collision, poly->equation, &ray) &&\
				is_in_poly(poly, &coord, collision) &&\
				mag(collision) < player->width * 3)
				return (object);
			i++;
			if ((i > 6 && object->type == BOX) || (i > 1 && object->type == DOOR))
				break; //sans ca, boucle sur tous les polys de tous les objets et return le premier object de la liste a chaque fois
			poly = poly->next;
		}
		object = object->next;
	}
	return (NULL);
}

void				drop_box(t_map *map, t_player *player)
{
	t_object		*object;

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

static void			rotate_all_objects(t_player *player, t_object *object)
{
	t_fdot_3d	pos;

	while (object)
	{
		if (object->type != BOX && object->type != DOOR)
		{
			pos = mid_segment(object->poly->dots_rotz_only[0], object->poly->dots_rotz_only[2]);
			object->poly->equation_rotz_only.v = rotate_dot(object->poly->equation_rotz_only.v, player->rz);
			object->poly->dots_rotz_only[0] = fdot_3d_add(rotate_dot(fdot_3d_sub(object->poly->dots_rotz_only[0], pos), player->rz), pos);
			object->poly->dots_rotz_only[1] = fdot_3d_add(rotate_dot(fdot_3d_sub(object->poly->dots_rotz_only[1], pos), player->rz), pos);
			object->poly->dots_rotz_only[2] = fdot_3d_add(rotate_dot(fdot_3d_sub(object->poly->dots_rotz_only[2], pos), player->rz), pos);
			object->poly->dots_rotz_only[3] = fdot_3d_add(rotate_dot(fdot_3d_sub(object->poly->dots_rotz_only[3], pos), player->rz), pos);
		}
		object = object->next;
	}
}

void			objects_actions(t_map *map, t_player *player, t_object *object)
{
	// printf("Object : %d\n", object->type);
	if (object->type == HEAL)
	{
		player->inventory->item[0]->nb++;
		// printf("Popo heal +1\n");
	}
	if (object->type == ARMOR)
	{
		player->inventory->item[1]->nb++;
		// printf("Popo armor +1\n");
	}
	// if (object->type == TP)
	// {
	// 	if (object->collide && test_timer_refresh(&(map->objects_tp_timer)))
	// 		tp(map, map->objects, object);
	// 	return ;
	// }
	if (object->type == DOOR)
		return ;
	if (object->type == GUN)
		player->inventory->weapon = 1;
	if (object->type == BULLET)
		player->inventory->item[3]->nb += 1;
	if (object->type == GRAVITY_INV)
	{
		map->gravity = -map->gravity;
		start_cooldown(&(map->gravity_inv_time), 10000);
	}
	object->collide = 0;
	object->visible = 0;
}

void			objects_movements(t_map *map, t_player *player, t_object *objects)
{
	t_object	*object;

	if (test_timer_refresh(&(map->objects_animation)))
		rotate_all_objects(player, objects);
	if (map->gravity < 0 && test_timer(&(map->gravity_inv_time)))
		map->gravity = -map->gravity;
	if (player->interaction_inventaire && (object = catch_box(player, objects)))
	{
		if (object->type == DOOR)
			interact_door(object);
		else
		{
			player->inventory->item[4]->nb++;
			object->rot_y_save = player->rot_y;
			object->collide = 0;
			object->visible = 0;
		}
	}
}