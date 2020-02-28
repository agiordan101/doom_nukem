#include "doom_nukem.h"
#include "ui_draw.h"

void		ed_display_wall(t_win *win, const t_map *map, t_poly *poly)
{
	t_line	line;

	line = ed_get_display_line(map,
			(t_dot){poly->dots[0].x, poly->dots[0].y},
			(t_dot){poly->dots[1].x, poly->dots[1].y});
	ui_draw_line(win->rend, &line);
}

void		ed_display_flat(t_win *win, const t_map *map, t_poly *poly)
{
	t_line	line;

	line = ed_get_display_line(map,
						(t_dot){poly->dots[0].x, poly->dots[0].y},
						(t_dot){poly->dots[1].x, poly->dots[1].y});
	ui_draw_line(win->rend, &line);
	line = ed_get_display_line(map,
						(t_dot){poly->dots[1].x, poly->dots[1].y},
						(t_dot){poly->dots[2].x, poly->dots[2].y});
	ui_draw_line(win->rend, &line);
	line = ed_get_display_line(map,
						(t_dot){poly->dots[2].x, poly->dots[2].y},
						(t_dot){poly->dots[3].x, poly->dots[3].y});
	ui_draw_line(win->rend, &line);
	line = ed_get_display_line(map,
						(t_dot){poly->dots[3].x, poly->dots[3].y},
						(t_dot){poly->dots[0].x, poly->dots[0].y});
	ui_draw_line(win->rend, &line);
	line = ed_get_display_line(map,
						(t_dot){poly->dots[0].x, poly->dots[0].y},
						(t_dot){poly->dots[2].x, poly->dots[2].y});
	ui_draw_line(win->rend, &line);
	line = ed_get_display_line(map,
						(t_dot){poly->dots[1].x, poly->dots[1].y},
						(t_dot){poly->dots[3].x, poly->dots[3].y});
	ui_draw_line(win->rend, &line);
}
