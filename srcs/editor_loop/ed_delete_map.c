/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_delete_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:10 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 19:50:44 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		ed_free_mob(t_mob **mob)
{
	t_mob	*m;

	m = *mob;
	if (m)
	{
		ft_strdel(&m->texture);
		free(m);
	}
	*mob = NULL;
}

static void		ed_free_poly(t_poly **poly)
{
	t_poly	*p;

	p = *poly;
	if (p)
	{
		ft_strdel(&p->texture_name);
		free(p);
	}
	*poly = NULL;
}

static void		ed_free_object(t_object **object)
{
	t_object	*obj;

	obj = *object;
	if (obj)
	{
		ft_strdel(&obj->texture);
		free(obj);
	}
	*object = NULL;
}

static void		ed_delete_mobs_and_objects(t_map *map)
{
	t_mob		*m;
	t_object	*obj;
	void		*next;

	m = map->mob;
	while (m)
	{
		next = m->next;
		ed_free_mob(&m);
		m = next;
	}
	map->mob = NULL;
	obj = map->objects;
	while (obj)
	{
		next = obj->next;
		ed_free_object(&obj);
		obj = next;
	}
	map->objects = NULL;
}

void			ed_delete_map(void *map_ptr)
{
	t_map		*map;
	t_poly		*p;
	void		*next;

	map = (t_map*)map_ptr;
	map->editor.list_selected = NULL;
	map->editor.selected = NULL;
	if (map)
	{
		p = map->polys;
		while (p)
		{
			next = p->next;
			ed_free_poly(&p);
			p = next;
		}
		map->polys = NULL;
		ed_delete_mobs_and_objects(map);
	}
}
