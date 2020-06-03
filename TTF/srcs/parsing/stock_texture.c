/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:30:30 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:50:58 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

t_l_texture	*new_stock_texture(const char *id)
{
	t_l_texture *texture;

	if (!(texture = ft_memalloc(sizeof(t_l_texture))))
	{
		return (ui_ret_null_error("new_stock_texture",
									"allocation failed", NULL));
	}
	texture->id = ft_strdup(id);
	if (!(texture->surface = IMG_Load(id))
		|| !(texture->surface = SDL_ConvertSurfaceFormat(\
				texture->surface, SDL_PIXELFORMAT_ARGB8888, 0)))
		ui_ret_null_error("new_stock_texture", SDL_GetError(), NULL);
	texture->next = NULL;
	return (texture);
}

void		add_stock_texture(t_l_texture **textures,
								t_l_texture *t)
{
	if (t)
	{
		t->next = *textures;
		*textures = t;
	}
}

int			is_in_stock(t_l_texture *textures,
						t_l_texture *texture)
{
	t_l_texture *t;

	t = textures;
	while (t)
	{
		if (ft_strcmp(t->id, texture->id) == 0)
			return (1);
		t = t->next;
	}
	return (0);
}

int			is_id_in_stock(t_l_texture *textures,
						char *id)
{
	t_l_texture *t;

	t = textures;
	while (t)
	{
		if (ft_strcmp(t->id, id) == 0)
			return (1);
		t = t->next;
	}
	return (0);
}

SDL_Surface	*get_surface_from_stock(t_l_texture *textures, const char *id)
{
	t_l_texture *t;

	t = textures;
	while (t)
	{
		if (ft_strcmp(t->id, id) == 0)
			return (t->surface);
		t = t->next;
	}
	return (NULL);
}
