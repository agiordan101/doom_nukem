/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_win_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:37:28 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:18:45 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"

void		ui_set_winui_size(t_winui *win, int w, int h)
{
	SDL_SetWindowSize(win->ptr, w, h);
}

t_dot		ui_get_winui_size(t_winui *win)
{
	t_dot	size;

	SDL_GetWindowSize(win->ptr, &size.x, &size.y);
	return (size);
}

void		ui_lock_win_size(t_winui *win)
{
	SDL_SetWindowResizable(win->ptr, SDL_FALSE);
}

void		ui_unlock_win_size(t_winui *win)
{
	SDL_SetWindowResizable(win->ptr, SDL_TRUE);
}
