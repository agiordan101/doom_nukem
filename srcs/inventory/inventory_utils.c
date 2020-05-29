/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventory_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:58:29 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 16:58:29 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		print_items_s(t_win *win, SDL_Texture *tex, int slotposx)
{
	SDL_RenderCopy(win->rend, tex, NULL, &(SDL_Rect){(slotposx),
		(win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)});
}
