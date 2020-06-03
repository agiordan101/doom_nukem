/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_check_text_entry_button.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:17:46 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:17:48 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "libft.h"

static void	ui_end_text_input(t_winui *win)
{
	SDL_StopTextInput();
	ft_strcpy(((t_text_entry_button*)
			win->ui.clicked_button->data)->text,
			((t_text_entry_button*)
			win->ui.clicked_button->data)->new_text);
	ft_bzero(((t_text_entry_button*)
			win->ui.clicked_button->data)->new_text,
			((t_text_entry_button*)
			win->ui.clicked_button->data)->max_text_size);
	ui_call_text_entry_function(win->ui.clicked_button->data);
}

void		ui_check_text_entry_button(t_winui *win)
{
	if (win->ui.clicked_button
	&& win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
	{
		if ((win->mouse.clicking
			&& win->ui.on_mouse_button != win->ui.clicked_button)
			|| win->event.key.keysym.scancode == SDL_SCANCODE_RETURN)
		{
			if (((t_text_entry_button*)
			win->ui.clicked_button->data)->text_type != UI_TEXT_TYPE_DIGITAL
			|| ft_atoi(((t_text_entry_button*)
			win->ui.clicked_button->data)->new_text) >= ((t_text_entry_button*)
				win->ui.clicked_button->data)->min_int)
			{
				ui_end_text_input(win);
			}
			win->ui.clicked_button = NULL;
			win->ui.cursor_position = 0;
		}
		else
			ui_resolve_text_entry_button(win, win->ui.clicked_button->data);
	}
}
