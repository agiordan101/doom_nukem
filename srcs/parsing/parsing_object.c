#include "doom_nukem.h"

// void    set_poly_dots_rotz_only(t_object *object)
static void    set_poly_dots_rotz_only(t_poly *poly, t_fdot_3d pos, float width_2, float height_2)
{
	printf("poly %p\nDots \n", poly);
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
	printf("pos %f %f %f\n", pos.x, pos.y, pos.z);
	print_poly(poly, 1);
}

void			add_object(t_object **object)
{
	t_object *new_object;

	printf("New object\n");
	new_object = (t_object *)ft_memalloc(sizeof(t_object));
	new_object->next = *object;
	// new_object->next_light = NULL;
	new_object->collide = 1;
	new_object->visible = 1;
	new_object->width = 50;
	new_object->height = 50;
	new_object->light_coef = 1;
	new_object->data = 1;
	new_object->dir = 0;
	*object = new_object;

}

static int		add_poly_object_norm(t_object *object, char *type_str)
{
	if (type_str == NULL)
	{
		ft_putendl("Error: Type of object is wrong !");
		return (1);
	}
	if (!ft_strcmp(type_str, "HEAL"))
		object->type = HEAL;
	else if (!ft_strcmp(type_str, "ARMOR"))
		object->type = ARMOR;
	else if (!ft_strcmp(type_str, "TP"))
		object->type = TP;
	else if (!ft_strcmp(type_str, "GUN"))
		object->type = GUN;
	else if (!ft_strcmp(type_str, "BULLET"))
		object->type = BULLET;
	else if (!ft_strcmp(type_str, "GRAVITY_INV"))
		object->type = GRAVITY_INV;
	else if (!ft_strcmp(type_str, "DOOR"))
	{
		object->type = DOOR;
		set_door_object(object, object->pos_rotz_only, object->width_2, object->height_2);
		return (0);
	}
	else if (!ft_strcmp(type_str, "BOX"))
	{
		object->type = BOX;
	// printf("argegr\n");
	// printf("argegr\n");
		set_box_object(object, object->pos_rotz_only, object->width_2, object->height_2);
		return 0;
	}
	else if (!ft_strcmp(type_str, "LIGHT"))
	{
		object->type = LIGHT;

	}
	else
	{
		ft_putendl("Error: Type of object is wrong !");
		return (1);
	}
	// printf("argegr 2\n");
	// printf("argegr\n");
	if (!(object->poly = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (1);
	set_poly_dots_rotz_only(object->poly, object->pos_rotz_only, object->width_2, object->height_2);
	object->poly->object = object;
	object->poly->mob = NULL;
	object->poly->light_coef = object->light_coef;
	object->poly->next = NULL;
	return (0);
}

int				add_poly_object(t_object *object, char *type_str)
{
	printf("Pos rotz : %f %f %f\n", object->pos_rotz_only.x, object->pos_rotz_only.y, object->pos_rotz_only.z);
	if (add_poly_object_norm(object, type_str))
		return (1);
	printf("BOOOX pos %f %f %f\n", object->pos_rotz_only.x, object->pos_rotz_only.y, object->pos_rotz_only.z);
	return (0);
}

int				object_data(char **tab, t_object **object, int i)
{
	char	*type;

	type = NULL;
	add_object(object);
	type = object_data_fill(tab, object, i);
	(*object)->width_2 = (*object)->width / 2;
	(*object)->height_2 = (*object)->height / 2;
	if (add_poly_object(*object, type))
		return (1);
	free(type);
	return (0);
}
