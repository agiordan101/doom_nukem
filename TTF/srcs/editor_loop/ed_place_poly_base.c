/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_place_poly_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:17 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 12:24:15 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

static int	ed_add_mob(t_win *win, t_map *map)
{
	t_mob	*mob;

	if (!(mob = ft_memalloc(sizeof(t_mob))))
		return (ui_ret_error("ed_add_mob", "mob allocation failed", 0));
	mob->pos.x = ed_get_map_x(map, win->winui->mouse.pos.x);
	mob->pos.y = ed_get_map_y(map, win->winui->mouse.pos.y);
	mob->pos.z = map->editor.settings.mob.z;
	mob->width = map->editor.settings.mob.width;
	mob->height = map->editor.settings.mob.height;
	mob->health = map->editor.settings.mob.health;
	mob->damage = map->editor.settings.mob.damage;
	mob->vel = map->editor.settings.mob.velocity;
	mob->agro_dist = 0;
	mob->light_coef = 1;
	mob->texture = ft_strdup(map->editor.settings.texture);
	add_existing_mob(&map->mob, mob);
	return (1);
}

static void	ed_place_flat_inclined(t_win *win, t_map *map, SDL_bool *call_place)
{
	if (win->winui->mouse.clicking & UI_MOUSE_LEFT
	|| (win->winui->mouse.releasing & UI_MOUSE_LEFT
	&& map->editor.place_step != 0))
		map->editor.place_step++;
	if (map->editor.place_step == 0
	&& win->winui->mouse.clicking & UI_MOUSE_LEFT)
		*call_place = 1;
	else if (map->editor.place_step == 1
	&& win->winui->mouse.clicked & UI_MOUSE_LEFT)
		*call_place = 1;
	else if (map->editor.place_step == 2)
		*call_place = 1;
	else if (map->editor.place_step == 3)
	{
		add_existing_poly(&map->polys, map->editor.placing_poly);
		map->editor.placing_poly = NULL;
		map->editor.place_step = 0;
	}
	if (*call_place)
	{
		if (map->editor.flags & ED_FLAT)
			ed_place_flat(win, map);
		else if (map->editor.flags & ED_INCLINED)
			ed_place_inclined(win, map);
	}
}

void		ed_place_poly_base(t_win *win, t_map *map)
{
	SDL_bool	call_place;

	call_place = SDL_FALSE;
	if (win->winui->mouse.releasing & UI_MOUSE_LEFT
		&& !(map->editor.flags & ED_FLAT)
		&& !(map->editor.flags & ED_INCLINED))
	{
		if (map->editor.flags & ED_MOB)
			ed_add_mob(win, map);
		else
		{
			add_existing_poly(&map->polys, map->editor.placing_poly);
			map->editor.placing_poly = NULL;
		}
	}
	else if (win->winui->mouse.clicked & UI_MOUSE_LEFT)
	{
		if (map->editor.flags & ED_WALL)
			ed_place_wall(win, map);
	}
	if (map->editor.flags & ED_FLAT || map->editor.flags & ED_INCLINED)
		ed_place_flat_inclined(win, map, &call_place);
}
