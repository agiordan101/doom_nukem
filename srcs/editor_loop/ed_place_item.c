/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_place_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:11 by gal               #+#    #+#             */
/*   Updated: 2020/05/19 08:48:52 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	ed_set_item_flag_next(t_map *map, t_object *obj)
{
	if (map->editor.flags & ED_GRAVITY)
	{
		obj->type = GRAVITY_INV;
		obj->texture = ft_strdup("pq.png");
	}
	else if (map->editor.flags & ED_BULLET)
	{
		obj->type = BULLET;
		obj->texture = ft_strdup("Ammo_box_icon.png");
	}
	else if (map->editor.flags & ED_BOX)
	{
		obj->type = BOX;
		obj->texture = ft_strdup(map->editor.settings.texture);
	}
	else if (map->editor.flags & ED_END)
	{
		obj->type = END;
		obj->texture = ft_strdup(map->editor.settings.texture);
	}
	else if (map->editor.flags & ED_LIGHT)
	{
		obj->type = LIGHT;
		obj->texture = ft_strdup(map->editor.settings.texture);
	}
}

static void	ed_set_item_flag_texture(t_map *map, t_object *obj)
{
	if (map->editor.flags & ED_HEAL)
	{
		obj->type = HEAL;
		obj->texture = ft_strdup("healthPotion.png");
	}
	else if (map->editor.flags & ED_SHIELD)
	{
		obj->type = ARMOR;
		obj->texture = ft_strdup("shieldPotion.png");
	}
	else
		ed_set_item_flag_next(map, obj);
}

void		ed_place_item(t_win *win, t_map *map)
{
	t_object	*obj;
	t_dot		pos;

	if (win->winui->mouse.releasing & UI_MOUSE_LEFT)
	{
		if ((obj = (t_object*)ft_memalloc(sizeof(t_object))))
		{
			pos = ed_get_map_point(map, win->winui->mouse.pos);
			ed_set_item_flag_texture(map, obj);
			obj->pos_rotz_only.x = pos.x;
			obj->pos_rotz_only.y = pos.y;
			obj->pos_rotz_only.z = map->editor.settings.object.z;
			obj->width = map->editor.settings.object.width;
			obj->height = map->editor.settings.object.width;
			obj->light_coef = 0.5;
			obj->poly = NULL;
			add_existing_object(&map->objects, obj);
		}
	}
}
