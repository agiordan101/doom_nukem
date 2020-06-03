/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_delete_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:20:13 by gal               #+#    #+#             */
/*   Updated: 2020/05/07 13:05:41 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	ed_delete_object_polys_loop(t_map *map,
										t_poly *p,
										t_poly *tmp_prev,
										t_object *object)
{
	int		i;
	int		poly_count;
	t_poly	*tmp_next;

	i = 0;
	poly_count = ed_get_object_poly_count(object);
	while (p && i < poly_count)
	{
		if (!tmp_prev)
		{
			map->polys = p->next;
			free(p);
			p = map->polys;
		}
		else
		{
			tmp_next = p->next;
			free(p);
			tmp_prev->next = tmp_next;
			p = tmp_next;
		}
		i++;
	}
}

static void	ed_delete_object_polys(t_map *map,
								t_object *object)
{
	t_poly	*p;
	t_poly	*tmp_prev;

	tmp_prev = NULL;
	p = map->polys;
	if (map)
	{
		if (p != object->poly)
		{
			while (p && p->next != object->poly)
				p = p->next;
			if (p != map->polys)
				tmp_prev = p;
			p = p->next;
		}
		ed_delete_object_polys_loop(map, p, tmp_prev, object);
	}
}

static void	ed_delete_obj_link(t_object **objects,
								t_object **obj,
								t_object **tmp_prev,
								t_object **tmp_next)
{
	*tmp_next = (*obj)->next;
	if ((*obj)->texture)
		ft_strdel(&(*obj)->texture);
	free(*obj);
	if (*tmp_prev)
		(*tmp_prev)->next = *tmp_next;
	else
		*objects = *tmp_next;
	*obj = *tmp_next;
}

void		ed_delete_obj(t_map *map, t_object **objects, t_object *object)
{
	t_object	*obj;
	t_object	*tmp_prev;
	t_object	*tmp_next;

	tmp_next = NULL;
	if (map && objects && object)
	{
		ed_delete_object_polys(map, object);
		tmp_prev = NULL;
		obj = *objects;
		while (obj)
		{
			if (obj == object)
				ed_delete_obj_link(objects, &obj, &tmp_prev, &tmp_next);
			else
			{
				tmp_prev = obj;
				obj = obj->next;
			}
		}
	}
}
