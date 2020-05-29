/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:41 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:23:46 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

static void	ed_move_player_z(t_map *map)
{
	t_poly		*p;
	t_mob		*mob;
	t_object	*obj;
	int			i;

	p = map->polys;
	while (p)
	{
		i = 0;
		while (i < 4)
			p->dots[i++].z -= map->player.pos.z;
		p = p->next;
	}
	obj = map->objects;
	while (obj)
	{
		obj->pos_rotz_only.z -= map->player.pos.z;
		obj = obj->next;
	}
	mob = map->mob;
	while (mob)
	{
		mob->pos.z -= map->player.pos.z;
		mob = mob->next;
	}
}

static void	ed_delete_event(t_win *win, t_map *map)
{
	if (map->editor.selected)
	{
		if (map->editor.selected->selected_type == SELECTED_TYPE_POLY)
			delete_poly(&map->polys, (t_poly*)map->editor.selected->ptr);
		else if (map->editor.selected->selected_type == SELECTED_TYPE_MOB)
			ed_delete_mob(&map->mob, (t_mob*)map->editor.selected->ptr);
		else if (map->editor.selected->selected_type == SELECTED_TYPE_OBJECT)
			ed_delete_obj(map, &map->objects,
							(t_object*)map->editor.selected->ptr);
		ed_clean_property(win, 1);
		ed_free_selected(&map->editor.list_selected);
		map->editor.selected = NULL;
	}
}

static void	ed_next_events(t_win *win, t_map *map, const Uint8 *state)
{
	if (state[SDL_SCANCODE_SPACE])
	{
		if (map->editor.flags & ED_DRAW_HELP)
			map->editor.flags ^= ED_DRAW_HELP;
	}
	else
	{
		if (!(map->editor.flags & ED_DRAW_HELP))
			map->editor.flags |= ED_DRAW_HELP;
	}
	if (win->winui->event.type == SDL_MOUSEWHEEL)
	{
		map->editor.unit += win->winui->event.wheel.y * 0.01;
		win->winui->event.wheel.y = 0;
	}
}

static void	ed_edit_vel(t_win *win, t_map *map, const Uint8 *state, t_dot *pos)
{
	int				vel;
	static Uint32	l_ti = 0;
	Uint32			n_ti;

	n_ti = SDL_GetTicks();
	if (l_ti == 0 || n_ti - l_ti >= 200)
	{
		if (state[SDL_SCANCODE_TAB] && map->editor.selected)
		{
			l_ti = n_ti;
			ed_incre_selected(map->editor.list_selected, &map->editor.selected);
			ed_set_buttons_selected(win, map);
		}
	}
	vel = 3;
	if (state[SDL_SCANCODE_LSHIFT])
		vel += 4;
	if (state[SDL_SCANCODE_A])
		pos->x -= vel;
	if (state[SDL_SCANCODE_D])
		pos->x += vel;
	if (state[SDL_SCANCODE_W])
		pos->y -= vel;
	if (state[SDL_SCANCODE_S])
		pos->y += vel;
}

int			ed_event(t_win *win, t_map *map)
{
	const Uint8	*state;

	SDL_GetWindowSize(win->ptr, &win->w, &win->h);
	state = SDL_GetKeyboardState(NULL);
	if (map->player.pos.z != 0)
	{
		ed_move_player_z(map);
		map->player.pos.z = 0;
	}
	if (!win->winui->ui.clicked_button)
		ed_edit_vel(win, map, state, &map->editor.pos);
	if (state[SDL_SCANCODE_DELETE]
		&& map->editor.selected)
		ed_delete_event(win, map);
	ed_next_events(win, map, state);
	ed_action(win, map);
	return (1);
}
