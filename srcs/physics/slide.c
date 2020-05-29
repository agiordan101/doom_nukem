/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiordan <agiordan@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:09:19 by agiordan          #+#    #+#             */
/*   Updated: 2020/03/05 17:24:20 by agiordan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_fdot_3d			segment_slide(t_fdot_3d dots[N_DOTS_POLY], t_plan plan,\
									int segment_code)
{
	return (vectoriel_product(plan.v,\
			fdot_3d_sub(dots[segment_code & 0b0011],\
						dots[(segment_code & 0b1100) >> 2])));
}

void				slide(t_map *map, t_poly *polys,\
							t_poly *polys_save, t_fdot_3d poly_collide_v)
{
	t_fdot_3d		dpos;
	t_plan			plan;
	t_fdot_3d		proj_ortho;
	t_cartesienne	proj_ortho_ray;

	dpos = (t_fdot_3d){polys_save->dots_rotz_only[0].x -\
													polys->dots_rotz_only[0].x,\
						polys_save->dots_rotz_only[0].y -\
													polys->dots_rotz_only[0].y,\
						polys_save->dots_rotz_only[0].z -\
													polys->dots_rotz_only[0].z};
	plan = (t_plan){poly_collide_v, 0};
	proj_ortho_ray = (t_cartesienne){dpos.x, dpos.y, dpos.z,\
									plan.v.x,\
									plan.v.y,\
									plan.v.z,\
									0, NULL, 0, (t_fdot_3d){0, 0, 0}, NULL};
	if (!intersection_plan_ray(&proj_ortho, plan, proj_ortho_ray))
		return ;
	copy_poly_lst(map->polys, map->polys_save);
	translate_all_poly_rotz_only(polys, (t_fdot_3d){-proj_ortho.x,\
													-proj_ortho.y,\
													-proj_ortho.z});
}
