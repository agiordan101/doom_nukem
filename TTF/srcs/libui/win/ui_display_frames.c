/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_display_frames.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:36:44 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:17:59 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "ui_frame.h"
#include "ui_draw.h"
#include "ui_texture.h"

void			ui_display_frames(t_winui *win, t_frame *frames)
{
	t_frame	*f;

	f = frames;
	while (f)
	{
		if (f->type == UI_FRAME_SIMPLE)
			ui_display_simple_frame(win, (t_simple_frame*)f->data, &f->rect);
		ui_display_buttons(win, f->buttons);
		f = f->next;
	}
}

void			ui_display_simple_frame(t_winui *win,
				t_simple_frame *simple_frame,
				const t_rect *rect)
{
	if (simple_frame->texture)
		SDL_RenderCopy(win->rend, simple_frame->texture,
						NULL, (SDL_Rect*)rect);
	else
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(win->rend, rect);
	}
}
