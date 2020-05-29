/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_polygone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:47:11 by gal               #+#    #+#             */
/*   Updated: 2020/05/17 22:47:13 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	init_polygone_in(t_poly *poly)
{
	poly->i = poly->i_rotz_only;
	poly->j = poly->j_rotz_only;
	poly->i_mag = mag(poly->i);
	poly->j_mag = mag(poly->j);
	poly->ii = poly->i_mag * poly->i_mag;
	poly->jj = poly->j_mag * poly->j_mag;
	poly->equation_rotz_only.v = normalize(
							vectoriel_product(poly->i_rotz_only,
							poly->j_rotz_only));
	poly->equation_rotz_only.d = -(poly->equation_rotz_only.v.x\
							* poly->dots_rotz_only[0].x +\
		poly->equation_rotz_only.v.y * poly->dots_rotz_only[0].y +\
		poly->equation_rotz_only.v.z * poly->dots_rotz_only[0].z);
	poly->equation = poly->equation_rotz_only;
}

void		init_polygone(t_poly *poly)
{
	int		i;

	i = 0;
	while (poly)
	{
		if (!(poly->object && poly->object->type && poly->object->type == DOOR))
		{
			poly->visible = 1;
			poly->collide = 1;
		}
		poly->index = i++;
		poly->is_slide_ban = 0;
		ft_memcpy(poly->dots,
					poly->dots_rotz_only,
					sizeof(t_fdot_3d) * N_DOTS_POLY);
		poly->i_rotz_only = fdot_3d_sub(poly->dots_rotz_only[1],
										poly->dots_rotz_only[0]);
		poly->j_rotz_only = fdot_3d_sub(poly->dots_rotz_only[N_DOTS_POLY - 1],
										poly->dots_rotz_only[0]);
		init_polygone_in(poly);
		poly = poly->next;
	}
}
