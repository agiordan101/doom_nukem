/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_place_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:20 by gal               #+#    #+#             */
/*   Updated: 2020/05/07 11:51:06 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

static t_poly	*ed_init_wall(t_map *map, t_dot p)
{
	t_poly	*poly;

	poly = NULL;
	if (!(poly = ft_memalloc(sizeof(t_poly))))
		return (NULL);
	poly->dots[0] = (t_fdot_3d){p.x, p.y, map->editor.settings.wall.max};
	poly->dots[1] = (t_fdot_3d){p.x, p.y, map->editor.settings.wall.max};
	poly->dots[2] = (t_fdot_3d){p.x, p.y, map->editor.settings.wall.min};
	poly->dots[3] = (t_fdot_3d){p.x, p.y, map->editor.settings.wall.min};
	poly->texture_name = ft_strdup(map->editor.settings.texture);
	poly->light_coef = 1;
	return (poly);
}

int				ed_place_wall(t_win *win, t_map *map)
{
	t_dot	p;

	p = ed_get_map_point(map, win->winui->mouse.pos);
	if (map->editor.flags & ED_DRAW_HELP)
		p = ed_is_next_to_poly(map, p, NEXT_RADIUS);
	if (!map->editor.placing_poly)
	{
		if (!(map->editor.placing_poly = ed_init_wall(map, p)))
			return (ui_ret_error("ed_place_wall",
			"placing_poly allocation failed", 0));
	}
	else
	{
		map->editor.placing_poly->dots[1].x = p.x;
		map->editor.placing_poly->dots[1].y = p.y;
		map->editor.placing_poly->dots[2].x = p.x;
		map->editor.placing_poly->dots[2].y = p.y;
	}
	return (1);
}
