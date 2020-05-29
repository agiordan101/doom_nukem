/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:33:44 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:15:03 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_draw.h"

void	ui_set_draw_color(SDL_Renderer *rend, const SDL_Color *color)
{
	SDL_SetRenderDrawColor(rend, color->r, color->g, color->b, color->a);
}
