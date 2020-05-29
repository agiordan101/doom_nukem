/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_maths_algebra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:23:53 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/10 12:02:21 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

/*
**	Une distance calcule avec sqrt doit tjs etre revoyer
**	en float, a nous de la cast apres si on veut
*/

float		modulo(float nbr, float mod)
{
	if (nbr < 0)
		return (mod - modulo(-nbr, mod));
	return (nbr - (int)(nbr / mod) * mod -\
					(mod < 0 ? mod : 0));
}

float		scalar_product(t_fdot_3d v1, t_fdot_3d v2)
{
	return ((float)(v1.x * v2.x + v1.y * v2.y + v1.z * v2.z));
}

t_fdot_3d	vectoriel_product(t_fdot_3d v1, t_fdot_3d v2)
{
	return ((t_fdot_3d){v1.y * v2.z - v1.z * v2.y,\
						v1.z * v2.x - v1.x * v2.z,\
						v1.x * v2.y - v1.y * v2.x});
}

int			is_null(float nbr, float precision)
{
	return (!(nbr > precision || nbr < -precision) ? 1 : 0);
}

int			resolve_polynome(t_fdot_3d polynome, float *x1, float *x2)
{
	float	delta;

	if ((delta = polynome.y * polynome.y - 4 * polynome.x * polynome.z) < 0)
		return (0);
	*x1 = (-polynome.y - sqrt(delta)) / (2 * polynome.x);
	*x2 = (-polynome.y + sqrt(delta)) / (2 * polynome.x);
	return (1);
}
