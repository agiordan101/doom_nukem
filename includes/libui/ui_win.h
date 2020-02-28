/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_win.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:21:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/17 14:33:34 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UI_WIN_H
# define UI_WIN_H

# include "ui_button.h"
# include "ui_frame.h"
# include "ui_event.h"
# include "ui_shape.h"
# include "ui_texture.h"
# include "SDL.h"

typedef struct			s_texture
{
	char				*id;
	SDL_Texture			*sdl_ptr;
	struct s_texture	*next;
}						t_texture;

typedef struct			s_ui
{
	t_frame				*frames;
	t_button			*on_mouse_button;
	t_button			*clicked_button;
	TTF_Font			*button_font;
	SDL_Color			button_text_color;
	float				button_text_ratio;
	int					cursor_position;
	Uint32				delay_text_entry;
	Uint32				delay_text_del;
	char				last_char;
	t_draw_text_flag	text_enrty_flags;
	SDL_Color			cursor_color;
	t_texture			*textures;
}						t_ui;

void					ui_free_ui(t_ui *ui);

typedef struct			s_winui
{
	SDL_Window			*ptr;
	SDL_Renderer		*rend;
	SDL_Event			event;
	t_mouse				mouse;
	t_ui				ui;
}						t_winui;

t_winui					*ui_new_win(const char *title,
								t_rect rect,
								Uint32 sdl_win_flags,
								Uint32 sdl_rend_flags);
void					ui_free_win(t_winui **win);

void					ui_set_winui_size(t_winui *win, int w, int h);
t_dot					ui_get_winui_size(t_winui *win);
void					ui_lock_win_size(t_winui *win);
void					ui_unlock_win_size(t_winui *win);

void					ui_clear_win(t_winui *win);
void					ui_draw_rend(t_winui *win);

void					ui_event_update_mouse(t_mouse *mouse);

void					ui_update_buttons(t_winui *win);

void					ui_display_simple(t_winui *win,
								t_simple_button *simple_button,
								const t_rect *rect);
t_rect					ui_get_name_side_rect(t_winui *win,
						t_text_entry_button *text_entry_button,
						const t_rect *rect);
t_rect					ui_get_text_side_rect(t_winui *win,
						t_text_entry_button *text_entry_button,
						const t_rect *rect);
void					ui_display_text_entry(t_winui *win,
			t_text_entry_button *text_entry_button, const t_rect *rect);
void					ui_display_buttons(t_winui *win, t_button *buttons);
void					ui_update_buttons_textures(t_winui *win,
			t_button *on_mouse_button, t_button *clicked_button);
void					ui_display_frames(t_winui *win, t_frame *frames);
void					ui_display_simple_frame(t_winui *win,
			t_simple_frame *simple_frame, const t_rect *rect);
void					ui_display_text_area(t_winui *win,
			t_text_area *text_area, const t_rect *rect);

void					ui_call_simple_function(t_winui *win,
			t_simple_button *simple_button);
void					ui_call_text_entry_function(
			t_text_entry_button *text_entry_button);
void					ui_resolve_text_entry_button(t_winui *win,
							t_text_entry_button *text_entry_button);
void					ui_resolve_buttons_event(t_winui *win);
void					ui_update_frames(t_winui *win);
void					ui_update_frames_rect(t_winui *win,
							SDL_bool force_update);
void					ui_update_buttons_rect(t_winui *win,
							SDL_bool force_update);
void					ui_update_ui(t_winui *win);

void					ui_set_simple_button_function(t_winui *win,
						const char *button_id, void (*fn)(void *argument),
						void *argument);
void					ui_set_text_entry_function(t_winui *win,
		const char *button_id, void (*fn)(void *argument, char *button_output),
		void *argument);

t_text_area				*ui_get_text_area_button(t_winui *win, const char *id);
t_simple_button			*ui_get_simple_button(t_winui *win, const char *id);
t_text_entry_button		*ui_get_text_entry_button(t_winui *win, const char *id);
#endif
