/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_place_inclined.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:08 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:22:09 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

static t_dot	ed_get_point_per_inclined_a1(t_poly *poly, double a1,
											t_dot mouse, t_dot point)
{
	int		b1;
	double	a2;
	int		b2;
	t_dot	inter;

	if (!a1)
	{
		inter.x = point.x;
		inter.y = point.y - (point.y - mouse.y);
	}
	else
	{
		b1 = poly->dots[3].y - a1 * poly->dots[3].x;
		a2 = -1 / a1;
		b2 = point.y - a2 * point.x;
		b1 = mouse.y - a1 * mouse.x;
		inter.x = (b2 - b1) / (a1 - a2);
		inter.y = a1 * inter.x + b1;
	}
	return (inter);
}

static t_dot	ed_get_point_per_inclined(t_poly *poly,
										t_dot mouse, t_dot point)
{
	t_dot	inter;

	if (poly->dots[3].x - poly->dots[0].x == 0)
	{
		inter.y = point.y;
		inter.x = point.x - (point.x - mouse.x);
	}
	else
	{
		inter = ed_get_point_per_inclined_a1(poly,
		(poly->dots[3].y - poly->dots[0].y) /
		(poly->dots[3].x - poly->dots[0].x), mouse, point);
	}
	return (inter);
}

static void		ed_spawn_inclined(t_map *map, t_dot p1)
{
	t_dot p2;

	p2 = ed_get_point_per_inclined(map->editor.placing_poly, p1,
						(t_dot){map->editor.placing_poly->dots[0].x,
								map->editor.placing_poly->dots[0].y});
	p1 = ed_get_point_per_inclined(map->editor.placing_poly, p1,
						(t_dot){map->editor.placing_poly->dots[3].x,
								map->editor.placing_poly->dots[3].y});
	map->editor.placing_poly->dots[2].x = p1.x;
	map->editor.placing_poly->dots[2].y = p1.y;
	map->editor.placing_poly->dots[1].x = p2.x;
	map->editor.placing_poly->dots[1].y = p2.y;
}

static t_poly	*ed_init_inclined(t_map *map, t_dot p1)
{
	t_poly		*poly;

	poly = NULL;
	if (!(poly = ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly->dots[0] = (t_fdot_3d)
	{p1.x, p1.y, map->editor.settings.inclined.z1};
	poly->dots[1] = (t_fdot_3d)
	{p1.x, p1.y, map->editor.settings.inclined.z2};
	poly->dots[2] = (t_fdot_3d)
	{p1.x, p1.y, map->editor.settings.inclined.z2};
	poly->dots[3] = (t_fdot_3d)
	{p1.x, p1.y, map->editor.settings.inclined.z1};
	poly->texture_name = ft_strdup(map->editor.settings.texture);
	poly->light_coef = 1;
	return (poly);
}

int				ed_place_inclined(t_win *win, t_map *map)
{
	t_dot		p1;

	p1 = ed_get_map_point(map, win->winui->mouse.pos);
	if (map->editor.flags & ED_DRAW_HELP)
		p1 = ed_is_next_to_poly(map, p1, NEXT_RADIUS);
	if (!map->editor.placing_poly)
	{
		if (!(map->editor.placing_poly = ed_init_inclined(map, p1)))
			return (ui_ret_error("ed_place_inclined",
			"placing_poly allocation failed", 0));
	}
	else if (map->editor.place_step == 1)
	{
		map->editor.placing_poly->dots[3].x = p1.x;
		map->editor.placing_poly->dots[3].y = p1.y;
	}
	else if (map->editor.place_step == 2)
		ed_spawn_inclined(map, p1);
	return (1);
}
