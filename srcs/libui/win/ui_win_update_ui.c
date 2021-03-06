/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_update_ui.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:18:48 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:18:49 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "libft.h"

static void		ui_event_cursor(t_winui *win,
								Uint32 *last_tick,
								Uint32 *new_tick)
{
	if (win->ui.cursor_position > 0)
		win->ui.cursor_position--;
	*last_tick = *new_tick;
}

static void		ui_event(t_winui *win)
{
	static Uint32	last_tick = 0;
	Uint32			new_tick;

	new_tick = SDL_GetTicks();
	ui_event_update_mouse(&win->mouse);
	if (last_tick == 0 || new_tick - last_tick >= win->ui.delay_text_entry)
	{
		if (win->event.type == SDL_KEYDOWN)
		{
			if (win->ui.clicked_button
			&& win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
			{
				if (win->event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					ui_event_cursor(win, &last_tick, &new_tick);
				if (win->event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
				{
					if (win->ui.cursor_position < (int)ft_strlen((
				(t_text_entry_button*)win->ui.clicked_button->data)->new_text))
						win->ui.cursor_position++;
					last_tick = new_tick;
				}
			}
		}
	}
}

void			ui_update_ui(t_winui *win)
{
	ui_event(win);
	ui_resolve_buttons_event(win);
	ui_update_frames(win);
}
