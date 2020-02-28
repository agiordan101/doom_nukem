#include "doom_nukem.h"


static t_rect	ed_get_selected_rect(const t_rect *rect)
{
	t_rect	selected_rect;

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

static SDL_bool	ed_is_wall_selected(const t_map *map, const t_poly *poly)
{
	t_dot	p1;
	t_dot	p2;
	t_rect	rect;

	p1.x = poly->dots[0].x;
	p1.y = poly->dots[0].y;
	p2.x = poly->dots[1].x;
	p2.y = poly->dots[1].y;
	rect = ed_get_selected_rect(&map->editor.select_rect);
	return (SDL_IntersectRectAndLine((SDL_Rect*)&rect,
			&p1.x, &p1.y, &p2.x, &p2.y));
}

static SDL_bool	ed_is_flat_selected(const t_map *map, const t_poly *poly)
{
	t_line	l1;
	t_line	l2;
	t_rect	rect;

	l1.p1 = (t_dot){poly->dots[0].x, poly->dots[0].y};
	l1.p2 = (t_dot){poly->dots[2].x, poly->dots[2].y};
	l2.p1 = (t_dot){poly->dots[1].x, poly->dots[1].y};
	l2.p2 = (t_dot){poly->dots[3].x, poly->dots[3].y};
	rect = ed_get_selected_rect(&map->editor.select_rect);
	return (SDL_IntersectRectAndLine((SDL_Rect*)&rect,
			&l1.p1.x, &l1.p1.y, &l1.p2.x, &l1.p2.y)
			||
			SDL_IntersectRectAndLine((SDL_Rect*)&rect,
			&l2.p1.x, &l2.p1.y, &l2.p2.x, &l2.p2.y));
}

static SDL_bool	ed_is_inclined_selected(t_win *win, const t_map *map, const t_poly *poly)
{
	t_rect	rect;
	t_dot	point;
	
	rect.x = poly->dots[0].x;
	rect.y = poly->dots[0].y;
	rect.w = ft_abs(poly->dots[2].x - rect.x);
	rect.h = ft_abs(poly->dots[2].y - rect.y);
	point = ed_get_map_point(map, win->winui->mouse.pos);
	return (SDL_PointInRect((SDL_Point*)&point,
							(SDL_Rect*)&rect));
}

t_poly			*ed_get_selected_poly(t_win *win, t_map *map)
{
	t_poly	*poly;

	poly = NULL;
	if (map)
	{
		poly = map->polys;
		while (poly)
		{
			if (ed_is_poly_printable(map, poly))
				if (ed_is_wall(poly) && ed_is_wall_selected(map, poly))
					return (poly);
			poly = poly->next;
		}
		poly = map->polys;
		while (poly)
		{
			if (ed_is_poly_printable(map, poly))
				if (ed_is_flat(poly) && ed_is_flat_selected(map, poly))
					return (poly);
			poly = poly->next;
		}
		poly = map->polys;
		while (poly)
		{
			if (ed_is_poly_printable(map, poly))
				if (ed_is_inclined(poly) && ed_is_inclined_selected(win, map, poly))
					return (poly);
			poly = poly->next;
		}
	}
	return (NULL);
}
