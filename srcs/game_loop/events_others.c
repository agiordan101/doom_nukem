/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_others.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:10:18 by gal               #+#    #+#             */
/*   Updated: 2020/05/20 13:55:52 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			events_rotate(t_win *win, t_map *map,\
								t_player *player, const Uint8 *state)
{
	int xrel;
	int yrel;

	xrel = win->winui->mouse.pos.x;
	yrel = win->winui->mouse.pos.y;
	if (xrel)
	{
		if (xrel > 0)
			rotate_all_rotz_only(map, map->polys,\
							create_rz_matrix(ft_abs((float)xrel) * SENSITIVE));
		if (xrel < 0)
			rotate_all_rotz_only(map, map->polys,\
							create_rz_matrix(-ft_abs((float)xrel) * SENSITIVE));
	}
	if (yrel)
		player->rot_y -= SENSITIVE * yrel;
	if (state[SDL_SCANCODE_RIGHT])
		rotate_all_rotz_only(map, map->polys, player->rz);
	if (state[SDL_SCANCODE_LEFT])
		rotate_all_rotz_only(map, map->polys, player->rz_inv);
	if (state[SDL_SCANCODE_UP] && player->rot_y < M_PI_2)
		player->rot_y += SENSITIVE;
	if (state[SDL_SCANCODE_DOWN] && player->rot_y > -M_PI_2)
		player->rot_y -= SENSITIVE;
}

void			events_others(t_win *win, t_player *player, const Uint8 *state)
{
	if (state[SDL_SCANCODE_KP_MINUS])
		player->fov += -0.03 + (player->fov - 0.03 < 0 ? _2_PI : 0);
	if (state[SDL_SCANCODE_KP_PLUS])
		player->fov += 0.03 - (player->fov + 0.03 > _2_PI ? _2_PI : 0);
	if (state[SDL_SCANCODE_1] && test_timer_refresh(&(win->view_change_time)))
		win->map->view += (win->map->view & TEXTURE_VIEW ?\
												-TEXTURE_VIEW : TEXTURE_VIEW);
	if (state[SDL_SCANCODE_2] && test_timer_refresh(&(win->view_change_time)))
		win->map->view += (win->map->view & WALL_VIEW ? -WALL_VIEW : WALL_VIEW);
	if (state[SDL_SCANCODE_3] && test_timer_refresh(&(win->view_change_time)))
		win->map->view += (win->map->view & BOX_VIEW ? -BOX_VIEW : BOX_VIEW);
	if (state[SDL_SCANCODE_4] && test_timer_refresh(&(win->view_change_time)))
		win->map->view += (win->map->view & LIGHT_VIEW ?\
													-LIGHT_VIEW : LIGHT_VIEW);
	if (state[SDL_SCANCODE_C])
		player->collision_on = player->collision_on ? 0 : 1;
	if (state[SDL_SCANCODE_F] && test_timer_refresh(&(player->fly_timer)))
		player->fly = player->fly ? 0 : 1;
}
