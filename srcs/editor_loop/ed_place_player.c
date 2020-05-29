/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_place_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:14 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:22:15 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		ed_translate_pos(t_fdot_3d *pos, t_dot player_pos)
{
	pos->x -= player_pos.x;
	pos->y -= player_pos.y;
}

static void		ed_translate_polys(t_poly *poly, t_dot player_pos)
{
	t_poly		*p;
	int			i;

	p = poly;
	while (p)
	{
		i = -1;
		while (++i < 4)
			ed_translate_pos(&p->dots[i], player_pos);
		p = p->next;
	}
}

void			ed_place_player(t_win *win, t_map *map)
{
	t_object	*obj;
	t_mob		*mob;
	t_dot		player_pos;

	if (win->winui->mouse.releasing & UI_MOUSE_LEFT)
	{
		player_pos = ed_get_map_point(map, win->winui->mouse.pos);
		ed_translate_polys(map->polys, player_pos);
		obj = map->objects;
		while (obj)
		{
			ed_translate_pos(&obj->pos_rotz_only, player_pos);
			obj = obj->next;
		}
		mob = map->mob;
		while (mob)
		{
			ed_translate_pos(&mob->pos, player_pos);
			mob = mob->next;
		}
		map->editor.pos.x -= player_pos.x;
		map->editor.pos.y -= player_pos.y;
	}
}
