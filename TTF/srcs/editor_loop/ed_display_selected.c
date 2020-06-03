/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_display_selected.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:35 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:40:59 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_draw.h"

void		ed_display_selected_poly(t_win *win,
									const t_map *map,
									const t_poly *selected)
{
	if (selected
		&& ed_is_poly_printable(map, selected))
	{
		ui_set_draw_color(win->winui->rend, &(SDL_Color){0, 200, 200, 255});
		if (ed_is_wall(selected))
			ed_display_wall(win, map, (t_poly*)selected);
		else if (ed_is_inclined(selected))
			ed_display_inclined(win, map, (t_poly*)selected);
		else if (ed_is_flat(selected))
			ed_display_flat(win, map, (t_poly*)selected);
	}
}

void		ed_display_selected_mob(t_win *win,
									const t_map *map,
									const t_mob *selected)
{
	t_dot	pos;

	if (selected)
	{
		ui_set_draw_color(win->winui->rend, &(SDL_Color){0, 200, 200, 255});
		pos = ed_get_display_point(map,
									(t_dot){selected->pos.x,
											selected->pos.y});
		draw_circle(win,
			(t_circle){pos.x, pos.y,
			selected->width * map->editor.unit / 2});
		ui_set_draw_color(win->winui->rend, &(SDL_Color){200, 255, 50, 255});
		draw_circle(win,
			(t_circle){pos.x, pos.y,
			selected->agro_dist * map->editor.unit});
	}
}

void		ed_display_selected_obj(t_win *win,
									const t_map *map,
									const t_object *selected)
{
	t_dot		pos;

	if (selected)
	{
		ui_set_draw_color(win->winui->rend, &(SDL_Color){0, 200, 200, 255});
		pos = ed_get_display_point(map,
						(t_dot){selected->pos_rotz_only.x,
								selected->pos_rotz_only.y});
		if (selected->type == DOOR)
			draw_quarter_circle(win, (t_circle){pos.x, pos.y,
											selected->width * map->editor.unit},
											selected->dir);
		else
			draw_circle(win, (t_circle){pos.x, pos.y,
									selected->width * map->editor.unit / 2});
	}
}
