/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_display_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:26 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 19:49:39 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_draw.h"

void	ed_display_player(t_win *win, const t_map *map)
{
	t_dot		pos;

	pos = ed_get_display_point(map,
							(t_dot){map->player.pos.x,
									map->player.pos.y});
	ui_set_draw_color(win->winui->rend,
					&(SDL_Color){225, 100, 100, 255});
	draw_circle(win, (t_circle){pos.x,
								pos.y,
								map->player.width * map->editor.unit / 2});
}
