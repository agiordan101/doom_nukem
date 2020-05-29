/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_set_button_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:18:31 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:18:31 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "libft.h"

void	ui_set_simple_button_function(t_winui *win,
			const char *button_id, void (*fn)(void *argument),
			void *argument)
{
	t_frame		*f;
	t_button	*b;

	f = win->ui.frames;
	while (f)
	{
		b = f->buttons;
		while (b)
		{
			if (b->type == UI_BUTTON_SIMPLE && ft_strcmp(b->id, button_id) == 0)
			{
				((t_simple_button*)b->data)->argurment = argument;
				((t_simple_button*)b->data)->f = fn;
			}
			b = b->next;
		}
		f = f->next;
	}
}

void	ui_set_text_entry_function(t_winui *win,
		const char *button_id, void (*fn)(void *argument, char *button_output),
		void *argument)
{
	t_frame		*f;
	t_button	*b;

	f = win->ui.frames;
	while (f)
	{
		b = f->buttons;
		while (b)
		{
			if (b->type == UI_BUTTON_TEXT_ENTRY
			&& ft_strcmp(b->id, button_id) == 0)
			{
				((t_text_entry_button*)b->data)->argument = argument;
				((t_text_entry_button*)b->data)->f = fn;
			}
			b = b->next;
		}
		f = f->next;
	}
}
