/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_display_list_selected.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:31:00 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:41:32 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_draw.h"

void	ed_display_list_selected(t_win *win, const t_map *map)
{
	t_selected	*l;

	l = map->editor.list_selected;
	while (l)
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 100, 255, 255});
		if (l->selected_type == SELECTED_TYPE_MOB)
			ed_display_mob(win, map, (t_mob*)l->ptr);
		else if (l->selected_type == SELECTED_TYPE_OBJECT)
			ed_display_object(win, map, (t_object*)l->ptr);
		else if (l->selected_type == SELECTED_TYPE_POLY)
			ed_display_poly(win, map, (t_poly*)l->ptr);
		l = l->next;
	}
}
