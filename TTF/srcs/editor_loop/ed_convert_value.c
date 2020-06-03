/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_convert_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:02 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:20:03 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_line		ed_get_display_line(const t_map *map, t_dot p1, t_dot p2)
{
	t_line	line;

	line.p1.x = (p1.x - map->editor.pos.x) * map->editor.unit;
	line.p1.y = (p1.y - map->editor.pos.y) * map->editor.unit;
	line.p2.x = (p2.x - map->editor.pos.x) * map->editor.unit;
	line.p2.y = (p2.y - map->editor.pos.y) * map->editor.unit;
	return (line);
}

t_dot		ed_get_display_point(const t_map *map, t_dot p)
{
	t_dot	point;

	point.x = (p.x - map->editor.pos.x) * map->editor.unit;
	point.y = (p.y - map->editor.pos.y) * map->editor.unit;
	return (point);
}

int			ed_get_map_x(const t_map *map, int n)
{
	return (n / map->editor.unit + map->editor.pos.x);
}

int			ed_get_map_y(const t_map *map, int n)
{
	return (n / map->editor.unit + map->editor.pos.y);
}

t_dot		ed_get_map_point(const t_map *map, t_dot p)
{
	t_dot	point;

	point.x = ed_get_map_x(map, p.x);
	point.y = ed_get_map_y(map, p.y);
	return (point);
}
