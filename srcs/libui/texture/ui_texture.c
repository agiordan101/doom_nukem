/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:17:34 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 16:49:21 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_texture.h"
# ifdef __linux__
#  include "SDL2/SDL.h"
#  include "SDL2/SDL_image.h"
# else
#  include "SDL.h"
#include "SDL_image.h"
# endif
#include "ui_error.h"

SDL_Texture			*ui_load_image(SDL_Renderer *rend, const char *file)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	if (!(surface = IMG_Load(file)))
	{
		return (ui_ret_null_error("ui_load_image IMG_Load",
				IMG_GetError(), NULL));
	}
	if (!(texture = SDL_CreateTextureFromSurface(rend, surface)))
		return (ui_ret_null_error("ui_load_image", SDL_GetError(), NULL));
	SDL_FreeSurface(surface);
	return (texture);
}

t_simple_set		ui_create_simple_set(SDL_Texture *normal,
										SDL_Texture *clicked,
										SDL_Texture *on_mouse)
{
	t_simple_set	simple_set;

	simple_set.normal = normal;
	simple_set.clicked = clicked;
	simple_set.on_mouse = on_mouse;
	simple_set.current = NULL;
	return (simple_set);
}

t_text_entry_set	ui_create_text_entry_set(SDL_Texture *name_side_texture,
											SDL_Texture *normal_box_texture,
											SDL_Texture *writting_box_texture)
{
	t_text_entry_set	text_entry_set;

	text_entry_set.name_side_texture = name_side_texture;
	text_entry_set.normal_box_texture = normal_box_texture;
	text_entry_set.writting_box_texture = writting_box_texture;
	text_entry_set.current_box_texture = NULL;
	return (text_entry_set);
}

void				ui_draw_texture(SDL_Renderer *rend,
								SDL_Texture *texture,
								const t_rect *src_rect,
								const t_rect *dst_rect)
{
	SDL_RenderCopy(rend, texture, (SDL_Rect*)src_rect, (SDL_Rect*)dst_rect);
}

void				ui_destroy_texture(SDL_Texture *texture)
{
	SDL_DestroyTexture(texture);
}
