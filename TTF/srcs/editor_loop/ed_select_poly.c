/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_select_poly.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:26 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:42:37 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static int		do_segs_intersect(t_line l1, t_line l2)
{
	float		s;
	float		t;
	t_fdot		d1;
	t_fdot		d2;
	float		divdis;

	d1 = (t_fdot){l1.p2.x - l1.p1.x, l1.p2.y - l1.p1.y};
	d2 = (t_fdot){l2.p2.x - l2.p1.x, l2.p2.y - l2.p1.y};
	if (!(divdis = -d2.x * d1.y + d1.x * d2.y))
		divdis += 0.0001;
	s = (-d1.y * (l1.p1.x - l2.p1.x) + d1.x * (l1.p1.y - l2.p1.y)) / divdis;
	t = (d2.x * (l1.p1.y - l2.p1.y) - d2.y * (l1.p1.x - l2.p1.x)) / divdis;
	if (s > 0 && s < 1 && t > 0 && t < 1)
		return (1);
	return (0);
}

static t_rect	ed_get_selected_rect(const t_rect *rect)
{
	t_rect		selected_rect;

	selected_rect = (t_rect){0, 0, 0, 0};
	if (rect)
	{
		selected_rect = *rect;
		if (selected_rect.w < 0)
		{
			selected_rect.w *= -1;
			selected_rect.x -= selected_rect.w;
		}
		if (selected_rect.h < 0)
		{
			selected_rect.h *= -1;
			selected_rect.y -= selected_rect.h;
		}
	}
	return (selected_rect);
}

int				rect_intersect_poly(t_map *map, t_poly poly)
{
	t_line		l1;
	t_line		l2;
	t_rect		rect;
	t_line		rect_diag;

	rect = ed_get_selected_rect(&map->editor.select_rect);
	l1.p1 = (t_dot){poly.dots[0].x, poly.dots[0].y};
	l1.p2 = (t_dot){poly.dots[2].x, poly.dots[2].y};
	l2.p1 = (t_dot){poly.dots[1].x, poly.dots[1].y};
	l2.p2 = (t_dot){poly.dots[3].x, poly.dots[3].y};
	rect_diag.p1 = (t_dot){rect.x, rect.y};
	rect_diag.p2 = (t_dot){rect.x + rect.w, rect.y + rect.h};
	if (do_segs_intersect(rect_diag, l1) || do_segs_intersect(rect_diag, l2))
		return (1);
	rect_diag.p1 = (t_dot){rect.x + rect.w, rect.y};
	rect_diag.p2 = (t_dot){rect.x, rect.y + rect.h};
	if (do_segs_intersect(rect_diag, l1) || do_segs_intersect(rect_diag, l2))
		return (1);
	return (0);
}

static SDL_bool	ed_is_wall_selected(const t_map *map, const t_poly poly)
{
	t_line		l;
	t_line		rect_side[6];
	t_rect		rect;
	int			i;

	l.p1 = (t_dot){poly.dots[0].x, poly.dots[0].y};
	l.p2 = (t_dot){poly.dots[1].x, poly.dots[1].y};
	rect = ed_get_selected_rect(&map->editor.select_rect);
	rect_side[0].p1 = (t_dot){rect.x, rect.y};
	rect_side[0].p2 = (t_dot){rect.x + rect.w, rect.y};
	rect_side[1].p1 = (t_dot){rect.x + rect.w, rect.y};
	rect_side[1].p2 = (t_dot){rect.x + rect.w, rect.y + rect.h};
	rect_side[2].p1 = (t_dot){rect.x + rect.w, rect.y + rect.h};
	rect_side[2].p2 = (t_dot){rect.x, rect.y + rect.h};
	rect_side[3].p1 = (t_dot){rect.x, rect.y + rect.h};
	rect_side[3].p2 = (t_dot){rect.x, rect.y};
	rect_side[4].p1 = (t_dot){rect.x, rect.y + rect.h};
	rect_side[4].p2 = (t_dot){rect.x + rect.w, rect.y};
	rect_side[5].p1 = (t_dot){rect.x, rect.y};
	rect_side[5].p2 = (t_dot){rect.x + rect.w, rect.y + rect.h};
	i = -1;
	while (++i < 6)
		if (do_segs_intersect(rect_side[i], l))
			return (1);
	return (0);
}

void			ed_get_selected_poly(t_map *map, int i)
{
	t_poly		*poly;

	if (map)
	{
		poly = map->polys;
		while (poly)
		{
			if (ed_is_poly_printable(map, poly))
			{
				if ((i == 0 && ed_is_wall(poly) &&
					ed_is_wall_selected(map, *poly)) ||
					(i == 1 && ed_is_flat(poly) &&
					rect_intersect_poly(map, *poly)) ||
					(i == 2 && ed_is_inclined(poly) &&
					rect_intersect_poly(map, *poly)))
				{
					ed_add_selected(&map->editor.list_selected,
							ed_new_selected((void*)poly, SELECTED_TYPE_POLY));
				}
			}
			poly = poly->next;
		}
		if (i < 3)
			ed_get_selected_poly(map, i + 1);
	}
}
