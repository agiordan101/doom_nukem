/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_get_side_rect.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:37:01 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:51:46 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_win.h"

t_rect	ui_get_name_side_rect(t_winui *win,
						t_text_entry_button *text_entry_button,
						const t_rect *rect)
{
	int			text_width;
	int			text_height;
	t_rect		texture_rect;

	text_height = rect->h * win->ui.button_text_ratio;
	text_width = ui_get_text_width(win->ui.button_font,
					text_entry_button->name, text_height);
	if (text_entry_button->text_side == UI_TEXT_SIDE_TOP)
		texture_rect = (t_rect){rect->x, rect->y, rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_BOT)
		texture_rect = (t_rect){rect->x, rect->y + rect->h,
								rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_LEFT)
		texture_rect = (t_rect){rect->x, rect->y, rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_RIGHT)
		texture_rect = (t_rect){rect->x + rect->w - rect->w / 3, rect->y,
								rect->w / 3, rect->h};
	else
		texture_rect = (t_rect){0, 0, 0, 0};
	return (texture_rect);
}

t_rect	ui_get_text_side_rect(t_winui *win,
						t_text_entry_button *text_entry_button,
						const t_rect *rect)
{
	int			text_width;
	int			text_height;
	t_rect		texture_rect;

	text_height = rect->h * win->ui.button_text_ratio;
	text_width = ui_get_text_width(win->ui.button_font,
					text_entry_button->name, text_height);
	if (text_entry_button->text_side == UI_TEXT_SIDE_TOP)
		texture_rect = (t_rect){rect->x, rect->y + rect->h,
								rect->w - rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_BOT)
		texture_rect = (t_rect){rect->x, rect->y,
								rect->w - rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_LEFT)
		texture_rect = (t_rect){rect->x + rect->w / 3,
							rect->y, rect->w - rect->w / 3, rect->h};
	else if (text_entry_button->text_side == UI_TEXT_SIDE_RIGHT)
		texture_rect = (t_rect){rect->x, rect->y,
								rect->w - rect->w / 3, rect->h};
	else
		texture_rect = (t_rect){0, 0, 0, 0};
	return (texture_rect);
}
