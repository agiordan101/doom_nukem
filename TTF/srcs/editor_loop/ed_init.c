/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:21:21 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 20:00:26 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		init_map_editor_settings(t_map *map)
{
	map->editor.settings.wall.min = 0;
	map->editor.settings.wall.max = 100;
	map->editor.settings.mob.z = 5;
	map->editor.settings.mob.width = 30;
	map->editor.settings.mob.height = 30;
	map->editor.settings.mob.damage = 1;
	map->editor.settings.mob.health = 50;
	map->editor.settings.mob.velocity = 1;
	map->editor.settings.flat_z = 0;
	map->editor.settings.inclined.z1 = 0;
	map->editor.settings.inclined.z2 = 100;
	map->editor.settings.texture = ft_strdup("brique.png");
	map->editor.settings.object.z = 0;
	map->editor.settings.object.width = 30;
}

static void		init_map_editor_arg_tab_bis(t_map *map)
{
	map->editor.arg_menu_tab[7] = (t_arg_menu){(int*)&map->editor.flags,
											ED_MOB};
	map->editor.arg_menu_tab[8] = (t_arg_menu){(int*)&map->editor.flags,
											ED_HEAL};
	map->editor.arg_menu_tab[9] = (t_arg_menu){(int*)&map->editor.flags,
											ED_SHIELD};
	map->editor.arg_menu_tab[10] = (t_arg_menu){(int*)&map->editor.flags,
											ED_GRAVITY};
	map->editor.arg_menu_tab[11] = (t_arg_menu){(int*)&map->editor.flags,
											ED_BULLET};
	map->editor.arg_menu_tab[12] = (t_arg_menu){(int*)&map->editor.flags,
											ED_BOX};
	map->editor.arg_menu_tab[13] = (t_arg_menu){(int*)&map->editor.flags,
											ED_DOOR};
	map->editor.arg_menu_tab[14] = (t_arg_menu){(int*)&map->editor.flags,
											ED_END};
	map->editor.arg_menu_tab[15] = (t_arg_menu){(int*)&map->editor.flags,
											ED_LIGHT};
}

static void		init_map_editor_arg_tab(t_map *map)
{
	map->editor.arg_menu_tab[0] = (t_arg_menu){(int*)&map->editor.flags,
											ED_SELECTION};
	map->editor.arg_menu_tab[1] = (t_arg_menu){(int*)&map->editor.flags,
											ED_WALL};
	map->editor.arg_menu_tab[2] = (t_arg_menu){(int*)&map->editor.flags,
											ED_FLAT};
	map->editor.arg_menu_tab[3] = (t_arg_menu){(int*)&map->editor.flags,
											ED_INCLINED};
	map->editor.arg_menu_tab[4] = (t_arg_menu){(int*)&map->editor.flags,
											ED_PLAYER};
	map->editor.arg_menu_tab[5] = (t_arg_menu){(int*)&map->editor.calc,
											ED_CALC_NORMAL};
	map->editor.arg_menu_tab[6] = (t_arg_menu){(int*)&map->editor.calc,
											ED_CALC_Z};
}

static void		init_map_export(t_win *win, t_map *map)
{
	t_text_entry_button	*text_entry;

	if ((text_entry = ui_get_text_entry_button(win->winui, "b_export_path")))
	{
		if (!map->editor.export.path)
		{
			if ((map->editor.export.path =
				ft_memalloc(sizeof(char) * (text_entry->max_text_size + 1))))
				ft_strcpy(text_entry->text, map->editor.export.path);
		}
	}
	map->editor.export.map = map;
}

void			ed_init_map_editor(t_win *win, t_map *map)
{
	map->editor.pos = (t_dot){0, 0};
	map->editor.size = (t_dot){0, 0};
	map->editor.unit = 1;
	map->editor.z_min = 0;
	map->editor.z_max = 100;
	map->editor.place_step = 0;
	map->editor.list_selected = NULL;
	map->editor.selected = NULL;
	map->editor.placing_poly = NULL;
	map->editor.placing_door = NULL;
	map->editor.flags = ED_NONE;
	map->editor.calc = ED_CALC_NORMAL;
	init_map_export(win, map);
	init_map_editor_settings(map);
	init_map_editor_arg_tab(map);
	init_map_editor_arg_tab_bis(map);
	map->editor.cursor[CURSOR_DEFAULT] =
	SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
	map->editor.cursor[CURSOR_SELECTING] =
	SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_CROSSHAIR);
}
