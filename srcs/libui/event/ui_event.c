/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_event.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:33:50 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:33:54 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_event.h"

void	ui_poll_event(SDL_Event *event)
{
	SDL_PollEvent(event);
}

void	ui_wait_event(SDL_Event *event)
{
	SDL_WaitEvent(event);
}
