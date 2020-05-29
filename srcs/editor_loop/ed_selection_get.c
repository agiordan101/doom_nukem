/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_selection_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:21:15 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:43:18 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static SDL_bool	ed_is_mob_selected(t_win *win,
								const t_map *map,
								const t_mob *mob)
{
	if (ed_get_line_len(&(t_line){ed_get_map_point(map, win->winui->mouse.pos),
						(t_dot){mob->pos.x, mob->pos.y}}) < mob->width / 2.0)
		return (SDL_TRUE);
	else
		return (SDL_FALSE);
}

void			ed_get_selected_mob(t_win *win, t_map *map)
{
	t_mob	*m;

	m = map->mob;
	while (m)
	{
		if (ed_is_mob_selected(win, map, m))
		{
			ed_add_selected(&map->editor.list_selected,
						ed_new_selected((void*)m, SELECTED_TYPE_MOB));
		}
		m = m->next;
	}
}

void			ed_get_selected_player(t_win *win, t_map *map)
{
	if (ed_get_line_len(&(t_line){ed_get_map_point(map, win->winui->mouse.pos),
			(t_dot){map->player.pos.x, map->player.pos.y}}) < map->player.width)
	{
		ed_add_selected(&map->editor.list_selected,
					ed_new_selected((void*)&map->player, SELECTED_TYPE_PLAYER));
	}
}

static SDL_bool	ed_is_obj_selected(t_win *win,
								const t_map *map,
								const t_object *object)
{
	if (ed_get_line_len(&(t_line){ed_get_map_point(map, win->winui->mouse.pos),
					(t_dot){object->pos_rotz_only.x,
							object->pos_rotz_only.y}}) < object->width / 2.0)
		return (SDL_TRUE);
	else
		return (SDL_FALSE);
}

void			ed_get_selected_obj(t_win *win, t_map *map)
{
	t_object	*obj;

	obj = map->objects;
	while (obj)
	{
		if (ed_is_obj_selected(win, map, obj))
		{
			ed_add_selected(&map->editor.list_selected,
						ed_new_selected((void*)obj, SELECTED_TYPE_OBJECT));
		}
		obj = obj->next;
	}
}
