#include "doom_nukem.h"

int				is_collision_box(t_object *object, t_cartesienne *ray)
{
	t_poly		*poly;
	t_fdot_3d	collision;
	t_fdot		coord;
	int			i;

	poly = object->poly;
	i = -1;
	while (++i < 6)
	{
		if (!intersection_plan_my_ray(&collision, poly->equation, ray))
			return (0);
		if (is_in_poly(poly, &coord, fdot_3d_sub(collision, poly->dots[0])))
			return (1);
		poly = poly->next;
	}
	return (0);
}
