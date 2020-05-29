/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stock_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 14:18:07 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:50:34 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	free_stock_texture(t_l_texture **stock)
{
	t_l_texture	*l;
	t_l_texture	*next;

	l = *stock;
	while (l)
	{
		next = l->next;
		if (l->id)
			ft_strdel(&l->id);
		if (l->surface)
		{
			SDL_FreeSurface(l->surface);
			l->surface = NULL;
		}
		free(l);
		l = next;
	}
	*stock = NULL;
}
