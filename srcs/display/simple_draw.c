#include "doom_nukem.h"

void	draw_line(t_win *win, t_dot p1, t_dot p2)
{
	int		i;
	int		n_pixels;
	t_fdot	delta;
	t_fdot	absdelta;
	t_fdot	pixel;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	absdelta = (t_fdot){ft_abs(delta.x), ft_abs(delta.y)};
	n_pixels = absdelta.x > absdelta.y ? absdelta.x : absdelta.y;
	delta.x /= n_pixels;
	delta.y /= n_pixels;
	i = -1;
	while (++i < n_pixels)
	{
		pixel = (t_fdot){	.x = p1.x + delta.x * i,\
							.y = p1.y + delta.y * i};
		if (0 <= pixel.y && pixel.y < win->h && 0 <= pixel.x && pixel.x < win->w)
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
	draw_line(win, (t_dot){rect.x + rect.w, rect.y}, (t_dot){rect.x + rect.w, rect.y + rect.h});
	draw_line(win, (t_dot){rect.x + rect.w, rect.y + rect.h}, (t_dot){rect.x, rect.y + rect.h});
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

void	draw_circle(t_win *win, t_circle circle)
{
	int		x;
	int		y;
	int		m;

	x = 0;
	y = circle.radius;
	m = 5 - 4 * circle.radius;
	while(x <= y)
	{
		SDL_RenderDrawPoint(win->rend, circle.x + x, y + circle.y);
		SDL_RenderDrawPoint(win->rend, circle.x + y, circle.y + x);
		SDL_RenderDrawPoint(win->rend, circle.x - x, y + circle.y);
		SDL_RenderDrawPoint(win->rend, circle.x - y, circle.y + x);
		SDL_RenderDrawPoint(win->rend, circle.x + x, circle.y - y);
		SDL_RenderDrawPoint(win->rend, circle.x + y, circle.y - x);
		SDL_RenderDrawPoint(win->rend, circle.x - x, circle.y - y);
		SDL_RenderDrawPoint(win->rend, circle.x - y, circle.y - x);
		if(m > 0)
		{
			y--;
			m = m - 8 * y;
		}
		x++;
		m = m + 8 * x + 4;
	}
}