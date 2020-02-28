#include "doom_nukem.h"

/*
**	Une distance calcule avec sqrt doit tjs etre revoyer
**	en float, a nous de la cast apres si on veut
*/

float		modulo(float nbr, float mod)
{
	if (nbr < 0)
		return (mod - modulo(-nbr, mod));
	return (nbr - (int)(nbr / mod) * mod -\
					(mod < 0 ? mod : 0));
}

float		fdist_3d(t_fdot_3d p1, t_fdot_3d p2)
{
	return (sqrt((p2.x - p1.x) * (p2.x - p1.x) +\
					(p2.y - p1.y) * (p2.y - p1.y) +\
					(p2.z - p1.z) * (p2.z - p1.z)));
}

float		fdist_3d_squared(t_fdot_3d p1, t_fdot_3d p2)
{
	return ((p2.x - p1.x) * (p2.x - p1.x) +\
			(p2.y - p1.y) * (p2.y - p1.y) +\
			(p2.z - p1.z) * (p2.z - p1.z));
}

float		mag(t_fdot_3d v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

int			sign(float nbr)
{
	return (nbr < 0 ? -1 : 1);
}

int			is_null(float nbr, float precision)
{
	return (!(nbr > precision || nbr < -precision) ? 1 : 0);
}

t_fdot_3d	fdot_3d_add(t_fdot_3d d1, t_fdot_3d d2)
{
	return ((t_fdot_3d){d1.x + d2.x,\
						d1.y + d2.y,\
						d1.z + d2.z});
}

t_fdot_3d	fdot_3d_sub(t_fdot_3d d1, t_fdot_3d d2)
{
	return ((t_fdot_3d){d1.x - d2.x,\
						d1.y - d2.y,\
						d1.z - d2.z});
}

t_fdot_3d	normalize(t_fdot_3d vector)
{
	float	magnitude;

	magnitude = 1 / mag(vector);
	return ((t_fdot_3d){vector.x * magnitude,\
						vector.y * magnitude,\
						vector.z * magnitude});
}

float		scalar_product(t_fdot_3d v1, t_fdot_3d v2)
{
	return ((float)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

t_fdot_3d	vectoriel_product(t_fdot_3d v1, t_fdot_3d v2)
{
	return ((t_fdot_3d){v1.y * v2.z - v1.z * v2.y,\
						v1.z * v2.x - v1.x * v2.z,\
						v1.x * v2.y - v1.y * v2.x});
}

t_fdot_3d	mid_segment(t_fdot_3d d1, t_fdot_3d d2)
{
	return ((t_fdot_3d){(d1.x + d2.x) / 2,\
						(d1.y + d2.y) / 2,\
						(d1.z + d2.z) / 2});
}
