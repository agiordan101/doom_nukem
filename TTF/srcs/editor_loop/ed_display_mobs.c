/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_display_mobs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:19 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 16:33:31 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_draw.h"

void	ed_display_mob(t_win *win, const t_map *map, const t_mob *m)
{
	t_dot	pos;

	pos = ed_get_display_point(map, (t_dot){m->pos.x, m->pos.y});
	draw_circle(win, (t_circle){pos.x,
								pos.y,
								(m->width / 2.0) * map->editor.unit});
}

void	ed_display_mobs(t_win *win, const t_map *map)
{
	SDL_Color	color;
	t_mob		*m;

	m = map->mob;
	while (m)
	{
		color = ed_get_mob_display_color(map, m);
		ui_set_draw_color(win->winui->rend, (SDL_Color*)&color);
		ed_display_mob(win, map, m);
		m = m->next;
	}
}
