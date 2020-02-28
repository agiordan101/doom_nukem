#include "doom_nukem.h"
#include "ui_draw.h"

static t_line	ed_get_heighest_line(t_poly *poly)
{
	if (poly->dots[0].z > poly->dots[1].z)
		return ((t_line){(t_dot){poly->dots[0].x, poly->dots[0].y},
						(t_dot){poly->dots[3].x, poly->dots[3].y}});
	else
		return ((t_line){(t_dot){poly->dots[1].x, poly->dots[1].y},
						(t_dot){poly->dots[2].x, poly->dots[2].y}});	

}

static t_line	ed_get_lowest_line(t_poly *poly)
{
	if (poly->dots[0].z < poly->dots[1].z)
		return ((t_line){(t_dot){poly->dots[0].x, poly->dots[0].y},
						(t_dot){poly->dots[3].x, poly->dots[3].y}});
	else
		return ((t_line){(t_dot){poly->dots[1].x, poly->dots[1].y},
						(t_dot){poly->dots[2].x, poly->dots[2].y}});	
}

int				ed_get_line_len(t_line *line)
{
	int	dx;
	int	dy;

	dx = line->p1.x - line->p2.x;
	dy = line->p1.y - line->p2.y;
	return (sqrt(dx * dx + dy * dy));
}

static void		ed_display_inclined_direction(t_win *win,
                                            const t_map *map,
                                            t_poly *poly)
{
	t_line	highest;
	t_line	lowest;
	t_line	display_line;
	t_dot	middle_lowest;
	t_dot	circle_point;

	highest = ed_get_heighest_line(poly);
	lowest = ed_get_lowest_line(poly);
	middle_lowest = (t_dot){(lowest.p1.x + lowest.p2.x) / 2,
							(lowest.p1.y + lowest.p2.y) / 2};
	display_line = ed_get_display_line(map, (t_dot){(highest.p1.x + highest.p2.x) / 2,
													(highest.p1.y + highest.p2.y) / 2},
											middle_lowest);
	ui_draw_line(win->rend, &display_line);
	circle_point = ed_get_display_point(map, middle_lowest);
	draw_circle(win, (t_circle){circle_point.x, circle_point.y, ed_get_line_len(&display_line) / 20});
}

void		ed_display_inclined(t_win *win, const t_map *map, t_poly *poly)
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
	ed_display_inclined_direction(win, map, poly);
}
