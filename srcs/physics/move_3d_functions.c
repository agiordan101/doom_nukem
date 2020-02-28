#include "doom_nukem.h"

void			rotate_box(t_player *player, t_object *object)
{
	t_poly		*poly;
	t_matrix	matrix;
	int			i;

	matrix = create_ry_matrix(-object->rot_y_save + player->rot_y);
	object->pos = rotate_dot(object->pos, matrix);
	poly = object->poly;
	i = -1;
	while (poly && ++i < 6)
	{
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
}

t_fdot_3d		rotate_dot(t_fdot_3d dot, t_matrix matrix)
{
	return ((t_fdot_3d)\
			{dot.x * matrix._00 + dot.y * matrix._10 + dot.z * matrix._20,\
			dot.x * matrix._01 + dot.y * matrix._11 + dot.z * matrix._21,\
			dot.x * matrix._02 + dot.y * matrix._12 + dot.z * matrix._22});
}

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
}

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
}

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

void			translate_all_objects_rotz_only(t_object *object, t_fdot_3d dpos)
{
	while (object)
	{
		object->pos_rotz_only = fdot_3d_add(object->pos_rotz_only, dpos);
		object = object->next;
	}
}

void			translate_all_rotz_only(t_map *map, t_poly *poly, t_fdot_3d dpos)
{
	translate_all_poly_rotz_only(poly, dpos);
	translate_all_objects_rotz_only(map->objects, dpos);
}
