/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_game_loop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 11:07:01 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 16:47:42 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	events_game_loop(t_win *win, t_map *map, t_player *player,\
						SDL_Event *event)
{
	const Uint8	*state;

	SDL_GetWindowSize(win->ptr, &win->w, &win->h);
	while (SDL_PollEvent(event))
		;
	map->event = event;
	SDL_GetRelativeMouseState(&(win->winui->mouse.pos.x),\
			&(win->winui->mouse.pos.y));
	state = SDL_GetKeyboardState(NULL);
	events_rotate(win, map, player, state);
	events_others(win, player, state);
	move_and_collide(map, player, events_move(map, player, state));
	move_and_collide(map, player, (t_fdot_3d){0, 0,\
												map->gravity + player->jump});
	if (player->jump < 0)
		player->jump++;
	mobs_attack_move(map, player, map->mob);
	events_actions(win, map, player, state);
}
