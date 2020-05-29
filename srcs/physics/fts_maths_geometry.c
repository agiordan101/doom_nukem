/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_maths_geometry.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiordan <agiordan@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:11:35 by agiordan          #+#    #+#             */
/*   Updated: 2020/03/05 18:15:24 by agiordan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_fdot_3d			proj_ortho_origin_line(t_fdot_3d d1, t_fdot_3d d2,\
											t_fdot_3d *proj)
{
	float			prop;
	t_fdot_3d		line;

	line = (t_fdot_3d){d2.x - d1.x, d2.y - d1.y, d2.z - d1.z};
	prop = scalar_product((t_fdot_3d){-d1.x, -d1.y, -d1.z},\
							line) /\
			scalar_product(line, line);
	proj->x = d1.x + line.x * prop;
	proj->y = d1.y + line.y * prop;
	proj->z = d1.z + line.z * prop;
	return ((t_fdot_3d){proj->x, proj->y, proj->z});
}

void				proj_ortho_plan(t_fdot_3d dot, t_plan plan,\
									t_fdot_3d *proj_ortho)
{
	intersection_plan_ray(proj_ortho, plan,\
					(t_cartesienne){dot.x, dot.y, dot.z,\
									plan.v.x, plan.v.y, plan.v.z,\
									0, NULL, 0, (t_fdot_3d){0, 0, 0}, NULL});
}

int					intersection_plan_my_ray(t_fdot_3d *collision, t_plan plan,\
												t_cartesienne *ray)
{
	float			t;
	float			denominateur;

	denominateur = plan.v.x + plan.v.y * ray->vy + plan.v.z * ray->vz;
	if (denominateur == 0)
		return (0);
	t = -plan.d / denominateur;
	collision->x = t;
	collision->y = ray->vy * t;
	collision->z = ray->vz * t;
	return (1);
}

int					intersection_plan_ray(t_fdot_3d *collision, t_plan plan,\
											t_cartesienne ray)
{
	float			t;
	float			denominateur;

	denominateur = plan.v.x * ray.vx + plan.v.y * ray.vy + plan.v.z * ray.vz;
	if (is_null(denominateur, 0.005))
		return (0);
	t = (-plan.d - plan.v.x * ray.ox - plan.v.y * ray.oy - plan.v.z * ray.oz) /\
		denominateur;
	collision->x = ray.vx * t + ray.ox;
	collision->y = ray.vy * t + ray.oy;
	collision->z = ray.vz * t + ray.oz;
	return (1);
}
