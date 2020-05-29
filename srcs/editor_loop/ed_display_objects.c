/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_display_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:23 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 18:33:48 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_draw.h"

void	ed_display_placing_door(t_win *win, const t_map *map)
{
	t_line	line;

	if (map->editor.placing_door)
	{
		line.p1 = ed_get_display_point(map,
				(t_dot){map->editor.placing_door->pos_rotz_only.x,
				map->editor.placing_door->pos_rotz_only.y});
		line.p2 = win->winui->mouse.pos;
		ui_set_draw_color(win->rend, &(SDL_Color){150, 255, 100, 255});
		ui_draw_line(win->rend, &line);
	}
}

void	ed_display_door(t_win *win, const t_map *map, t_object *obj)
{
	t_dot		pos;

	pos = ed_get_display_point(map,
	(t_dot){obj->pos_rotz_only.x, obj->pos_rotz_only.y});
	draw_quarter_circle(win,
	(t_circle){pos.x, pos.y, obj->width * map->editor.unit}, obj->dir);
}

void	ed_display_object(t_win *win, const t_map *map, t_object *obj)
{
	t_dot		pos;

	pos = ed_get_display_point(map,
	(t_dot){obj->pos_rotz_only.x, obj->pos_rotz_only.y});
	draw_circle(win,
	(t_circle){pos.x, pos.y, obj->width * map->editor.unit / 2});
}

void	ed_display_objects(t_win *win, const t_map *map)
{
	t_object	*obj;
	SDL_Color	color;

	obj = map->objects;
	while (obj)
	{
		color = ed_get_obj_display_color(map, obj);
		ui_set_draw_color(win->winui->rend, (SDL_Color*)&color);
		if (obj->type == DOOR)
			ed_display_door(win, map, obj);
		else
			ed_display_object(win, map, obj);
		obj = obj->next;
	}
}
