/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_mobs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:47:34 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/20 17:10:49 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static t_mob		*choose_mob(t_mob *mobs, t_cartesienne *ray)
{
	t_mob			*closest;
	t_fdot_3d		collision;
	t_fdot			coord_plan;
	int				dist_min;
	int				dist_tmp;

	closest = NULL;
	dist_min = -1;
	while (mobs)
	{
		if (mobs->alive)
		{
			if (intersection_plan_my_ray(&collision,\
												mobs->poly->equation, ray) &&\
				(dist_min == -1 || (dist_tmp = mag(collision)) < dist_min) &&\
				is_in_poly(mobs->poly, &coord_plan, collision))
			{
				closest = mobs;
				dist_min = dist_tmp;
			}
		}
		mobs = mobs->next;
	}
	return (closest);
}

void				hit_mobs(t_mob *mobs, int damage)
{
	t_cartesienne	ray;
	t_mob			*closest;

	ray = (t_cartesienne){0, 0, 0,\
							1, 0, 0,\
							0, NULL, 0, (t_fdot_3d){0, 0, 0}, NULL};
	if ((closest = choose_mob(mobs, &ray)))
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
