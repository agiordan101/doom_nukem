/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_display_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:36:41 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:17:54 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "ui_draw.h"
#include "ui_error.h"

void			ui_display_buttons(t_winui *win, t_button *buttons)
{
	t_button	*b;

	b = buttons;
	while (b)
	{
		if (b->type == UI_BUTTON_SIMPLE)
			ui_display_simple(win, (t_simple_button*)b->data, &b->rect);
		else if (b->type == UI_BUTTON_TEXT_ENTRY)
			ui_display_text_entry(win, (t_text_entry_button*)b->data, &b->rect);
		else if (b->type == UI_BUTTON_TEXT_AREA)
			ui_display_text_area(win, (t_text_area*)b->data, &b->rect);
		b = b->next;
	}
}
