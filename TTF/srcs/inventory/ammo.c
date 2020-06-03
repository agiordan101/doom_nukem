/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:58:24 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 16:58:24 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	all_reload(t_player *player)
{
	int nb;

	nb = 15 - player->inventory->ammo;
	if (player->inventory->magazine - nb > 0)
	{
		player->inventory->magazine -= nb;
		player->inventory->ammo += nb;
	}
	else
	{
		player->inventory->ammo += player->inventory->magazine;
		player->inventory->magazine = 0;
	}
}

void	reload_ammo(t_player *player)
{
	all_reload(player);
}
