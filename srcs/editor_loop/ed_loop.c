/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:21:30 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:36:15 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui.h"
#include "ui_draw.h"
#include "ui_error.h"

static void		editor_menu_quit(t_win *win, t_map *map, Uint32 ms)
{
	Mix_FadeOutMusic(ms);
	ui_free_ui(&win->winui->ui);
	SDL_SetCursor(map->editor.cursor[CURSOR_DEFAULT]);
	SDL_Delay(ms);
}

static void		editor_menu_disp(t_win *win, t_map *map)
{
	map->editor.min_pos_z = ed_get_z_min(map->polys);
	map->editor.max_pos_z = ed_get_z_max(map->polys);
	ui_set_draw_color(win->rend, &(SDL_Color){30, 30, 30, 255});
	ui_clear_win(win->winui);
	ed_display(win, map);
	ui_display_frames(win->winui, win->winui->ui.frames);
	ui_draw_rend(win->winui);
	ui_poll_event(&win->winui->event);
	ui_update_ui(win->winui);
}

int				init_editor_menu(t_win *win, t_map *map)
{
	t_text_entry_button	*b;

	if (Mix_PlayMusic(win->music.editor_music, -1) == -1)
		ui_ret_error("init_editor_menu", "impossible to play menu_music", 0);
	if (!(win->winui->ui.button_font = ui_load_font("TTF/arial.ttf", 100)))
		return (ui_ret_error("init_editor_menu", "ui_load_font failed", 0));
	if (!ui_load("interfaces/editor_interface", win->winui))
		return (ui_ret_error("init_editor_menu", "ui_load failed", 0));
	b = ui_get_text_entry_button(win->winui, "b_export_path");
	ft_strcpy(b->text, map->editor.export.path);
	ed_set_menu_button_function(win, map);
	SDL_SetRelativeMouseMode(SDL_FALSE);
	return (1);
}

static void		ed_body_loop(t_win *win, t_map *map, SDL_bool *loop)
{
	Uint32				end;
	Uint32				start;

	start = SDL_GetTicks();
	editor_menu_disp(win, map);
	if (win->winui->event.type == SDL_QUIT ||
			win->winui->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		*loop = 0;
	ed_event(win, map);
	end = SDL_GetTicks();
	if (end - start < 1000 / 60)
		SDL_Delay(1000 / 60 - (end - start));
}

int				editor_loop(t_win *win, t_map *map)
{
	SDL_bool			loop;

	if (!map->editor.export.path)
		map->editor.export.path = ft_strdup("./maps/new_map");
	if (!init_editor_menu(win, map))
		return (ui_ret_error("editor_loop", "init_editor_menu failed", 0));
	ed_init_map_editor(win, map);
	loop = SDL_TRUE;
	while (loop)
		ed_body_loop(win, map, &loop);
	editor_menu_quit(win, map, 500);
	if (map->editor.export.path)
		ft_strdel(&map->editor.export.path);
	init_main_menu(win);
	return (1);
}
