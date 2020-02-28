/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_display_text_entry.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:36:55 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 12:50:19 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_win.h"
#include "ui_draw.h"
#include "ui_error.h"
#include "libft.h"

static void		ui_draw_cursor(t_winui *win, char *text, const t_rect *rect)
{
	int		x_pos;
	int		x_size;
	int		x_pre_size;
	char	pre_cursor_text[ft_strlen(text) + 1];

	ft_bzero(pre_cursor_text, ft_strlen(text) + 1);
	ft_strncpy(pre_cursor_text, text, win->ui.cursor_position);
	x_pre_size = ui_get_text_width(win->ui.button_font, pre_cursor_text,
									rect->h * win->ui.button_text_ratio);
	x_size = ui_get_text_width(win->ui.button_font, text,
					rect->h * win->ui.button_text_ratio);
	ui_set_draw_color(win->rend, &win->ui.cursor_color);
	x_pos = rect->x + rect->w / 2 - x_size / 2 + x_pre_size;
	ui_draw_line(win->rend,
		&((t_line){(t_dot){x_pos, rect->y},
		(t_dot){x_pos, rect->y + rect->h}}));
}

static void		ui_draw_text_side(t_winui *win,
									const t_rect *rect,
									t_text_entry_button *text_entry,
									char *text)
{
	t_rect				r;
	char				pre_cursor_text[ft_strlen(text) + 1];
	int					cursor_x;
	t_dot				text_size;

	ft_bzero(pre_cursor_text, ft_strlen(text) + 1);
	ft_strncpy(pre_cursor_text, text, win->ui.cursor_position);
	TTF_SizeText(win->ui.button_font, pre_cursor_text,
					&text_size.x, &text_size.y);
	r = ui_get_text_side_rect(win, text_entry, rect);
	cursor_x = (r.h * text_size.x) / text_size.y;
	ui_draw_text_line(win->rend,
						&(t_text_line_kit){text,
						win->ui.button_text_color,
						(t_dot){r.x + r.w / 2, r.y + r.h / 2},
						r.w,
						r.h * win->ui.button_text_ratio,
						win->ui.button_font,
						TEXT_ALIGN_CENTER | TEXT_ALIGN_V_MIDDLE});
	if (win->ui.clicked_button
			&& (t_text_entry_button*)(
			win->ui.clicked_button->data) == text_entry)
		ui_draw_cursor(win, text,
						&r);
}

static void		ui_draw_name_side(t_winui *win,
									t_text_entry_button *text_entry_button,
									const t_rect *rect)
{
	SDL_Texture	*text_texture;
	t_rect		r;

	if (text_entry_button->name)
	{
		if ((text_texture = ui_new_text(win->rend, win->ui.button_font,
			text_entry_button->name, &win->ui.button_text_color)))
		{
			r = ui_get_name_side_rect(win, text_entry_button, rect);
			if (text_entry_button->textures.name_side_texture)
				SDL_RenderCopy(win->rend,
				text_entry_button->textures.name_side_texture,
				NULL, (SDL_Rect*)&r);
			ui_draw_text_line(win->rend,
								&(t_text_line_kit){text_entry_button->name,
								win->ui.button_text_color,
								(t_dot){r.x + r.w / 2, r.y + r.h / 2},
								r.w,
								r.h * win->ui.button_text_ratio,
								win->ui.button_font,
								TEXT_ALIGN_CENTER | TEXT_ALIGN_V_MIDDLE});
			SDL_DestroyTexture(text_texture);
		}
	}
}

static void		ui_draw_text_entry_normally(t_winui *win,
									t_text_entry_button *text_entry_button,
									const t_rect *rect)
{
	SDL_Texture	*text_texture;
	char		*text;

	ui_draw_name_side(win, text_entry_button, rect);
	if (win->ui.clicked_button && win->ui.clicked_button->data == text_entry_button)
		text = text_entry_button->new_text;
	else
		text = text_entry_button->text;
	if (text[0]
		&& (text_texture = ui_new_text(win->rend,
										win->ui.button_font,
										text,
										&win->ui.button_text_color)))
	{
		ui_draw_text_side(win, rect, text_entry_button, text);
		SDL_DestroyTexture(text_texture);
	}
}

void			ui_display_text_entry(t_winui *win,
										t_text_entry_button *text_entry_button,
										const t_rect *rect)
{
	t_rect text_side_rect;

	if (text_entry_button->textures.current_box_texture)
	{
		text_side_rect = ui_get_text_side_rect(win, text_entry_button, rect);
		SDL_RenderCopy(win->rend,
						text_entry_button->textures.current_box_texture,
						NULL, (SDL_Rect*)&text_side_rect);
	}
	else
	{
		ui_set_draw_color(win->rend, &(SDL_Color){200, 200, 200, 255});
		ui_draw_rect(win->rend, rect);
	}
	if (win->ui.button_font)
		ui_draw_text_entry_normally(win, text_entry_button, rect);
}
