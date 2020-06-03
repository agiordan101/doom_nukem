/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:55:48 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 16:02:07 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

SDL_Texture		*generate_text(SDL_Renderer *rend, TTF_Font *font,
								const char *text, SDL_Color fg)
{
	SDL_Surface		*tmp;
	SDL_Texture		*texture;

	if (!(tmp = TTF_RenderText_Solid(font, text, fg)))
		return (ret_null_error("tmp allocation failed in generate_text"));
	if (!(texture = SDL_CreateTextureFromSurface(rend, tmp)))
		return (ret_null_error("texture allocation failed in generate text"));
	SDL_FreeSurface(tmp);
	return (texture);
}

SDL_Texture		*create_bg_text_input(t_win *win, SDL_Rect rect,
								SDL_Color l_color, SDL_Color r_color)
{
	SDL_Texture		*texture;

	if (!(texture = SDL_CreateTexture(win->rend,
	SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, rect.w, rect.h)))
	{
		return (
	ret_null_error("texture allocation failedin create_bg_text_input"));
	}
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(win->rend, texture);
	SDL_SetRenderDrawColor(win->rend, l_color.r,
		l_color.g, l_color.b, l_color.a);
	fill_rect(win, (SDL_Rect){0, 0, rect.x, rect.h});
	SDL_SetRenderDrawColor(win->rend, r_color.r,
		r_color.g, r_color.b, r_color.a);
	fill_rect(win, (SDL_Rect){rect.x, 0, rect.w - rect.x, rect.h});
	SDL_SetRenderTarget(win->rend, NULL);
	return (texture);
}

SDL_Texture		*blit_text(SDL_Renderer *rend,
						SDL_Texture *bg_texture,
						SDL_Texture *text, SDL_Rect *text_rect)
{
	SDL_Texture		*t;
	t_size			s;

	SDL_QueryTexture(bg_texture, NULL, NULL, &s.w, &s.h);
	if (!(t = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA32,
				SDL_TEXTUREACCESS_TARGET, s.w, s.h)))
		return (ret_null_error("t allocation failed in blit text"));
	SDL_SetRenderTarget(rend, t);
	SDL_RenderCopy(rend, bg_texture, NULL, &(SDL_Rect){0, 0, s.w, s.h});
	SDL_RenderCopy(rend, text, NULL, text_rect);
	SDL_SetRenderTarget(rend, NULL);
	return (t);
}
