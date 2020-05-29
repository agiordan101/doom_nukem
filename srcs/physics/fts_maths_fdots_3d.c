/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_maths_fdots_3d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiordan <agiordan@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:34:45 by agiordan          #+#    #+#             */
/*   Updated: 2020/03/05 17:35:00 by agiordan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

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

float		mag(t_fdot_3d v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
