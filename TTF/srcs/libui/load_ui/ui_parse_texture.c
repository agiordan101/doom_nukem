/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_parse_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:35:28 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/18 11:22:43 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

SDL_Texture		*get_texture_ptr(t_texture *textures, const char *id)
{
	t_texture	*t;

	t = textures;
	while (t)
	{
		if (ft_strcmp(t->id, id) == 0)
			return (t->sdl_ptr);
		t = t->next;
	}
	return (NULL);
}

SDL_Texture		*parse_texture(SDL_Renderer *rend,
								t_texture **textures,
								const char *expected_name,
								char *line)
{
	char		*path;
	SDL_Texture	*texture;

	if (!check_line_name(line, expected_name) || !(path = parse_str(line)))
	{
		return (ui_ret_null_error("parse_texture", "\"<?> : \
		<path>\" expected", NULL));
	}
	if ((texture = get_texture_ptr(*textures, path)))
	{
		ft_strdel(&path);
		return (texture);
	}
	if (!(texture = ui_load_image(rend, path)))
	{
		ft_strdel(&path);
		return (ui_ret_null_error("parse_texture",
		"ui_load_image failed", NULL));
	}
	add_texture(textures, new_texture(path, texture));
	ft_strdel(&path);
	return (texture);
}

void			ui_free_texture(t_texture **texture)
{
	t_texture	*t;

	t = *texture;
	if (t)
	{
		if (t->id)
			ft_strdel(&t->id);
		if (t->sdl_ptr)
			SDL_DestroyTexture(t->sdl_ptr);
		t->next = NULL;
		free(t);
	}
	*texture = NULL;
}

void			ui_free_textures(t_texture **textures)
{
	t_texture	*t;
	t_texture	*next;

	t = *textures;
	while (t)
	{
		next = t->next;
		ui_free_texture(&t);
		t = next;
	}
	*textures = NULL;
}
