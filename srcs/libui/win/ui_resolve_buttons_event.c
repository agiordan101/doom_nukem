/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_resolve_buttons_event.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:18:25 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:18:26 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "libft.h"

static void	ui_mouse_releasing(t_winui *win)
{
	if (win->mouse.releasing)
	{
		if (win->ui.clicked_button)
		{
			if (win->ui.clicked_button->type == UI_BUTTON_SIMPLE &&
				win->ui.clicked_button == win->ui.on_mouse_button)
				ui_call_simple_function(win, win->ui.clicked_button->data);
			if (win->ui.clicked_button->type != UI_BUTTON_TEXT_ENTRY)
				win->ui.clicked_button = NULL;
		}
	}
}

static void	ui_start_text_input(t_winui *win)
{
	SDL_StartTextInput();
	ft_strcpy(((t_text_entry_button*)
				win->ui.clicked_button->data)->new_text,
				((t_text_entry_button*)
				win->ui.clicked_button->data)->text);
	win->ui.cursor_position = ft_strlen(((t_text_entry_button*)
					win->ui.clicked_button->data)->new_text);
}

static void	ui_set_clicked_on_mouse(t_winui *win, t_button *b)
{
	if (win->mouse.clicking &&
		!(win->ui.clicked_button &&
		win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY &&
		win->ui.clicked_button == b))
	{
		win->ui.clicked_button = b;
		if (win->ui.clicked_button->type == UI_BUTTON_TEXT_ENTRY)
			ui_start_text_input(win);
	}
	win->ui.on_mouse_button = b;
}

void		ui_resolve_buttons_event(t_winui *win)
{
	t_frame				*f;
	t_button			*b;

	ui_mouse_releasing(win);
	ui_check_text_entry_button(win);
	f = win->ui.frames;
	win->ui.on_mouse_button = NULL;
	while (f)
	{
		b = f->buttons;
		while (b)
		{
			if (ui_is_dot_in_rect(win->mouse.pos, b->rect))
				ui_set_clicked_on_mouse(win, b);
			b = b->next;
		}
		f = f->next;
	}
}
