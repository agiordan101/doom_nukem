/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobs_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:46:19 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/24 12:21:01 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void			mobs_move(t_fdot_3d pos, t_poly *poly,\
							float dist_mob, float vel)
{
	t_fdot_3d		move;
	float			cst_vel;

	cst_vel = vel / dist_mob;
	move = (t_fdot_3d){-pos.x * cst_vel,\
						-pos.y * cst_vel,\
						-pos.z * cst_vel};
	poly->dots_rotz_only[0] = fdot_3d_add(poly->dots_rotz_only[0], move);
	poly->dots_rotz_only[1] = fdot_3d_add(poly->dots_rotz_only[1], move);
	poly->dots_rotz_only[2] = fdot_3d_add(poly->dots_rotz_only[2], move);
	poly->dots_rotz_only[3] = fdot_3d_add(poly->dots_rotz_only[3], move);
	poly->equation_rotz_only.d = -scalar_product(poly->equation_rotz_only.v,\
													poly->dots_rotz_only[0]);
}

static void			mobs_apply_rotation(t_poly *poly, t_fdot_3d pos,\
										t_matrix rotation)
{
	poly->dots_rotz_only[0] =\
				fdot_3d_add(rotate_dot(fdot_3d_sub(poly->dots_rotz_only[0],\
													pos),\
										rotation),\
							pos);
	poly->dots_rotz_only[1] =\
				fdot_3d_add(rotate_dot(fdot_3d_sub(poly->dots_rotz_only[1],\
													pos),\
										rotation),\
							pos);
	poly->dots_rotz_only[2] =\
				fdot_3d_add(rotate_dot(fdot_3d_sub(poly->dots_rotz_only[2],\
													pos),\
										rotation),\
							pos);
	poly->dots_rotz_only[3] =\
				fdot_3d_add(rotate_dot(fdot_3d_sub(poly->dots_rotz_only[3],\
													pos),\
										rotation),\
							pos);
}

static void			mobs_rotate(t_fdot_3d pos, t_poly *poly)
{
	t_fdot_3d		v1;
	t_fdot_3d		v2;
	t_matrix		rotation;
	t_matrix		rz;
	t_matrix		rz_inv;

	rz = create_rz_matrix(SENSITIVE * 10);
	rz_inv = create_rz_matrix(-SENSITIVE * 10);
	v1 = rotate_dot(poly->equation_rotz_only.v, rz);
	v2 = rotate_dot(poly->equation_rotz_only.v, rz_inv);
	if (mag(fdot_3d_add(pos, v1)) < mag(fdot_3d_add(pos, v2)))
	{
		poly->equation_rotz_only.v = v1;
		rotation = rz;
	}
	else
	{
		poly->equation_rotz_only.v = v2;
		rotation = rz_inv;
	}
	mobs_apply_rotation(poly, pos, rotation);
}

void				mobs_attack_move(t_map *map, t_player *player, t_mob *mobs)
{
	t_fdot_3d		pos;
	float			dist_mob;
	float			dist;

	if (mobs)
	{
		dist = player->width_2 + mobs->width_2;
		while (mobs)
		{
			pos = mid_segment(mobs->poly->dots_rotz_only[0],\
								mobs->poly->dots_rotz_only[2]);
			if (mobs->alive && (dist_mob = mag(pos)) < mobs->agro_dist)
			{
				mobs_rotate(pos, mobs->poly);
				if (dist_mob < dist)
					apply_damage(map, player, mobs->damage);
				else
					mobs_move(pos, mobs->poly, dist_mob, mobs->vel);
			}
			mobs = mobs->next;
		}
	}
}
