/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_event.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:17:32 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/28 16:45:29 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_EVENT_H
# define UI_EVENT_H

# include "ui_shape.h"
# ifdef __linux__
#  include "SDL2/SDL.h"
# else
#  include "SDL.h"
# endif

typedef enum		e_mouse_button
{
	UI_MOUSE_NONE = 0,
	UI_MOUSE_LEFT = 1,
	UI_MOUSE_RIGHT = 2,
	UI_MOUSE_MIDDLE = 4
}					t_mouse_button;

typedef struct		s_mouse
{
	t_dot			pos;
	t_mouse_button	clicked;
	t_mouse_button	clicking;
	t_mouse_button	releasing;
}					t_mouse;

void				ui_poll_event(SDL_Event *event);
void				ui_wait_event(SDL_Event *event);

#endif
