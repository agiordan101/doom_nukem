#include "doom_nukem.h"

void	draw_line(t_win *win, t_dot p1, t_dot p2)
{
	int             i;
	int				n_pixels;
	t_fdot			delta;
	double			tmp;
	t_fdot			pixel;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	if (ft_abs(delta.x) > ft_abs(delta.y))
			tmp = delta.x;
	else
			tmp = delta.y;
	n_pixels = ft_abs(tmp);
	delta.x /= ft_abs(tmp);
	delta.y /= ft_abs(tmp);
	i = -1;
	while (i++ < n_pixels)
	{
		pixel = (t_fdot){.x = p1.x + delta.x * i, .y = p1.y + delta.y * i};
		if (pixel.y < win->h && pixel.y >= 0 && pixel.x < win->w && pixel.x >= 0)
				SDL_RenderDrawPoint(win->rend, pixel.x, pixel.y);
	}
}


void	draw_rect(t_win *win, SDL_Rect rect)
{
	draw_line(win, (t_dot){rect.x, rect.y}, (t_dot){rect.x + rect.w, rect.y});
	draw_line(win, (t_dot){rect.x + rect.w, rect.y}, (t_dot){rect.x + rect.w, rect.y + rect.h});
	draw_line(win, (t_dot){rect.x + rect.w, rect.y + rect.h}, (t_dot){rect.x, rect.y + rect.h});
	draw_line(win, (t_dot){rect.x, rect.y + rect.h}, (t_dot){rect.x, rect.y});
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