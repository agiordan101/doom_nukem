#include "doom_nukem.h"

void				hit_mobs(t_mob *mobs, int damage)
{
	t_cartesienne	ray;
	t_mob			*closest;
	t_fdot_3d		collision;
	t_fdot			coord_plan;
	int				tmp;
	int				dist_min;

	closest = NULL;
	dist_min = -1;
	ray = (t_cartesienne){0, 0, 0, 1, 0, 0, 0, NULL, 0, (t_fdot_3d){}, NULL};
	while (mobs)
	{
		if (mobs->alive)
		{
			if (!intersection_plan_my_ray(&collision, mobs->poly->equation, &ray))
				continue ;
			// printf("Collision %f %f %f\n", collision.x, collision.y, collision.z);
			if ((dist_min == -1 || (tmp = mag(collision)) < dist_min) &&\
				is_in_poly(mobs->poly, &coord_plan, collision))
			{
				closest = mobs;
				dist_min = tmp;
			}
		}
		mobs = mobs->next;
	}
	if (closest)
	{
		closest->health -= damage;
		if (closest->health <= 0)
		{
			closest->alive = 0;
			closest->poly->visible = 0;
			closest->poly->collide = 0;
		}
	}
}

static void		mobs_move(t_fdot_3d pos, t_poly *poly, float dist_mob, float vel)
{
	t_fdot_3d	move;
	float		cst_vel;

	cst_vel = vel / dist_mob;
	move = (t_fdot_3d){-pos.x * cst_vel,\
						-pos.y * cst_vel,\
						-pos.z * cst_vel};
	// translate_dot(&(pos), move);
	poly->dots_rotz_only[0] = fdot_3d_add(poly->dots_rotz_only[0], move);
	poly->dots_rotz_only[1] = fdot_3d_add(poly->dots_rotz_only[1], move);
	poly->dots_rotz_only[2] = fdot_3d_add(poly->dots_rotz_only[2], move);
	poly->dots_rotz_only[3] = fdot_3d_add(poly->dots_rotz_only[3], move);
	poly->equation_rotz_only.d = -(poly->equation_rotz_only.v.x * poly->dots_rotz_only[0].x +\
									poly->equation_rotz_only.v.y * poly->dots_rotz_only[0].y +\
									poly->equation_rotz_only.v.z * poly->dots_rotz_only[0].z);
	// printf("cst_vel %f\tvel %f\tdits_mob %f\n", cst_vel, vel, dist_mob);
}

static void		mobs_rotate(t_player *player, t_fdot_3d pos, t_poly *poly)
{
	t_fdot_3d	v1;
	t_fdot_3d	v2;
	t_matrix	rotation;

	v1 = rotate_dot(poly->equation_rotz_only.v, player->rz);
	v2 = rotate_dot(poly->equation_rotz_only.v, player->rz_inv);
	if (mag(fdot_3d_add(pos, v1)) < mag(fdot_3d_add(pos, v2)))
	{
		poly->equation_rotz_only.v = v1;
		rotation = player->rz;
	}
	else
	{
		poly->equation_rotz_only.v = v2;
		rotation = player->rz_inv;
	}
	poly->dots_rotz_only[0] = fdot_3d_add(rotate_dot(fdot_3d_sub(poly->dots_rotz_only[0], pos), rotation), pos);
	poly->dots_rotz_only[1] = fdot_3d_add(rotate_dot(fdot_3d_sub(poly->dots_rotz_only[1], pos), rotation), pos);
	poly->dots_rotz_only[2] = fdot_3d_add(rotate_dot(fdot_3d_sub(poly->dots_rotz_only[2], pos), rotation), pos);
	poly->dots_rotz_only[3] = fdot_3d_add(rotate_dot(fdot_3d_sub(poly->dots_rotz_only[3], pos), rotation), pos);
	//Inutile
	// poly->equation_rotz_only.d = -(poly->equation_rotz_only.v.x * poly->dots_rotz_only[0].x +\
	// 								poly->equation_rotz_only.v.y * poly->dots_rotz_only[0].y +\
	// 								poly->equation_rotz_only.v.z * poly->dots_rotz_only[0].z);
}

void			mobs_attack_move(t_map *map, t_player *player, t_mob *mobs)
{
	t_fdot_3d	pos;
	float		dist_mob;
	float		dist;

	dist = player->width_2 + mobs->width_2;
	while (mobs)
	{
		if (mobs->alive)
		{
			pos = mid_segment(mobs->poly->dots_rotz_only[0], mobs->poly->dots_rotz_only[2]);
			mobs_rotate(player, pos, mobs->poly);
			if (is_null(dist_mob = mag(pos), 1) || dist_mob < dist)
				apply_damage(map, player, mobs->damage);
			else
				mobs_move(pos, mobs->poly, dist_mob, mobs->vel);
		}
		mobs = mobs->next;
	}
}
