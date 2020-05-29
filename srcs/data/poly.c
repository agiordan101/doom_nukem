/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:21:58 by gal               #+#    #+#             */
/*   Updated: 2020/05/16 23:26:12 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	add_poly(t_poly **poly)
{
	t_poly	*new_poly;

	if (!(new_poly = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (ft_putendl("poly allocation failed in poly.c"));
	new_poly->next = *poly;
	new_poly->light_coef = 1;
	*poly = new_poly;
}

void	init_fpoly(t_poly **poly)
{
	t_poly	*new_poly;

	if (!(new_poly = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (ft_putendl("poly allocation failed in poly.c"));
	new_poly->next = *poly;
	new_poly->light_coef = 1;
	new_poly->dots_rotz_only[0].x = -10000;
	new_poly->dots_rotz_only[1].x = -10000;
	new_poly->dots_rotz_only[2].x = -10000;
	new_poly->dots_rotz_only[3].x = -10000;
	new_poly->texture_name = ft_strdup("brique.png");
	new_poly->texture = IMG_Load("textures/brique.png");
	*poly = new_poly;
}

void	add_existing_poly(t_poly **polys, t_poly *poly)
{
	if (poly)
	{
		poly->next = *polys;
		*polys = poly;
	}
}
