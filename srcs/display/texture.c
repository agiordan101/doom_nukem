/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:03:14 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 16:05:10 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

SDL_Texture		*load_texture(SDL_Renderer *rend, const char *file)
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	if (!(surface = IMG_Load(file)))
		return (ret_null_error("failed to load surface in load_texture"));
	if (!(texture = SDL_CreateTextureFromSurface(rend, surface)))
	{
		return (
		ret_null_error(
		"failed to create texture from surface in load_texture"));
	}
	SDL_FreeSurface(surface);
	return (texture);
}
