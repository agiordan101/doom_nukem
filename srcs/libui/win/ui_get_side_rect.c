/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_side_rect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:37:01 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/17 23:49:43 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"

t_rect	ui_get_name_side_rect(t_text_entry_button *text_entry_button,
						const t_rect *rect)
{
	t_rect		texture_rect;

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

t_rect	ui_get_text_side_rect(t_text_entry_button *text_entry_button,
						const t_rect *rect)
{
	t_rect		texture_rect;

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
