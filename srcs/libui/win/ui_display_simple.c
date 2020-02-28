/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_display_simple.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:36:48 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 12:43:27 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

void			ui_display_simple(t_winui *win,
									t_simple_button *simple_button,
									const t_rect *rect)
{
	SDL_Texture	*text_texture;

	if (simple_button->textures.current)
		SDL_RenderCopy(win->rend, simple_button->textures.current,
						NULL, (SDL_Rect*)rect);
	else
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(win->rend, rect);
	}
	if (simple_button->text && ft_strlen(simple_button->text) > 0)
	{
		if (win->ui.button_font)
		{
			if ((text_texture = ui_new_text(win->rend,
					win->ui.button_font, simple_button->text,
					&win->ui.button_text_color)))
			{
				ui_display_simple_draw_text(win, simple_button, rect);
				SDL_DestroyTexture(text_texture);
			}
			else
				ui_ret_error("ui_display_simple", "ui_new_text failed", 0);
		}
		else
			ui_ret_error("ui_display_simple",
							"(ui_win)->(TTF_Font*)button_font is not set", 0);
	}
}
