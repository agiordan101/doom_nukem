/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:33:39 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:14:59 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_draw.h"
#include "libft.h"

void	ui_draw_point(SDL_Renderer *rend, const t_dot *dot)
{
	SDL_RenderDrawPoint(rend, dot->x, dot->y);
}

void	ui_draw_line(SDL_Renderer *rend, const t_line *line)
{
	int		i;
	int		n_pixels;
	t_fdot	delta;
	t_fdot	absdelta;
	t_fdot	pixel;

	delta.x = line->p2.x - line->p1.x;
	delta.y = line->p2.y - line->p1.y;
	absdelta = (t_fdot){ft_abs(delta.x), ft_abs(delta.y)};
	n_pixels = absdelta.x > absdelta.y ? absdelta.x : absdelta.y;
	delta.x /= n_pixels;
	delta.y /= n_pixels;
	i = -1;
	while (++i < n_pixels)
	{
		pixel = (t_fdot){	.x = line->p1.x + delta.x * i,\
							.y = line->p1.y + delta.y * i};
		SDL_RenderDrawPoint(rend, pixel.x, pixel.y);
	}
}

void	ui_draw_rect(SDL_Renderer *rend, const t_rect *rect)
{
	SDL_RenderDrawRect(rend, (SDL_Rect*)rect);
}
