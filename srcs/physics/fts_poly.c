/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_poly.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:23:48 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/17 00:02:42 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int			lstlen(t_poly *poly)
{
	int		count;

	count = 0;
	while (poly)
	{
		count++;
		poly = poly->next;
	}
	return (count);
}

void		copy_poly_lst(t_poly *dst, t_poly *src)
{
	t_poly	*tmp_next;
	int		tmp_is_slide_ban;

	while (src)
	{
		tmp_next = dst->next;
		tmp_is_slide_ban = dst->is_slide_ban;
		ft_memcpy(dst, src, sizeof(t_poly));
		dst->next = tmp_next;
		dst->is_slide_ban = tmp_is_slide_ban;
		dst = dst->next;
		src = src->next;
	}
}

int			create_poly_save(t_map *map)
{
	int		i;
	int		length;
	t_poly	*poly;

	if (!(length = lstlen(map->polys)) ||\
		!(map->polys_save = (t_poly *)malloc(sizeof(t_poly))))
		return (1);
	poly = map->polys_save;
	i = 0;
	while (++i < length)
	{
		if (!(poly->next = (t_poly *)malloc(sizeof(t_poly))))
			return (1);
		poly = poly->next;
	}
	poly->next = NULL;
	return (0);
}

int			check_parallelogram(t_poly *poly)
{
	int		i;

	i = 0;
	while (poly)
	{
		if (!is_null(mag(fdot_3d_sub(poly->dots[0], poly->dots[1])) -\
					mag(fdot_3d_sub(poly->dots[2], poly->dots[3])), 5))
		{
			ft_putstr("Polygone n°");
			ft_putnbr(i);
			ft_putendl(" is not a parallelogram");
			return (1);
		}
		if (!is_null(mag(fdot_3d_sub(poly->dots[1], poly->dots[2])) -\
					mag(fdot_3d_sub(poly->dots[3], poly->dots[0])), 5))
		{
			ft_putstr("Polygone n°");
			ft_putnbr(i);
			ft_putendl(" is not a parallelogram");
			return (1);
		}
		poly = poly->next;
		i++;
	}
	return (0);
}
