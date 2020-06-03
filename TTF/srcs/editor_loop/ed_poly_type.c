/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_poly_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:23 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 17:36:46 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

SDL_bool		ed_is_wall(const t_poly *poly)
{
	int pairs;

	pairs = 0;
	if (poly->dots[0].x == poly->dots[3].x &&
		poly->dots[0].y == poly->dots[3].y)
		pairs++;
	if (poly->dots[1].x == poly->dots[2].x &&
		poly->dots[1].y == poly->dots[2].y)
		pairs++;
	return (pairs == 2);
}

SDL_bool		ed_is_inclined(const t_poly *poly)
{
	return (poly->dots[0].z == poly->dots[3].z &&
			poly->dots[1].z == poly->dots[2].z &&
			poly->dots[0].z != poly->dots[1].z);
}

SDL_bool		ed_is_flat(const t_poly *poly)
{
	return (poly->dots[0].z == poly->dots[1].z &&
			poly->dots[1].z == poly->dots[2].z &&
			poly->dots[2].z == poly->dots[3].z);
}
