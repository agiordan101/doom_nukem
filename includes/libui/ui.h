/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:16:36 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:51:37 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include <stdio.h>
# include "ui_win.h"
# include "ui_frame.h"
# include "ui_draw.h"
# include "libft.h"
# include "SDL.h"

int					ui_init(Uint32 sdl_flags);
void				ui_quit(Uint32 flags);

char				**skip_next_block(char **str);

char				*parse_str(char *str);
int					parse_int(const char *str, int *n);

int					get_resize_type(const char *line);
int					get_resize_text(const char *line);

int					get_clicked_condition(const char *line);
char				*get_next_flag(const char *flags);
char				**get_flags_tab(const char *flags);
int					get_ratio(const char *line, t_frect *ratio_ptr);
int					get_float(char *str, double *fnb_ptr);

int					get_frame_type(const char *line);
int					get_button_type(const char *line);
int					get_text_side(const char *line);
int					get_text_type(const char *line);
int					get_text_align(const char *line);
int					parse_sdl_color(const char *line, SDL_Color *sdl_color);

void				add_texture(t_texture **textures, t_texture *new_texture);
t_texture			*new_texture(char *id, SDL_Texture *sdl_ptr);
SDL_Texture			*get_texture_ptr(t_texture *textures, const char *id);
SDL_Texture			*parse_texture(SDL_Renderer *rend, t_texture **textures,
									const char *expected_name, char *line);
void				ui_free_texture(t_texture **texture);
void				ui_free_textures(t_texture **textures);

int					parse_frame(t_winui *win, char **text, int *i);
void				*parse_frame_data(t_winui *win,
									char **str,
									t_frame_type frame_type,
									int *i);
t_simple_frame		*parse_simple_frame(SDL_Renderer *rend,
									t_texture **textures,
									char **str,
									int *i);

void				incre_double_int(int *a, int *b, int value);

t_button			*parse_button(t_winui *win, char **text, int *i);
int					parse_buttons(t_winui *win, char **text, int *i);
t_simple_button		*parse_simple_button(t_winui *win,
										char **text,
										int *i);
t_text_entry_button	*parse_text_entry_button(t_winui *win,
											char **text,
											int *i);
int					parse_cut(t_winui *win,
						char **text,
						int *i,
						t_text_entry_button *b);
t_text_area			*parse_text_area(char **text,
								int *i);

int					check_line_name(const char *line, const char *expected);
int					ui_load(const char *path, t_winui *win);

#endif
