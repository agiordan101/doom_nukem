/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:06:45 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 18:10:13 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		main_free_music(t_music *music)
{
	int			i;

	i = -1;
	while (++i < 7)
		if (music->tmusic[i])
			Mix_FreeChunk(music->tmusic[i]);
}

static void		main_free_map(t_map *map)
{
	if (map)
	{
		main_free_player(&map->player);
		if (map->editor.export.path)
			ft_strdel(&map->editor.export.path);
		if (map->editor.settings.texture)
			ft_strdel(&map->editor.settings.texture);
		if (map->polys_save)
			main_free_polys(&map->polys_save);
		if (map->music)
		{
			main_free_music(map->music);
			free(map->music);
			map->music = NULL;
		}
		ed_delete_map(map);
	}
}

static void		main_free_texthud(t_texhud *texhud)
{
	int i;

	i = 0;
	while (i < 16)
		SDL_DestroyTexture(texhud->tex[i++]);
	i = 0;
	while (i < 6)
		SDL_DestroyTexture(texhud->tex_weapon[i++]);
	i = 0;
	while (i < 5)
		SDL_DestroyTexture(texhud->tex_reload[i++]);
	if (texhud->police)
		TTF_CloseFont(texhud->police);
}

static void		main_free_win(t_win *win)
{
	if (win)
	{
		if (win->pixels)
			free(win->pixels);
		if (win->texhud)
		{
			main_free_texthud(win->texhud);
			free(win->texhud);
		}
		if (win->threads)
			free(win->threads);
	}
}

void			main_free(t_win *win, t_map *map)
{
	free_stock_texture(&map->texture_stock);
	if (map->editor.list_selected)
		ed_free_selected(&map->editor.list_selected);
	ui_free_win(&(win->winui));
	main_free_win(win);
	main_free_map(map);
	SDL_DestroyWindow(win->ptr);
	SDL_DestroyRenderer(win->rend);
	SDL_Quit();
}
