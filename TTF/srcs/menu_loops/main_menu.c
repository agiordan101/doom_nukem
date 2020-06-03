/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:03:33 by gal               #+#    #+#             */
/*   Updated: 2020/05/17 22:47:58 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_win.h"
#include "ui.h"
#include "ui_draw.h"
#include "ui_error.h"

void			main_menu_quit(t_win *win, Uint32 ms)
{
	Mix_FadeOutMusic(ms);
	ui_free_ui(&win->winui->ui);
	SDL_Delay(ms);
}

static void		menu_change_loop(void *argument)
{
	t_arg_menu	*arg_menu;

	arg_menu = (t_arg_menu*)argument;
	*(arg_menu->loop) = arg_menu->value;
}

static void		set_menu_button_function(t_winui *winui,
							t_map *map, int *next_loop)
{
	map->editor.arg_menu_tab[0] = (t_arg_menu){next_loop,
											2};
	map->editor.arg_menu_tab[1] = (t_arg_menu){next_loop,
											3};
	map->editor.arg_menu_tab[2] = (t_arg_menu){next_loop,
											4};
	map->editor.arg_menu_tab[3] = (t_arg_menu){next_loop,
											0};
	ui_set_simple_button_function(winui,
									"b_play",
									&menu_change_loop,
									&map->editor.arg_menu_tab[0]);
	ui_set_simple_button_function(winui,
									"b_map_editor",
									&menu_change_loop,
									&map->editor.arg_menu_tab[1]);
	ui_set_simple_button_function(winui,
									"b_credit",
									&menu_change_loop,
									&map->editor.arg_menu_tab[2]);
	ui_set_simple_button_function(winui,
									"b_exit",
									&menu_change_loop,
									&map->editor.arg_menu_tab[3]);
}

static void		main_menu_ui(t_win *win)
{
	ui_set_draw_color(win->rend, &(SDL_Color){71, 27, 27, 255});
	ui_clear_win(win->winui);
	ui_display_frames(win->winui, win->winui->ui.frames);
	ui_draw_rend(win->winui);
	ui_wait_event(&win->winui->event);
	ui_update_ui(win->winui);
}

int				main_menu(t_win *win, t_map *map, char *arg)
{
	int			next_loop;
	int			f_set;

	map->editor.export.path = ft_strdup(arg);
	next_loop = 1;
	f_set = 0;
	if (!init_main_menu(win))
		return (ui_ret_error("main_menu", "init_main_menu failed", 0));
	while (next_loop)
	{
		next_loop = 1;
		if (!f_set)
		{
			set_menu_button_function(win->winui, map, &next_loop);
			f_set = 1;
		}
		main_menu_ui(win);
		condition_loop(win, map, &next_loop, &f_set);
	}
	main_menu_quit(win, 500);
	return (next_loop);
}
