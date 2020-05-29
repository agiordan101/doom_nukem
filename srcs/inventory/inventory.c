/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:58:32 by gal               #+#    #+#             */
/*   Updated: 2020/05/17 20:26:08 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_inventory	*define_inventory(void)
{
	t_inventory		*inventory;

	if (!(inventory = (t_inventory *)ft_memalloc(sizeof(t_inventory))))
		return (ret_null_error("inventory failed in define inventory"));
	return (inventory);
}

int			define_pos_slot(t_inventory *inventory, t_win *win)
{
	int		i;
	int		slotposx;

	i = 0;
	slotposx = 240;
	while (i < 5)
	{
		inventory->item[i] = (t_item *)ft_memalloc(sizeof(t_item));
		i++;
	}
	i = 0;
	while (i < 5)
	{
		inventory->item[i]->pos = &(SDL_Rect){(slotposx),
			(win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)};
		inventory->item[i]->nb = 0;
		slotposx += 80;
		i++;
	}
	return (0);
}

void		print_value_item(t_win *win, t_texhud *texhud, int nb, int slotposx)
{
	SDL_Texture		*text;
	char			*tmp;

	tmp = ft_strjoin(" X ", ft_itoa(nb));
	text = generate_text(win->rend, texhud->police, tmp,
		(SDL_Color){255, 255, 255, 50});
	SDL_RenderCopy(win->rend, text, NULL,\
					&(SDL_Rect){(slotposx + (win->w * 0.05)),\
					(win->h * 0.95), (win->w * 0.035), (win->h * 0.04375)});
	ft_strdel(&tmp);
}

void		print_content_slot(t_win *win, t_player *player, t_texhud *texhud)
{
	int i;
	int slotposx;

	i = -1;
	slotposx = win->w * 0.24;
	while (++i <= 4)
	{
		if (player->inventory->item[i]->nb != 0)
		{
			if (i == 0)
				print_items_s(win, texhud->tex[7], slotposx);
			if (i == 1)
				print_items_s(win, texhud->tex[8], slotposx);
			if (i == 2)
				print_items_s(win, texhud->tex[9], slotposx);
			if (i == 3)
				print_items_s(win, texhud->tex[15], slotposx);
			if (i == 4)
				print_items_s(win, texhud->tex[14], slotposx);
			print_value_item(win, texhud, player->inventory->item[i]->nb,
							slotposx);
		}
		slotposx += win->w * 0.08;
	}
}

void		main_inventory(t_win *win, t_player *player)
{
	define_pos_slot(player->inventory, win);
	player->inventory->weapon = 1;
	ft_putendl("inventory created");
}
