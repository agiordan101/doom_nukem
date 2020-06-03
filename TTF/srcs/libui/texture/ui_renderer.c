/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_renderer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:36:16 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:17:24 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_texture.h"

void				ui_set_rend_target(SDL_Renderer *rend, SDL_Texture *texture)
{
	SDL_SetRenderTarget(rend, texture);
}
