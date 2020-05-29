/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:41:41 by gal               #+#    #+#             */
/*   Updated: 2020/05/20 14:54:38 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_line(t_win *win, t_dot p1, t_dot p2)
{
	int		i;
	int		n_pixels;
	t_fdot	delta;
	t_dot	absdelta;
	t_dot	pixel;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	absdelta = (t_dot){ft_intabs(delta.x), ft_intabs(delta.y)};
	n_pixels = absdelta.x > absdelta.y ? absdelta.x : absdelta.y;
	if (is_null(n_pixels, 0.0005))
		return ;
	delta.x /= n_pixels;
	delta.y /= n_pixels;
	i = -1;
	while (++i < n_pixels)
	{
		pixel = (t_dot){	.x = (int)(p1.x + delta.x * i),\
							.y = (int)(p1.y + delta.y * i)};
		if (0 <= pixel.x && pixel.x < win->w &&\
			0 <= pixel.y && pixel.y < win->h)
			SDL_RenderDrawPoint(win->rend, pixel.x, pixel.y);
	}
}

void	draw_t_line(t_win *win, t_line line)
{
	draw_line(win, line.p1, line.p2);
}

void	draw_column(t_win *win, int x, int ylow, int yup)
{
	if (ylow < 0)
		ylow = 0;
	if (yup > win->h)
		yup = win->h;
	while (ylow <= yup)
		SDL_RenderDrawPoint(win->rend, x, ylow++);
}

void	draw_rect(t_win *win, SDL_Rect rect)
{
	draw_line(win, (t_dot){rect.x, rect.y}, (t_dot){rect.x + rect.w, rect.y});
	draw_line(win, (t_dot){rect.x + rect.w, rect.y},
				(t_dot){rect.x + rect.w, rect.y + rect.h});
	draw_line(win, (t_dot){rect.x + rect.w, rect.y + rect.h},
				(t_dot){rect.x, rect.y + rect.h});
	draw_line(win, (t_dot){rect.x, rect.y + rect.h}, (t_dot){rect.x, rect.y});
}

void	fill_rect(t_win *win, SDL_Rect rect)
{
	int		x;
	int		xmax;
	int		y1;
	int		y2;

	x = rect.x;
	xmax = rect.x + rect.w;
	y1 = rect.y;
	y2 = rect.y + rect.h;
	while (x < xmax)
	{
		draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
		x++;
	}
}
