/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:05:10 by aducimet          #+#    #+#             */
/*   Updated: 2020/05/19 17:22:16 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

int			ft_data_storing2(t_poly **poly, t_map *map, char **tab, int i)
{
	if (ft_strstr(tab[i], "Polygon"))
		ft_fill_data(map, tab, poly, i);
	else if (ft_strstr(tab[i], "Object"))
	{
		if (object_data(tab, &(map->objects), i))
			return (ui_ret_error("ft_data_storing2", "object_data", -1));
	}
	else if (ft_strstr(tab[i], "Player"))
		player_data(tab, &(map->player), i);
	if (ft_strstr(tab[i], "Sphere"))
		new_sphere(&(map->sky_box), tab, i);
	else if (ft_strstr(tab[i], "Mob"))
	{
		if (fill_mob_data(&(map->mob), tab, i) == -1)
			return (ui_ret_error("ft_data_storing2", "fill_mob_data", -1));
	}
	return (0);
}

void		clear_leaks_obj(t_map *map)
{
	t_object	*object_tmp_next;

	if (map->objects)
	{
		while (map->objects)
		{
			object_tmp_next = map->objects->next;
			free(map->objects);
			map->objects = object_tmp_next;
		}
		map->objects = NULL;
	}
}

void		clear_leaks(t_map *map)
{
	t_poly		*poly_tmp_next;
	t_mob		*mob_tmp_next;

	if (map->editor.export.path)
		ft_strdel(&map->editor.export.path);
	if (map->polys)
	{
		while (map->polys)
		{
			poly_tmp_next = map->polys->next;
			free(map->polys);
			map->polys = poly_tmp_next;
		}
		map->polys = NULL;
	}
	if (map->mob)
	{
		while (map->mob)
		{
			mob_tmp_next = map->mob->next;
			free(map->mob);
			map->mob = mob_tmp_next;
		}
		map->mob = NULL;
	}
}
