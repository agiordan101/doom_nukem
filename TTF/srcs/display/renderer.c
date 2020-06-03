/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:18:00 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 16:18:01 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	clear_rend(SDL_Renderer *rend, Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetRenderDrawColor(rend, r, g, b, 255);
	SDL_RenderClear(rend);
}
