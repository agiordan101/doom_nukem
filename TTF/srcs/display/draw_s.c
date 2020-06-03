/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:48:32 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 15:49:18 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_ratio_rect(t_win *win, const SDL_Rect *rect, const t_frect *ratio)
{
	int x;
	int	y;
	int	w;
	int	h;

	x = rect->w * ratio->x + rect->x;
	y = rect->h * ratio->y + rect->y;
	w = rect->w * ratio->w;
	h = rect->h * ratio->h;
	draw_line(win, (t_dot){x, y}, (t_dot){x + w, y});
	draw_line(win, (t_dot){x + w, y}, (t_dot){x + w, y + h});
	draw_line(win, (t_dot){x + w, y + h}, (t_dot){x, y + h});
	draw_line(win, (t_dot){x, y + h}, (t_dot){x, y});
}

void	draw_quarter_circle(t_win *win, t_circle circle, float dir_start)
{
	t_fdot	p;
	float	angle;
	float	end;

	dir_start = 360 - dir_start;
	angle = dir_start * M_PI / 180;
	end = (dir_start + 90) * M_PI / 180;
	while (angle < end)
	{
		p.x = circle.x + circle.radius * sin(angle);
		p.y = circle.y + circle.radius * cos(angle);
		SDL_RenderDrawPoint(win->rend, p.x, p.y);
		angle += 0.01;
	}
}

void	draw_circle(t_win *win, t_circle circle)
{
	int		x;
	int		y;
	int		m;

	x = 0;
	y = circle.radius;
	m = 5 - 4 * circle.radius;
	while (x <= y)
	{
		SDL_RenderDrawPoint(win->rend, circle.x + x, y + circle.y);
		SDL_RenderDrawPoint(win->rend, circle.x + y, circle.y + x);
		SDL_RenderDrawPoint(win->rend, circle.x - x, y + circle.y);
		SDL_RenderDrawPoint(win->rend, circle.x - y, circle.y + x);
		SDL_RenderDrawPoint(win->rend, circle.x + x, circle.y - y);
		SDL_RenderDrawPoint(win->rend, circle.x + y, circle.y - x);
		SDL_RenderDrawPoint(win->rend, circle.x - x, circle.y - y);
		SDL_RenderDrawPoint(win->rend, circle.x - y, circle.y - x);
		if (m > 0)
		{
			y--;
			m = m - 8 * y;
		}
		x++;
		m = m + 8 * x + 4;
	}
}
