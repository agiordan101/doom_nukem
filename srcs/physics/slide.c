#include "doom_nukem.h"

//Probleme si la collision est sur la tranche d'un plan
//Vaut mieux desactiver le slide dans ce cas
//Sinon pas realiste avec la hitbox

//Apres le while(collision) check si ya tjs une collision pour les is_slide_ban=1

t_fdot_3d			segment_slide(t_fdot_3d dots[N_DOTS_POLY], t_plan plan, int segment_code)
{
	// printf("Segment slide : produit vectoriel : Plan %f %f %f\n", plan.v.x, plan.v.y, plan.v.z);
	// printf("D1 : %f %f %f\n", dots[segment_code & 0b11].x,\
	// 							dots[segment_code & 0b11].y,\
	// 							dots[segment_code & 0b11].z);
	// printf("D2 : %f %f %f\n", dots[(segment_code & 0b1100) >> 2].x,\
	// 							dots[(segment_code & 0b1100) >> 2].y,\
	// 							dots[(segment_code & 0b1100) >> 2].z);
	return (vectoriel_product(plan.v,\
								fdot_3d_sub(dots[segment_code & 0b11],\
											dots[(segment_code & 0b1100) >> 2])));
}

void				slide(t_map *map, t_poly *polys, t_poly *polys_save, t_fdot_3d poly_collide_v)
{
	t_fdot_3d		dpos;
	t_plan			plan;
	t_fdot_3d		proj_ortho;
	t_cartesienne	proj_ortho_ray;

	dpos = (t_fdot_3d){polys_save->dots_rotz_only[0].x - polys->dots_rotz_only[0].x,\
						polys_save->dots_rotz_only[0].y - polys->dots_rotz_only[0].y,\
						polys_save->dots_rotz_only[0].z - polys->dots_rotz_only[0].z};
	plan = (t_plan){poly_collide_v, 0};
	proj_ortho_ray = (t_cartesienne){dpos.x, dpos.y, dpos.z,\
									plan.v.x,\
									plan.v.y,\
									plan.v.z,\
									0, NULL, 0, (t_fdot_3d){}, NULL};
									// 0, 0, NULL, 0, (t_fdot_3d){}, NULL};
	if (!intersection_plan_ray(&proj_ortho, plan, proj_ortho_ray))
	{
		printf("CHELOU slide trouve pas de collision ???\n");
		exit(1);
	}
	// printf("Ray o/v %f %f %f\t%f %f %f\n", proj_ortho_ray.ox, proj_ortho_ray.oy, proj_ortho_ray.oz,\
	// 											proj_ortho_ray.vx, proj_ortho_ray.vy, proj_ortho_ray.vz);
	// printf("Slide :  %f %f %f\n", proj_ortho.x, proj_ortho.y, proj_ortho.z);
	copy_poly_lst(map->polys, map->polys_save);
	// copy_poly_lst(map->polys, map->polys_save, map->objects, map->objects_save);
	translate_all_poly_rotz_only(polys, (t_fdot_3d){-proj_ortho.x,\
													-proj_ortho.y,\
													-proj_ortho.z});
	// translate_all_rotz_only(map, polys, (t_fdot_3d){-proj_ortho.x,\
	// 												-proj_ortho.y,\
	// 												-proj_ortho.z});
	map = NULL;
}
