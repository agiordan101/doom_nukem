/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_display_poly.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:29 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:29:22 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_draw.h"

void		ed_display_wall(t_win *win, const t_map *map, t_poly *poly)
{
	t_line	line;

	line = ed_get_display_line(map,
			(t_dot){poly->dots[0].x, poly->dots[0].y},
			(t_dot){poly->dots[1].x, poly->dots[1].y});
	draw_line(win, line.p1, line.p2);
}

void		ed_display_flat(t_win *win, const t_map *map, t_poly *poly)
{
	t_line	line;

	line = ed_get_display_line(map, (t_dot){poly->dots[0].x, poly->dots[0].y},
									(t_dot){poly->dots[1].x, poly->dots[1].y});
	draw_line(win, line.p1, line.p2);
	line = ed_get_display_line(map, (t_dot){poly->dots[1].x, poly->dots[1].y},
									(t_dot){poly->dots[2].x, poly->dots[2].y});
	draw_line(win, line.p1, line.p2);
	line = ed_get_display_line(map, (t_dot){poly->dots[2].x, poly->dots[2].y},
									(t_dot){poly->dots[3].x, poly->dots[3].y});
	draw_line(win, line.p1, line.p2);
	line = ed_get_display_line(map, (t_dot){poly->dots[3].x, poly->dots[3].y},
									(t_dot){poly->dots[0].x, poly->dots[0].y});
	draw_line(win, line.p1, line.p2);
	line = ed_get_display_line(map, (t_dot){poly->dots[0].x, poly->dots[0].y},
									(t_dot){poly->dots[2].x, poly->dots[2].y});
	draw_line(win, line.p1, line.p2);
	line = ed_get_display_line(map, (t_dot){poly->dots[1].x, poly->dots[1].y},
									(t_dot){poly->dots[3].x, poly->dots[3].y});
	draw_line(win, line.p1, line.p2);
}

void		ed_display_poly(t_win *win, const t_map *map, t_poly *poly)
{
	if (ed_is_wall(poly))
		ed_display_wall(win, map, poly);
	else if (ed_is_flat(poly))
		ed_display_flat(win, map, poly);
	else if (ed_is_inclined(poly))
		ed_display_inclined(win, map, poly);
}
