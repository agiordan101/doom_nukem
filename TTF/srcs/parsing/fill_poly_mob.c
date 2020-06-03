/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_poly_mob.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:57:38 by gal               #+#    #+#             */
/*   Updated: 2020/05/19 19:08:29 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static int	fill_poly_mob_norm(t_map *map, char *tmp, t_poly *poly_mob)
{
	if (!is_id_in_stock(map->texture_stock, tmp))
		add_stock_texture(&map->texture_stock, new_stock_texture(tmp));
	poly_mob->texture = get_surface_from_stock(map->texture_stock, tmp);
	return (0);
}

int			fill_poly_mob(t_map *map, t_poly *poly, t_mob *mob)
{
	char	*tmp;
	t_poly	*poly_mob;

	tmp = NULL;
	while (poly && poly->next)
		poly = poly->next;
	while (mob)
	{
		tmp = ft_strjoin("textures/", mob->texture);
		poly_mob = mob->poly;
		poly->light_coef = mob->light_coef;
		while (poly_mob)
		{
			if (fill_poly_mob_norm(map, tmp, poly_mob) == -1)
				return (-1);
			poly->next = poly_mob;
			poly = poly->next;
			poly_mob = poly_mob->next;
		}
		mob = mob->next;
		ft_strdel(&tmp);
	}
	return (0);
}
