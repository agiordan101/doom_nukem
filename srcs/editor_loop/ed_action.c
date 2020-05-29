/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:19:58 by gal               #+#    #+#             */
/*   Updated: 2020/05/19 08:47:17 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

void	ed_action(t_win *win, t_map *map)
{
	if ((win->winui->mouse.clicked & UI_MOUSE_RIGHT
		|| map->editor.flags & ED_SELECTION) && !win->winui->ui.on_mouse_button)
		ed_selection(win, map);
	else if (map->editor.flags & ED_PLAYER && !win->winui->ui.on_mouse_button)
		ed_place_player(win, map);
	else if (map->editor.flags & ED_DOOR && !win->winui->ui.on_mouse_button)
		ed_place_door_event(win, map);
	else if ((map->editor.flags & ED_HEAL ||
				map->editor.flags & ED_SHIELD ||
				map->editor.flags & ED_GRAVITY ||
				map->editor.flags & ED_BULLET ||
				map->editor.flags & ED_BOX ||
				map->editor.flags & ED_LIGHT ||
				map->editor.flags & ED_END) && !win->winui->ui.on_mouse_button)
		ed_place_item(win, map);
	else if (map->editor.flags & ED_PLACE && !win->winui->ui.on_mouse_button)
		ed_place_poly_base(win, map);
	if (map->editor.flags & ED_MODE_CHANGED)
	{
		map->editor.flags ^= ED_MODE_CHANGED;
		if (map->editor.flags & ED_SELECTION || map->editor.flags & ED_PLACE)
			SDL_SetCursor(map->editor.cursor[CURSOR_SELECTING]);
		else
			SDL_SetCursor(map->editor.cursor[CURSOR_DEFAULT]);
	}
}
