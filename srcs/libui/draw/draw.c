/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:33:44 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:33:47 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_draw.h"

void	ui_set_draw_color(SDL_Renderer *rend, const SDL_Color *color)
{
	SDL_SetRenderDrawColor(rend, color->r, color->g, color->b, color->a);
}
