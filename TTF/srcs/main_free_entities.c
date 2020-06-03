/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_free_entities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:06:45 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 16:46:50 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		main_free_rays(t_cartesienne **rays)
{
	t_cartesienne	*l;
	t_cartesienne	*next;
	int				i;

	if (rays)
	{
		i = 0;
		while (rays[i])
		{
			l = rays[i];
			while (l)
			{
				next = l->next;
				free(l);
				l = next;
			}
			i++;
		}
	}
}

void		main_free_inventory(t_inventory *inventory)
{
	int i;

	if (!inventory)
		return ;
	i = 0;
	while (i < 5)
	{
		if (inventory->item[i])
			free(inventory->item[i]);
		i++;
	}
}

void		main_free_player(t_player *player)
{
	if (!player)
		return ;
	if (player->inventory)
	{
		main_free_inventory(player->inventory);
		free(player->inventory);
		player->inventory = NULL;
	}
	if (player->rays)
	{
		main_free_rays(player->rays);
		free(player->rays);
	}
}

void		main_free_polys(t_poly **polys)
{
	t_poly	*p;
	t_poly	*next;

	if (polys)
	{
		p = *polys;
		while (p)
		{
			next = p->next;
			free(p);
			p = next;
		}
		*polys = NULL;
	}
}
