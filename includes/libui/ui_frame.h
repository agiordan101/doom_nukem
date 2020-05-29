/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_frame.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:17:38 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/19 09:27:54 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_FRAME_H
# define UI_FRAME_H

# include "ui_button.h"

typedef struct			s_simple_frame
{
	char				*text;
	t_frect				text_ratio;
	SDL_Texture			*texture;
	SDL_Texture			*text_background;
}						t_simple_frame;

t_simple_frame			*ui_new_simple_frame(char *text,
										t_frect text_ratio,
										SDL_Texture *texture,
										SDL_Texture *text_background);
void					ui_free_simple_frame(t_simple_frame **simple_frame);

typedef enum			e_frame_type
{
	UI_FRAME_NONE = 0,
	UI_FRAME_SIMPLE = 1
}						t_frame_type;

typedef struct			s_frame
{
	void				*data;
	t_frame_type		type;
	t_resize_type		resize_type;
	t_rect				rect;
	t_frect				ratio;
	t_button			*buttons;
	struct s_frame		*next;
}						t_frame;

t_frame					*ui_new_frame(t_frame_type type,
										t_resize_type resize_type,
										t_frect ratio, void *data);
void					ui_add_frame(t_frame **frames, t_frame *new_frame);
void					ui_free_frame(t_frame **frame);
void					ui_free_frames(t_frame **frames);

#endif
