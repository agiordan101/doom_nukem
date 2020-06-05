/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:47:53 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/26 22:11:46 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		events_reload(t_win *win,
								t_map *map,
								t_player *player,
								const Uint8 *state)
{
	char		*tmp;
	SDL_Texture	*text;

	if (state[SDL_SCANCODE_R])
	{
		if (player->inventory->magazine <= 0)
		{
			tmp = ft_strdup("NO AMMO LEFT");
			text = generate_text(win->rend, win->texhud->police,
									tmp, (SDL_Color){200, 0, 2, 40});
			free(tmp);
			SDL_RenderCopy(win->rend, text, NULL,
							&(SDL_Rect){(win->w * 0.05), (win->h * 0.8125),
										(win->w * 0.25), (win->h * 0.0625)});
		}
		else if (player->inventory->weapon == 1 && player->inventory->ammo < 30)
		{
			player->inventory->weapon = 2;
			player->timers.reload_cd.index = 0;
			Mix_PlayChannel(3, map->music->tmusic[1], 0);
			reload_ammo(player);
		}
	}
}

static void		events_shoot(t_win *win,
								t_map *map,
								t_player *player)
{
	char		*tmp;
	SDL_Texture	*text;

	if (SDL_GetMouseState(NULL, NULL) && SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if (player->inventory->ammo == 0)
		{
			tmp = ft_strdup("EMPTY AMMO PRESS 'R' ");
			text = generate_text(win->rend, win->texhud->police,
									tmp, (SDL_Color){200, 0, 2, 40});
			free(tmp);
			SDL_RenderCopy(win->rend, text, NULL,
							&(SDL_Rect){(win->w * 0.33), (win->h * 0.8125),
							(win->w * 0.28), (win->h * 0.0625)});
		}
		if (test_timer_refresh(&(player->timers.bullet_cd)) == 1 &&\
			player->inventory->ammo > 0 && player->inventory->weapon == 1)
		{
			player->timers.bullet_cd.index = 0;
			Mix_PlayChannel(2, map->music->tmusic[0], 0);
			player->inventory->ammo -= 1;
			add_bullet(player);
			hit_mobs(map->mob, 10);
		}
	}
}

static void		events_weapon(t_win *win,
								t_map *map,
								t_player *player,
								const Uint8 *state)
{
	if (map->event->type == SDL_MOUSEWHEEL)
	{
		player->inventory->selected_slot -= map->event->wheel.y;
		if (player->inventory->selected_slot < 0)
			player->inventory->selected_slot = 0;
		else if (player->inventory->selected_slot > 4)
			player->inventory->selected_slot = 4;
		if (map->event->wheel.y)
			Mix_PlayChannel(1, map->music->tmusic[4], 0);
		map->event->wheel.y = 0;
	}
	events_reload(win, map, player, state);
	events_shoot(win, map, player);
}

t_fdot_3d		events_move(t_map *map, t_player *player, const Uint8 *state)
{
	t_fdot_3d	move;

	move = (t_fdot_3d){0, 0, 0};
	player->sprint = state[SDL_SCANCODE_LSHIFT] ? 2 : 1;
	if (state[SDL_SCANCODE_W])
		move = fdot_3d_add(move,\
						(t_fdot_3d){-player->const_vel * player->sprint, 0, 0});
	if (state[SDL_SCANCODE_S])
	{
		move = fdot_3d_add(move,\
						(t_fdot_3d){player->const_vel * player->sprint, 0, 0});
	}
	if (state[SDL_SCANCODE_D])
		move = fdot_3d_add(move,\
						(t_fdot_3d){0, -player->const_vel * player->sprint, 0});
	if (state[SDL_SCANCODE_A])
		move = fdot_3d_add(move,\
						(t_fdot_3d){0, player->const_vel * player->sprint, 0});
	if (state[SDL_SCANCODE_SPACE] &&\
		(player->fly || is_null(map->last_move.z, 0.25)))
		player->jump = -0.5 - map->gravity - sqrt(0.24 + map->gravity *\
						(map->gravity + 1) + player->height);
	map->last_move = (t_fdot_3d){0, 0, 0};
	player->sneak = state[SDL_SCANCODE_LCTRL] ? 1 : 0;
	return (move);
}

void			events_actions(t_win *win, t_map *map,\
								t_player *player, const Uint8 *state)
{
	events_weapon(win, map, player, state);
	if (state[SDL_SCANCODE_I])
		player->inventory->item[0]->nb += 1;
	if (state[SDL_SCANCODE_O])
		player->inventory->item[1]->nb += 1;
	if (state[SDL_SCANCODE_P])
	{
		player->inventory->item[0]->nb += 1;
		player->inventory->item[1]->nb += 1;
		player->inventory->item[2]->nb += 1;
		player->inventory->item[3]->nb += 1;
		player->inventory->item[4]->nb += 1;
	}
	if (state[SDL_SCANCODE_E] &&\
		test_timer_refresh(&(player->interaction_inventaire_time)) == 1)
		use_item(map, player, map->music, player->inventory->selected_slot);
	else
		player->interaction_inventaire = 0;
	if (state[SDL_SCANCODE_L])
		apply_damage(map, player, 5);
}
