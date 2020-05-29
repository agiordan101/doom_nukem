/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:15:30 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/11 11:06:08 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		apply_damage(t_map *map, t_player *player, int damage)
{
	Mix_PlayChannel(4, map->music->tmusic[5], 0);
	player->current_armor -= damage;
	if (player->current_armor < 0)
	{
		player->current_hp += player->current_armor;
		player->current_armor = 0;
	}
}

void		apply_heal(t_player *player, int heal)
{
	player->current_hp += heal;
	if (player->current_hp > 100)
		player->current_hp = 100;
}

void		apply_armor(t_player *player, int armor)
{
	player->current_armor += armor;
	if (player->current_armor > 100)
		player->current_armor = 100;
}

static void	use_item_cut(t_map *map, t_player *player, int slot_selected)
{
	if (slot_selected == 2 && player->inventory->item[2]->nb > 0)
		player->inventory->item[2]->nb -= 1;
	else if (slot_selected == 3 && player->inventory->item[3]->nb > 0)
	{
		player->inventory->item[3]->nb -= 1;
		player->inventory->magazine += 20;
	}
	else if (slot_selected == 4 && player->inventory->item[4]->nb > 0)
	{
		player->inventory->item[4]->nb -= 1;
		drop_box(map, player);
	}
	else
		player->interaction_inventaire = 1;
}

void		use_item(t_map *map, t_player *player,
			t_music *music, int slot_selected)
{
	if (slot_selected == 0 && player->inventory->item[0]->nb > 0)
	{
		player->inventory->item[0]->nb -= 1;
		Mix_PlayChannel(4, music->tmusic[2], 0);
		apply_heal(player, 15);
	}
	else if (slot_selected == 1 && player->inventory->item[1]->nb > 0)
	{
		player->inventory->item[1]->nb -= 1;
		Mix_PlayChannel(5, music->tmusic[3], 0);
		apply_armor(player, 15);
	}
	else
		use_item_cut(map, player, slot_selected);
}
