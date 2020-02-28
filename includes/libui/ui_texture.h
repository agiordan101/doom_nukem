/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_texture.h                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:20:45 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:20:51 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UI_TEXTURE_H
# define UI_TEXTURE_H

# include "SDL.h"
# include "SDL_ttf.h"
# include "ui_shape.h"

void				ui_set_rend_target(SDL_Renderer *rend,
										SDL_Texture *texture);
void				ui_draw_texture(SDL_Renderer *rend,
									SDL_Texture	*texture,
									const t_rect *src_rect,
									const t_rect *dst_rect);

typedef struct		s_button_texture_set
{
	SDL_Texture		*normal;
	SDL_Texture		*clicked;
	SDL_Texture		*on_mouse;
	SDL_Texture		*current;
}					t_simple_set;

SDL_Texture			*ui_load_image(SDL_Renderer *rend, const char *file);
void				ui_destroy_texture(SDL_Texture *texture);
t_simple_set		ui_create_simple_set(SDL_Texture *normal,
											SDL_Texture *clicked,
											SDL_Texture *on_mouse);
void				ui_free_simple_set(t_simple_set	simple_set);

typedef enum		e_text_align
{
	TEXT_ALIGN_NONE = 0,
	TEXT_ALIGN_LEFT = 1,
	TEXT_ALIGN_RIGHT = 2,
	TEXT_ALIGN_CENTER = 4,
	TEXT_ALIGN_V_MIDDLE = 8,
	TEXT_ALIGN_V_TOP = 16,
	TEXT_ALIGN_V_BOT = 32
}					t_text_align;

typedef enum		e_text_flag
{
	UI_DRAW_TEXT_NONE = 0b0,
	UI_DRAW_TEXT_LINE_BREAK = 1,
	UI_DRAW_TEXT_HIDE_RIGHT = 2,
	UI_DRAW_TEXT_HIDE_LEFT = 4
}					t_draw_text_flag;

typedef struct		s_text_entry_texture_set
{
	SDL_Texture		*name_side_texture;
	SDL_Texture		*normal_box_texture;
	SDL_Texture		*writting_box_texture;
	SDL_Texture		*current_box_texture;
}					t_text_entry_set;

t_text_entry_set	ui_create_text_entry_set(SDL_Texture *name_side_texture,
											SDL_Texture *normal_box_texture,
											SDL_Texture *writting_box_texture);
void				ui_free_text_entry_set(t_text_entry_set text_entry_set);

typedef struct		s_text_line_kit
{
	char			*str;
	SDL_Color		color;
	t_dot			pos;
	int				max_width;
	int				height;
	TTF_Font		*font;
	t_text_align	alignment;
}					t_text_line_kit;

typedef struct		s_text_rect_kit
{
	char			*str;
	SDL_Color		color;
	t_rect			rect;
	int				height;
	TTF_Font		*font;
	t_text_align	alignment;
}					t_text_rect_kit;

typedef struct		s_text
{
	char			*text;
	t_rect			rect;
	int				height;
	TTF_Font		*font;
	SDL_Color		color;
	t_text_align	alignment;
}					t_text;

TTF_Font			*ui_load_font(const char *file, int pixel_height);
SDL_Texture			*ui_new_text(SDL_Renderer *rend,
									TTF_Font *font,
									const char *text,
									const SDL_Color *color);
int					ui_get_text_width(TTF_Font *font,
										const char *text,
										int height);
void				ui_draw_text(SDL_Renderer *rend, const t_text *text);
int					ui_draw_text_line(SDL_Renderer *rend,
									t_text_line_kit *text);
int					draw_one_line_return(SDL_Renderer *rend,
										t_text_line_kit *text,
										int n_to_rem,
										int n_words);
int					ui_draw_text_line_return(SDL_Renderer *rend,
								t_text_line_kit *text);
void				ui_draw_text_in_rect(SDL_Renderer *rend,
											const t_text *text,
											t_rect rect);
int					ui_get_x_alignment(t_rect rect,
										t_text_align aligment,
										int text_width);

#endif
