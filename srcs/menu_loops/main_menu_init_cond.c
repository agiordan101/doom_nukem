/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu_init_cond.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:12:00 by gal               #+#    #+#             */
/*   Updated: 2020/05/20 14:11:41 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"
#include "ui.h"

int				init_main_menu(t_win *win)
{
	if (Mix_PlayMusic(win->music.menu_music, -1) == -1)
		ui_ret_error("init_editor_menu", "impossible to play menu_music", 0);
	Mix_VolumeMusic(30);
	if (!(win->winui->ui.button_font = ui_load_font("TTF/DooM.ttf", 100)))
		return (ui_ret_error("init_main_menu", "ui_load_font failed", 0));
	if (!ui_load("interfaces/menu_interface", win->winui))
		return (ui_ret_error("init_main_menu", "ui_load failed", 0));
	SDL_SetRelativeMouseMode(SDL_FALSE);
	return (1);
}

void			condition_loop(t_win *win, t_map *map,
							int *next_loop, int *f_set)
{
	if (win->winui->event.type == SDL_QUIT)
		*next_loop = 0;
	else if (*next_loop != 1)
	{
		*f_set = 0;
		main_menu_quit(win, 100);
		if (*next_loop == 2)
			game_loop(win, map);
		else if (*next_loop == 3)
		{
			editor_loop(win, map);
			*next_loop = 0;
		}
		else if (*next_loop == 4)
			print_credit(win);
	}
}
