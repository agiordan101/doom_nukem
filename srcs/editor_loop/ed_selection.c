/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_selection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:28 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:30:45 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static int	ed_get_all_selected(t_win *win, t_map *map)
{
	ed_get_selected_mob(win, map);
	ed_get_selected_obj(win, map);
	ed_get_selected_poly(map, 0);
	ed_get_selected_player(win, map);
	return (0);
}

static void	ed_clean_selected(t_win *win, t_map *map)
{
	if (map->editor.list_selected)
		ed_free_selected(&map->editor.list_selected);
	ed_clean_property(win, 1);
	map->editor.selected = NULL;
}

static void	ed_end_selection(t_win *win, t_map *map)
{
	map->editor.select_rect.w = ed_get_map_x(map, win->winui->mouse.pos.x)
								- map->editor.select_rect.x;
	map->editor.select_rect.h = ed_get_map_y(map, win->winui->mouse.pos.y)
								- map->editor.select_rect.y;
	ed_get_all_selected(win, map);
	if (!map->editor.list_selected)
		ed_clean_selected(win, map);
	else
	{
		map->editor.selected = map->editor.list_selected;
		ed_set_buttons_selected(win, map);
	}
}

void		ed_set_buttons_selected(t_win *win, t_map *map)
{
	if (map->editor.selected->selected_type == SELECTED_TYPE_MOB)
		ed_set_buttons_mob(win, (t_mob*)map->editor.selected->ptr);
	else if (map->editor.selected->selected_type == SELECTED_TYPE_OBJECT)
		ed_set_buttons_object(win, (t_object*)map->editor.selected->ptr);
	else if (map->editor.selected->selected_type == SELECTED_TYPE_POLY)
	{
		if (ed_is_wall((t_poly*)map->editor.selected->ptr))
			ed_set_buttons_wall(win, (t_poly*)map->editor.selected->ptr);
		else if (ed_is_flat((t_poly*)map->editor.selected->ptr))
			ed_set_buttons_flat(win, (t_poly*)map->editor.selected->ptr);
		else if (ed_is_inclined((t_poly*)map->editor.selected->ptr))
			ed_set_buttons_inclined(win, (t_poly*)map->editor.selected->ptr);
	}
	else if (map->editor.selected->selected_type == SELECTED_TYPE_PLAYER)
		ed_set_buttons_player(win, (t_player*)map->editor.selected->ptr);
}

void		ed_selection(t_win *win, t_map *map)
{
	if (map->editor.list_selected)
	{
		ed_free_selected(&map->editor.list_selected);
		map->editor.selected = NULL;
	}
	if (win->winui->mouse.clicking & UI_MOUSE_LEFT
		|| win->winui->mouse.clicking & UI_MOUSE_RIGHT)
	{
		map->editor.select_rect.x = ed_get_map_x(map, win->winui->mouse.pos.x);
		map->editor.select_rect.y = ed_get_map_y(map, win->winui->mouse.pos.y);
		map->editor.select_rect.w = 0;
		map->editor.select_rect.h = 0;
	}
	else if (win->winui->mouse.clicked & UI_MOUSE_LEFT
			|| win->winui->mouse.clicked & UI_MOUSE_RIGHT)
		ed_end_selection(win, map);
}
