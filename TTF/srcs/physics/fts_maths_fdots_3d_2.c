/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_maths_fdots_3d_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiordan <agiordan@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:36:46 by agiordan          #+#    #+#             */
/*   Updated: 2020/03/07 19:20:41 by agiordan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_fdot_3d	normalize(t_fdot_3d vector)
{
	float	magnitude;

	magnitude = 1 / mag(vector);
	return ((t_fdot_3d){vector.x * magnitude,\
						vector.y * magnitude,\
						vector.z * magnitude});
}

t_fdot_3d	mid_segment(t_fdot_3d d1, t_fdot_3d d2)
{
	return ((t_fdot_3d){(d1.x + d2.x) / 2,\
						(d1.y + d2.y) / 2,\
						(d1.z + d2.z) / 2});
}

t_fdot_3d	intersection_axe_y(t_fdot_3d d1, t_fdot_3d d2)
{
	float	t;

	t = (1 - d1.x) / (d2.x - d1.x);
	return ((t_fdot_3d){1,\
						(d2.y - d1.y) * t + d1.y,\
						(d2.z - d1.z) * t + d1.z});
}

int			is_in_poly_rotz_only(t_poly *poly, t_fdot_3d dot)
{
	t_fdot	coord1;

	dot = fdot_3d_sub(dot, poly->dots_rotz_only[0]);
	coord1.x = scalar_product(dot, poly->i_rotz_only) / poly->ii;
	coord1.y = scalar_product(dot, poly->j_rotz_only) / poly->jj;
	return (coord1.x < 0 || 1 < coord1.x ||\
			coord1.y < 0 || 1 < coord1.y ? 0 : 1);
}

int			is_in_poly(t_poly *poly, t_fdot *coord, t_fdot_3d dot)
{
	dot = fdot_3d_sub(dot, poly->dots[0]);
	coord->x = scalar_product(dot, poly->i) / poly->ii;
	coord->y = scalar_product(dot, poly->j) / poly->jj;
	return (coord->x < 0 || coord->x > 1 || coord->y < 0 || coord->y > 1 ||\
	is_null(coord->x - 1, 0.000005) || is_null(coord->y, 0.000005) ? 0 : 1);
}
