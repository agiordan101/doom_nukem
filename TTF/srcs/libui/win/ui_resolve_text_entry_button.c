/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_resolve_text_entry_button.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:18:28 by gal               #+#    #+#             */
/*   Updated: 2020/05/19 12:00:15 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "libft.h"

static void		suppress_char(t_winui *win, t_text_entry_button *t_e_button)
{
	int		i;
	int		i_tmp;
	char	tmp[t_e_button->max_text_size + 1];

	if (ft_strlen(t_e_button->new_text) > 0)
	{
		if (t_e_button->text_type == UI_TEXT_TYPE_DIGITAL)
			t_e_button->new_text[
			ft_strlen(t_e_button->new_text) - 1] = '\0';
		else
		{
			ft_bzero(tmp, t_e_button->max_text_size + 1);
			ft_strncpy(tmp,
				&(t_e_button->new_text[win->ui.cursor_position]),
				ft_strlen(&(t_e_button->new_text[win->ui.cursor_position])));
			i = win->ui.cursor_position - 1;
			i_tmp = 0;
			while (tmp[i_tmp])
				t_e_button->new_text[i++] = tmp[i_tmp++];
			t_e_button->new_text[i] = '\0';
		}
	}
	win->ui.cursor_position--;
	if (win->ui.cursor_position < 0)
		win->ui.cursor_position = 0;
}

static void		text_input_digital(t_winui *win,
								t_text_entry_button *text_entry_button)
{
	int		nb;

	if (ft_isdigit(win->event.text.text[0]) ||
	(win->event.text.text[0] == '-' && text_entry_button->min_int < 0))
	{
		if ((int)ft_strlen(text_entry_button->new_text) <=
			text_entry_button->max_text_size - 1)
		{
			ft_strcat(text_entry_button->new_text,
					win->event.text.text);
			nb = ft_atoi(text_entry_button->new_text);
			if (nb > text_entry_button->max_int)
				text_entry_button->new_text[
					ft_strlen(text_entry_button->new_text) - 1] = '\0';
			win->ui.cursor_position++;
		}
	}
}

static void		text_input_else(t_winui *win,
							t_text_entry_button *text_entry_button)
{
	int		i;
	int		i_tmp;
	char	tmp[text_entry_button->max_text_size + 1];

	if ((int)ft_strlen(text_entry_button->new_text) <=
		text_entry_button->max_text_size - 1)
	{
		ft_bzero(tmp, text_entry_button->max_text_size + 1);
		ft_strncpy(tmp,
				&(text_entry_button->new_text[win->ui.cursor_position]),
				ft_strlen(&(text_entry_button->new_text[
							win->ui.cursor_position])));
		text_entry_button->new_text[win->ui.cursor_position] =
				win->event.text.text[0];
		i = win->ui.cursor_position + 1;
		i_tmp = 0;
		while (tmp[i_tmp])
			text_entry_button->new_text[i++] = tmp[i_tmp++];
		win->ui.cursor_position++;
	}
}

static void		ui_text_input(t_text_entry_button *text_entry_button,
								t_winui *win,
								Uint32 *n_ti,
								Uint32 *l_ti)
{
	if (text_entry_button->text_type & UI_TEXT_TYPE_DIGITAL)
		text_input_digital(win, text_entry_button);
	else
		text_input_else(win, text_entry_button);
	*l_ti = *n_ti;
	win->ui.last_char = win->event.text.text[0];
}

void			ui_resolve_text_entry_button(t_winui *win,
						t_text_entry_button *text_entry_button)
{
	static Uint32	l_ti = 0;
	Uint32			n_ti;

	n_ti = SDL_GetTicks();
	if (l_ti == 0 || n_ti - l_ti >= win->ui.delay_text_entry)
	{
		if (win->event.type == SDL_KEYDOWN)
		{
			if (win->event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE
				&& win->ui.cursor_position > 0)
			{
				suppress_char(win, text_entry_button);
				l_ti = n_ti;
			}
		}
	}
	if (win->event.type == SDL_TEXTINPUT)
	{
		if (l_ti == 0 || n_ti - l_ti >= win->ui.delay_text_entry
		|| win->ui.last_char == '\0' || win->event.text.text[0]
		!= win->ui.last_char)
			ui_text_input(text_entry_button, win, &n_ti, &l_ti);
	}
}
