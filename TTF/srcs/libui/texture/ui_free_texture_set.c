/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_free_texture_set.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:36:12 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/28 16:49:24 by gal              ###   ########lyon.fr   */
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

void				ui_free_simple_set(t_simple_set simple_set)
{
	if (simple_set.normal)
		SDL_DestroyTexture(simple_set.normal);
	if (simple_set.clicked)
		SDL_DestroyTexture(simple_set.clicked);
	if (simple_set.on_mouse)
		SDL_DestroyTexture(simple_set.on_mouse);
}

void				ui_free_text_entry_set(t_text_entry_set text_entry_set)
{
	if (text_entry_set.name_side_texture)
		SDL_DestroyTexture(text_entry_set.name_side_texture);
	if (text_entry_set.normal_box_texture)
		SDL_DestroyTexture(text_entry_set.normal_box_texture);
	if (text_entry_set.writting_box_texture)
		SDL_DestroyTexture(text_entry_set.writting_box_texture);
}
