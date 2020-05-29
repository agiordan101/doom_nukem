/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiordan <agiordan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:06:50 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/11 02:16:52 by agiordan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
			{dot.x * matrix.index_00 +\
			dot.y * matrix.index_10 +\
			dot.z * matrix.index_20,\
			dot.x * matrix.index_01 +\
			dot.y * matrix.index_11 +\
			dot.z * matrix.index_21,\
			dot.x * matrix.index_02 +\
			dot.y * matrix.index_12 +\
			dot.z * matrix.index_22});
}
