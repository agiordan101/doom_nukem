/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:54:34 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:54:36 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui.h"
#include "ui_error.h"
#include "libft.h"

void			win_menu_ui(t_win *win)
{
	ui_set_draw_color(win->rend, &(SDL_Color){71, 27, 27, 255});
	ui_clear_win(win->winui);
	ui_display_frames(win->winui, win->winui->ui.frames);
	ui_draw_rend(win->winui);
	ui_poll_event(&win->winui->event);
	ui_update_ui(win->winui);
}

static void		win_change_loop(void *argument)
{
	t_arg_menu	*arg_menu;

	arg_menu = (t_arg_menu*)argument;
	*(arg_menu->loop) = arg_menu->value;
}

static void		set_menu_button_function(t_winui *winui, int *next_loop)
{
	ui_set_simple_button_function(winui,
									"b_exit",
									&win_change_loop,
									&(t_arg_menu){next_loop, 2});
}

int				init_win_menu(t_win *win)
{
	if (!(win->winui->ui.button_font = ui_load_font("TTF/DooM.ttf", 100)))
		return (0);
	if (!ui_load("interfaces/menu_win", win->winui))
		return (0);
	SDL_SetRelativeMouseMode(SDL_FALSE);
	return (1);
}

int				win_menu(t_win *win, t_player *player)
{
	int next_loop;
	int flag;

	flag = 0;
	next_loop = 0;
	if (init_win_menu(win) == 0)
		return (ret_error("win_menu"));
	if (player->current_hp <= 0)
	{
		while (!next_loop)
		{
			if (!flag)
			{
				set_menu_button_function(win->winui, &next_loop);
				flag = 1;
			}
			win_menu_ui(win);
			if (next_loop != 0)
			{
				main_menu_quit(win, 250);
				return (next_loop);
			}
		}
	}
	return (0);
}
