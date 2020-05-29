/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_display_polys.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:33 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 17:18:32 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_draw.h"

void		ed_display_polys_flat(t_win *win, const t_map *map)
{
	t_poly		*poly;
	SDL_Color	color;

	poly = map->polys;
	while (poly)
	{
		color = ed_get_flat_display_color(map, poly);
		ui_set_draw_color(win->rend, &color);
		if (ed_is_flat(poly) && ed_is_poly_printable(map, poly))
			ed_display_flat(win, map, poly);
		poly = poly->next;
	}
}

void		ed_display_polys_inclined(t_win *win, const t_map *map)
{
	t_poly		*poly;
	SDL_Color	color;

	color = (SDL_Color){255, 0, 0, 255};
	ui_set_draw_color(win->rend, &color);
	poly = map->polys;
	while (poly)
	{
		if (ed_is_inclined(poly) && ed_is_poly_printable(map, poly))
			ed_display_inclined(win, map, poly);
		poly = poly->next;
	}
}

void		ed_display_polys_wall(t_win *win, const t_map *map)
{
	t_poly		*poly;
	SDL_Color	color;

	poly = map->polys;
	while (poly)
	{
		color = ed_get_wall_display_color(map, poly);
		ui_set_draw_color(win->rend, &color);
		if (ed_is_wall(poly) && ed_is_poly_printable(map, poly))
			ed_display_wall(win, map, poly);
		poly = poly->next;
	}
}

static void	ed_display_placing_poly(t_win *win, const t_map *map)
{
	ui_set_draw_color(win->winui->rend,
					&(SDL_Color){255, 225, 0, 255});
	if (map->editor.placing_poly)
	{
		if (ed_is_wall(map->editor.placing_poly))
			ed_display_wall(win, map, map->editor.placing_poly);
		else if (ed_is_flat(map->editor.placing_poly))
			ed_display_flat(win, map, map->editor.placing_poly);
		else if (ed_is_inclined(map->editor.placing_poly))
			ed_display_inclined(win, map, map->editor.placing_poly);
	}
}

void		ed_display_polys(t_win *win, const t_map *map)
{
	ed_display_polys_flat(win, map);
	ed_display_polys_inclined(win, map);
	ed_display_polys_wall(win, map);
	ed_display_mobs(win, map);
	ed_display_placing_poly(win, map);
	ed_display_placing_door(win, map);
}
