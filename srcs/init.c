/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 00:06:08 by gal               #+#    #+#             */
/*   Updated: 2020/06/02 19:13:10 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

static void		init_player_hud(t_player *player)
{
	player->inventory = define_inventory();
	player->max_hp = 100;
	player->current_hp = player->max_hp;
	player->max_armor = 100;
	player->current_armor = player->max_armor;
	player->inventory->ammo = 15;
	player->inventory->magazine = 120;
	start_cooldown(&(player->timers.bullet_cd), 130);
	start_cooldown(&(player->timers.item_cd), 100);
	start_cooldown(&(player->timers.text_cd), 600);
	start_cooldown(&(player->timers.reload_cd), 600);
	start_cooldown(&(player->timers.animation_cd), 1000);
	start_cooldown(&(player->timers.shot_cd), 50);
	start_cooldown(&(player->timers.animation_shot_cd), 10);
	start_cooldown(&(player->timers.mouse), 10);
	player->timers.reload_cd.index = 5;
	player->timers.bullet_cd.index = 5;
	player->timers.bullet_cd.index = 0;
}

int				init_win_player(t_win *win, t_player *player)
{
	if (!(win->pixels = (Uint32 *)malloc(sizeof(Uint32) * win->w * win->h)))
		return (1);
	start_cooldown(&(win->view_change_time), 250);
	start_cooldown(&(win->map->objects_animation), 20);
	start_cooldown(&(win->map->objects_tp_timer), 2000);
	start_cooldown(&(player->interaction_inventaire_time), 250);
	start_cooldown(&(player->fly_timer), 250);
	init_player_maths(win, player);
	init_player_hud(player);
	return (0);
}

int				init_music_timer(t_doom_music *music)
{
	if (music)
	{
		if (!(music->editor_music = Mix_LoadMUS("sounds/map_editor.wav")))
			return (ui_ret_error("init_music_timer", SDL_GetError(), 0));
		if (!(music->credit_music = Mix_LoadMUS("sounds/Remember_chill.mp3")))
			return (ui_ret_error("init_music_timer", SDL_GetError(), 0));
		if (!(music->menu_music = Mix_LoadMUS("sounds/doomMenu.wav")))
			return (ui_ret_error("init_music_timer", SDL_GetError(), 0));
	}
	return (1);
}
