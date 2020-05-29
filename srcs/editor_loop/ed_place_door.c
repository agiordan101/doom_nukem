/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_place_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 00:02:45 by widrye            #+#    #+#             */
/*   Updated: 2020/05/17 23:36:51 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

float				ed_get_line_degrees(t_line *l)
{
	float		dy;
	float		dx;
	float		angle;

	dy = l->p2.y - l->p1.y;
	dx = l->p2.x - l->p1.x;
	if (!dx)
		return (dy > 0 ? 90 : 270);
	if (!dy)
		return (dx > 0 ? 0 : 180);
	angle = ((atan(dy / dx)) * 180 / M_PI);
	if (dx < 0)
		angle += 180;
	else if (dy < 0)
		angle += 360;
	return (angle);
}

static t_object		*ed_init_door(t_dot p)
{
	t_object		*door;

	if (!(door = ft_memalloc(sizeof(t_object))))
		return (NULL);
	door->pos_rotz_only.x = p.x;
	door->pos_rotz_only.y = p.y;
	door->dir = 1;
	door->type = DOOR;
	door->height = 120;
	door->width = 30;
	door->texture = ft_strdup("doorfront.png");
	door->light_coef = 1;
	return (door);
}

static int			ed_place_door(t_win *win, t_map *map)
{
	static t_dot	p1 = (t_dot){0, 0};
	t_dot			p;

	p = ed_get_map_point(map, win->winui->mouse.pos);
	if (map->editor.flags & ED_DRAW_HELP)
		p = ed_is_next_to_poly(map, p, NEXT_RADIUS);
	if (!map->editor.placing_door)
	{
		p1 = p;
		if (!(map->editor.placing_door = ed_init_door(p1)))
			return (ui_ret_error("ed_place_door",
		"door allocation failed", 0));
	}
	else
	{
		map->editor.placing_door->dir = ed_get_line_degrees(&(t_line){p1, p});
		map->editor.placing_door->width = ed_get_line_len(&(t_line){p1, p});
		win->winui->mouse.pos = ed_get_display_point(map, p);
	}
	return (1);
}

void				ed_place_door_event(t_win *win, t_map *map)
{
	if (win->winui->mouse.releasing & UI_MOUSE_LEFT)
	{
		add_existing_object(&map->objects, map->editor.placing_door);
		map->editor.placing_door = NULL;
	}
	else if (win->winui->mouse.clicked & UI_MOUSE_LEFT)
		ed_place_door(win, map);
}
