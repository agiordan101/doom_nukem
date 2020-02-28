/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_draw.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:17:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:17:09 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UI_DRAW_H
# define UI_DRAW_H

# include "ui_shape.h"
# include "SDL.h"

void	ui_set_draw_color(SDL_Renderer *rend, const SDL_Color *color);
void	ui_draw_point(SDL_Renderer *rend, const t_dot *dot);
void	ui_draw_line(SDL_Renderer *rend, const t_line *line);
void	ui_draw_rect(SDL_Renderer *rend, const t_rect *rect);

#endif
