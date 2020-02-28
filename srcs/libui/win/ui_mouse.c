/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_mouse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:37:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:37:06 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_win.h"

static void	ui_mouse_state_click(t_mouse *mouse,
			Uint32 mouse_state,
			t_mouse_button last_clicked)
{
	if (mouse_state & SDL_BUTTON(SDL_BUTTON_LEFT))
		mouse->clicked |= UI_MOUSE_LEFT;
	if (mouse_state & SDL_BUTTON(SDL_BUTTON_RIGHT))
		mouse->clicked |= UI_MOUSE_RIGHT;
	if (mouse_state & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		mouse->clicked |= UI_MOUSE_MIDDLE;
	if (!(last_clicked & UI_MOUSE_LEFT) && (mouse->clicked & UI_MOUSE_LEFT))
		mouse->clicking |= UI_MOUSE_LEFT;
	if (!(last_clicked & UI_MOUSE_RIGHT) && (mouse->clicked & UI_MOUSE_RIGHT))
		mouse->clicking |= UI_MOUSE_RIGHT;
	if (!(last_clicked & UI_MOUSE_MIDDLE) && (mouse->clicked & UI_MOUSE_MIDDLE))
		mouse->clicking |= UI_MOUSE_MIDDLE;
	if ((last_clicked & UI_MOUSE_LEFT) && !(mouse->clicked & UI_MOUSE_LEFT))
		mouse->releasing |= UI_MOUSE_LEFT;
	if ((last_clicked & UI_MOUSE_RIGHT) && !(mouse->clicked & UI_MOUSE_RIGHT))
		mouse->releasing |= UI_MOUSE_RIGHT;
	if ((last_clicked & UI_MOUSE_MIDDLE) && !(mouse->clicked & UI_MOUSE_MIDDLE))
		mouse->releasing |= UI_MOUSE_MIDDLE;
}

void		ui_event_update_mouse(t_mouse *mouse)
{
	Uint32			mouse_state;
	t_mouse_button	last_clicked;

	last_clicked = mouse->clicked;
	mouse->clicked = UI_MOUSE_NONE;
	mouse->clicking = UI_MOUSE_NONE;
	mouse->releasing = UI_MOUSE_NONE;
	mouse_state = SDL_GetMouseState(&mouse->pos.x, &mouse->pos.y);
	ui_mouse_state_click(mouse, mouse_state, last_clicked);
}
