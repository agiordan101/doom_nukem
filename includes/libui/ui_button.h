/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_button.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:13:24 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/19 09:27:38 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_BUTTON_H
# define UI_BUTTON_H
# define UI_RESIZE_POS_LINEAR 3
# define UI_RESIZE_SIZE_LINEAR 12
# define UI_RESIZE_ALL_LINEAR 15
# include "ui_event.h"
# include "ui_shape.h"
# include "ui_texture.h"

typedef enum			e_simple_state
{
	UI_SIMPLE_NONE = 0,
	UI_SIMPLE_ON_MOUSE = 1,
	UI_SIMPLE_CLICKED = 2
}						t_simple_state;

typedef struct			s_simple_button
{
	char				*text;
	t_simple_set		textures;
	t_mouse_button		clicked_condition;
	void				(*f)(void *argument);
	void				*argurment;
}						t_simple_button;

t_simple_button			*ui_new_simple_button(t_mouse_button clicked_condition,
												void (*f)(void *argument),
												void *argument,
												t_simple_set textures);
void					ui_free_simple_button(t_simple_button **simple_button);

typedef enum			e_text_side
{
	UI_TEXT_SIDE_NONE = 0,
	UI_TEXT_SIDE_RIGHT = 1,
	UI_TEXT_SIDE_TOP = 2,
	UI_TEXT_SIDE_LEFT = 3,
	UI_TEXT_SIDE_BOT = 4
}						t_text_side;

typedef enum			e_text_type
{
	UI_TEXT_TYPE_NONE = 0,
	UI_TEXT_TYPE_DIGITAL = 1
}						t_text_type;

typedef struct			s_text_entry_button
{
	char				*name;
	char				*text;
	int					max_text_size;
	int					max_int;
	int					min_int;
	char				*new_text;
	t_text_side			text_side;
	t_text_type			text_type;
	t_text_entry_set	textures;
	void				(*f)(void *argument, char *button_output);
	void				*argument;
}						t_text_entry_button;

t_text_entry_button		*ui_new_text_entry_button(char *name,
													void (*f)(void *argument,
													char *button_output),
													void *argument,
													int max_text_size);
void					ui_free_text_entry_button(
						t_text_entry_button **text_entry);

typedef enum			e_resize_text
{
	UI_RESIZE_TEXT_NONE = 0,
	UI_RESIZE_TEXT_LINEAR = 1
}						t_resize_text;

typedef struct			s_text_area
{
	char				*text;
	t_resize_text		resize_text;
	float				text_height;
	t_text_align		text_align;
	SDL_Color			text_color;
}						t_text_area;

t_text_area				*ui_new_text_area(const char *text,
									float text_height,
									t_text_align text_align,
									t_resize_text resize_text);

void					ui_free_text_area(t_text_area **text_area);

typedef enum			e_button_type
{
	UI_BUTTON_NONE = 0,
	UI_BUTTON_SIMPLE = 1,
	UI_BUTTON_TEXT_ENTRY = 2,
	UI_BUTTON_TEXT_AREA = 3
}						t_button_type;

typedef enum			e_resize_type
{
	UI_RESIZE_NONE = 0,
	UI_RESIZE_X = 1,
	UI_RESIZE_Y = 2,
	UI_RESIZE_W = 4,
	UI_RESIZE_H = 8,
	UI_RESIZE_LOCK_RATIO = 16
}						t_resize_type;

typedef struct			s_button
{
	char				*id;
	void				*data;
	t_button_type		type;
	t_resize_type		resize_type;
	t_rect				rect;
	t_frect				ratio;
	struct s_button		*next;
}						t_button;

t_button				*ui_new_button(t_button_type type,
										t_resize_type resize_type,
										t_frect ratio,
										void *data);
void					ui_add_button(t_button **buttons, t_button *new_button);
void					ui_free_buttons(t_button **buttons);
void					ui_free_button(t_button **button);

#endif
