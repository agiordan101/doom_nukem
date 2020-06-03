/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:36:20 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:17:28 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_texture.h"
#include "ui_error.h"
#include "libft.h"

TTF_Font		*ui_load_font(const char *file, int pixel_height)
{
	TTF_Font	*new_font;

	if (!(new_font = TTF_OpenFont(file, pixel_height)))
		return (ui_ret_null_error("ui_load_font", TTF_GetError(), NULL));
	return (new_font);
}

SDL_Texture		*ui_new_text(SDL_Renderer *rend,
								TTF_Font *font,
								const char *text,
								const SDL_Color *color)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	texture = NULL;
	if (text && ft_strlen(text) > 0)
	{
		if (!(surface = TTF_RenderText_Blended(font, text, *color)))
			return (ui_ret_null_error("ui_new_text [1]", TTF_GetError(), NULL));
		if (!(texture = SDL_CreateTextureFromSurface(rend, surface)))
			return (ui_ret_null_error("ui_new_text [2]", SDL_GetError(), NULL));
		SDL_FreeSurface(surface);
	}
	return (texture);
}

int				ui_get_text_width(TTF_Font *font, const char *text, int height)
{
	int		w;
	int		h;
	int		width;

	width = 0;
	if (text)
	{
		TTF_SizeText(font, text, &w, &h);
		if (h > 0)
			width = (w * height) / h;
	}
	return (width);
}

int				ui_get_x_alignment(t_rect rect,
									t_text_align aligment,
									int text_width)
{
	if (aligment & TEXT_ALIGN_CENTER)
		return (rect.x + rect.w / 2 - text_width / 2);
	else if (aligment & TEXT_ALIGN_RIGHT)
		return (rect.x + rect.w - text_width);
	else
		return (rect.x);
}
