/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_display_text_area.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:36:51 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:18:08 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "ui_draw.h"

void	ui_display_text_area(t_winui *win,
							t_text_area *text_area,
							const t_rect *rect)
{
	t_dot	pos;
	int		text_height;

	if (text_area->text_align & TEXT_ALIGN_RIGHT)
		pos = (t_dot){rect->x + rect->w, rect->y};
	else if (text_area->text_align & TEXT_ALIGN_CENTER)
		pos = (t_dot){rect->x + rect->w / 2, rect->y};
	else
		pos = (t_dot){rect->x, rect->y};
	if (text_area->resize_text == UI_RESIZE_TEXT_LINEAR)
		text_height = rect->h * text_area->text_height;
	else
		text_height = text_area->text_height;
	ui_draw_text_line_return(win->rend, &(t_text_line_kit){text_area->text,
										text_area->text_color,
										pos,
										rect->w,
										text_height,
										win->ui.button_font,
										text_area->text_align});
}
