/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_shape.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:33:39 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:52:54 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_draw.h"

void	ui_draw_point(SDL_Renderer *rend, const t_dot *dot)
{
	SDL_RenderDrawPoint(rend, dot->x, dot->y);
}

void	ui_draw_line(SDL_Renderer *rend, const t_line *line)
{
	SDL_RenderDrawLine(rend, line->p1.x, line->p1.y, line->p2.x, line->p2.y);
}

void	ui_draw_rect(SDL_Renderer *rend, const t_rect *rect)
{
	SDL_RenderDrawRect(rend, (SDL_Rect*)rect);
}
