/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_display_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:18:02 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:18:03 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "ui_draw.h"
#include "ui_error.h"
#include "libft.h"

static void		ui_display_simple_draw_text(t_winui *win,
											t_simple_button *simple_button,
											const t_rect *rect)
{
	ui_draw_text_line(win->rend,
					&(t_text_line_kit){simple_button->text,
					win->ui.button_text_color,
					(t_dot){rect->x + rect->w / 2,
					rect->y + rect->h / 2},
					rect->w,
					rect->h * win->ui.button_text_ratio,
					win->ui.button_font,
					TEXT_ALIGN_CENTER | TEXT_ALIGN_V_MIDDLE});
}

void			ui_display_simple(t_winui *w,
									t_simple_button *s_b,
									const t_rect *rect)
{
	SDL_Texture	*t;

	if (s_b->textures.current)
		SDL_RenderCopy(w->rend, s_b->textures.current, NULL, (SDL_Rect*)rect);
	else
	{
		ui_set_draw_color(w->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(w->rend, rect);
	}
	if (s_b->text && ft_strlen(s_b->text) > 0)
	{
		if (w->ui.button_font)
		{
			if ((t = ui_new_text(w->rend, w->ui.button_font,
						s_b->text, &w->ui.button_text_color)))
			{
				ui_display_simple_draw_text(w, s_b, rect);
				SDL_DestroyTexture(t);
			}
			else
				ui_ret_error("ui_display_simple", "ui_new_text failed", 0);
		}
		else
			ui_ret_error("ui_display_simple", "(ui_win)->(TTF_Font*)", 0);
	}
}
