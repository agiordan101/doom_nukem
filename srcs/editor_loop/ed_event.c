#include "doom_nukem.h"
#include "ui_error.h"

static SDL_bool	ed_is_mob_selected(t_win *win, const t_map *map, const t_mob *mob)
{
	if (ed_get_line_len(&(t_line){ed_get_map_point(map, win->winui->mouse.pos),
						(t_dot){mob->pos.x, mob->pos.y}}) < mob->width)
		return (SDL_TRUE);
	else
		return (SDL_FALSE);
}

static t_mob	*ed_get_selected_mob(t_win *win, const t_map *map)
{
	t_mob	*m;

	m = map->mob;
	while (m)
	{
		if (ed_is_mob_selected(win, map, m))
			return (m);
		m = m->next;
	}
	return (NULL);
}

static SDL_bool	ed_is_obj_selected(t_win *win, const t_map *map, const t_object *object)
{
	if (ed_get_line_len(&(t_line){ed_get_map_point(map, win->winui->mouse.pos),
						(t_dot){object->pos.x, object->pos.y}}) < object->width)
		return (SDL_TRUE);
	else
		return (SDL_FALSE);
}

static t_object	*ed_get_selected_obj(t_win *win, const t_map *map)
{
	t_object	*obj;

	obj = map->objects;
	while (obj)
	{
		if (ed_is_obj_selected(win, map, obj))
			return (obj);
		obj = obj->next;
	}
	return (NULL);
}

static void		set_int_value(void *argument, char *button_output)
{
	*((int*)argument) = ft_atoi(button_output);
}

static void		set_float_value(void *argument, char *button_output)
{
	*((float*)argument) = ft_atoi(button_output);
}

static void		set_coef_value(void *argument, char *button_output)
{
	*((float*)argument) = ft_atoi(button_output) / 100.f;
}

static void			set_wall_z1(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[0].z = ft_atoi(button_output);
	poly->dots[1].z = ft_atoi(button_output);
}

static void			set_wall_z2(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[2].z = ft_atoi(button_output);
	poly->dots[3].z = ft_atoi(button_output);
}


static void			set_flat_z(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[0].z = ft_atoi(button_output);
	poly->dots[1].z = ft_atoi(button_output);
	poly->dots[2].z = ft_atoi(button_output);
	poly->dots[3].z = ft_atoi(button_output);
}

static void			set_inclined_z1(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[0].z = ft_atoi(button_output);
	poly->dots[3].z = ft_atoi(button_output);
}

static void			set_inclined_z2(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[1].z = ft_atoi(button_output);
	poly->dots[2].z = ft_atoi(button_output);
}

static void		set_str_value(void *argument, char *button_output)
{
	if (*((char**)argument))
		ft_strdel((char**)argument);
	*((char**)argument) = ft_strdup(button_output);
}

static void	ed_clean_property(t_win *win, int i_start)
{
	t_text_entry_button	*text_entry;
	char				*id;
	char				*tmp;

	while (i_start < 9)
	{
		tmp = ft_itoa(i_start);
		id = ft_strjoin("b_property_", tmp);
		ft_strdel(&tmp);
		text_entry = ui_get_text_entry_button(win->winui, id);
		if (text_entry)
		{
			ft_bzero(text_entry->text, ft_strlen(text_entry->text));
			if (text_entry->name)
				ft_bzero(text_entry->name, ft_strlen(text_entry->name));
		}
		ft_strdel(&id);
		i_start++;
	}
}

static void	ed_set_buttons_wall(t_win *win, t_poly *selected)
{
	t_text_entry_button	*text_entry;
	char				*tmp;

	ui_set_text_entry_function(win->winui, "b_property_1", &set_str_value, &selected->texture_name);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_1");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("texture");
		}
		if (selected->texture_name && ft_strcmp(text_entry->text, selected->texture_name) != 0)
			ft_strcpy(text_entry->text, selected->texture_name);
	}
	ui_set_text_entry_function(win->winui, "b_property_2", &set_wall_z1, selected);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_2");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("z1");
		}
		tmp = ft_itoa(selected->dots[0].z);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_3", &set_wall_z2, selected);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_3");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("z2");
		}
		tmp = ft_itoa(selected->dots[2].z);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_4", &set_coef_value, &selected->light_coef);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_4");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("light %");
		}
		tmp = ft_itoa(selected->light_coef * 100);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ed_clean_property(win, 5);
}

static void	ed_set_buttons_flat(t_win *win, t_poly *selected)
{
	t_text_entry_button	*text_entry;
	char				*tmp;

	ui_set_text_entry_function(win->winui, "b_property_1", &set_str_value, &selected->texture_name);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_1");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("texture");
		}
		if (selected->texture_name && ft_strcmp(text_entry->text, selected->texture_name) != 0)
			ft_strcpy(text_entry->text, selected->texture_name);
	}
	ui_set_text_entry_function(win->winui, "b_property_2", &set_flat_z, selected);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_2");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("z");
		}
		tmp = ft_itoa(selected->dots[0].z);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_3", &set_coef_value, &selected->light_coef);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_3");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("light %");
		}
		tmp = ft_itoa(selected->light_coef * 100);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ed_clean_property(win, 4);
}

static void	ed_set_buttons_inclined(t_win *win, t_poly *selected)
{
	t_text_entry_button	*text_entry;
	char				*tmp;

	ui_set_text_entry_function(win->winui, "b_property_1", &set_str_value, &selected->texture_name);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_1");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("texture");
		}
		if (selected->texture_name && ft_strcmp(text_entry->text, selected->texture_name) != 0)
			ft_strcpy(text_entry->text, selected->texture_name);
	}
	ui_set_text_entry_function(win->winui, "b_property_2", &set_inclined_z1, selected);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_2");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("z1");
		}
		tmp = ft_itoa(selected->dots[0].z);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_3", &set_inclined_z2, selected);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_3");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("z2");
		}
		tmp = ft_itoa(selected->dots[1].z);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_4", &set_coef_value, &selected->light_coef);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_4");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("light %");
		}
		tmp = ft_itoa(selected->light_coef * 100);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ed_clean_property(win, 5);
}

static void	ed_set_buttons_mob(t_win *win, t_mob *selected)
{
	t_text_entry_button	*text_entry;
	char				*tmp;

	ui_set_text_entry_function(win->winui, "b_property_1", &set_str_value, &selected->texture);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_1");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("texture");
		}
		if (selected->texture && ft_strcmp(text_entry->text, selected->texture) != 0)
			ft_strcpy(text_entry->text, selected->texture);
	}
	ui_set_text_entry_function(win->winui, "b_property_2", &set_float_value, &selected->pos.z);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_2");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("z");
		}
		tmp = ft_itoa(selected->pos.z);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_3", &set_int_value, &selected->width);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_3");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("width");
		}
		tmp = ft_itoa(selected->width);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_4", &set_int_value, &selected->height);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_4");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("height");
		}
		tmp = ft_itoa(selected->height);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_5", &set_int_value, &selected->health);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_5");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("health");
		}
		tmp = ft_itoa(selected->health);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_6", &set_int_value, &selected->damage);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_6");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("damage");
		}
		tmp = ft_itoa(selected->damage);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_7", &set_int_value, &selected->vel);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_7");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("velocity");
		}
		tmp = ft_itoa(selected->vel);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_8", &set_coef_value, &selected->light_coef);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_8");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("light %");
		}
		tmp = ft_itoa(selected->light_coef * 100);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
}


static void	ed_set_buttons_object(t_win *win, t_object *selected)
{
	t_text_entry_button	*text_entry;
	char				*tmp;

	ui_set_text_entry_function(win->winui, "b_property_1", &set_str_value, &selected->texture);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_1");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("texture");
		}
		if (selected->texture && ft_strcmp(text_entry->text, selected->texture) != 0)
			ft_strcpy(text_entry->text, selected->texture);
	}
	ui_set_text_entry_function(win->winui, "b_property_2", &set_float_value, &selected->pos.z);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_2");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("z");
		}
		tmp = ft_itoa(selected->pos.z);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_3", &set_int_value, &selected->width);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_3");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("width");
		}
		tmp = ft_itoa(selected->width);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_4", &set_int_value, &selected->height);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_4");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("height");
		}
		tmp = ft_itoa(selected->height);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ui_set_text_entry_function(win->winui, "b_property_5", &set_coef_value, &selected->light_coef);
	text_entry = ui_get_text_entry_button(win->winui, "b_property_5");
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup("light %");
		}
		tmp = ft_itoa(selected->light_coef * 100);
		ft_strcpy(text_entry->text, tmp);
		ft_strdel(&tmp);
	}
	ed_clean_property(win, 6);
}

static void	ed_selection(t_win *win, t_map *map)
{
	if (win->winui->mouse.clicking & UI_MOUSE_LEFT || win->winui->mouse.clicking & UI_MOUSE_RIGHT)
	{	
		map->editor.select_rect.x = ed_get_map_x(map, win->winui->mouse.pos.x);
		map->editor.select_rect.y = ed_get_map_y(map, win->winui->mouse.pos.y);
		map->editor.select_rect.w = 0;
		map->editor.select_rect.h = 0;
	}
	else if (win->winui->mouse.clicked & UI_MOUSE_LEFT || win->winui->mouse.clicked & UI_MOUSE_RIGHT)
	{
		map->editor.select_rect.w = ed_get_map_x(map, win->winui->mouse.pos.x)
									- map->editor.select_rect.x;
		map->editor.select_rect.h = ed_get_map_y(map, win->winui->mouse.pos.y)
									- map->editor.select_rect.y;
		if ((map->editor.selected_mob = ed_get_selected_mob(win, map)))
		{
			ed_set_buttons_mob(win, map->editor.selected_mob);
			map->editor.selected_obj = NULL;
			map->editor.selected_poly = NULL;
		}
		else if ((map->editor.selected_obj = ed_get_selected_obj(win, map)))
		{
			ed_set_buttons_object(win, map->editor.selected_obj);
			map->editor.selected_mob = NULL;
			map->editor.selected_poly = NULL;
		}
		else if ((map->editor.selected_poly = ed_get_selected_poly(win, map)))
		{
			if (ed_is_wall(map->editor.selected_poly))
				ed_set_buttons_wall(win, map->editor.selected_poly);
			else if (ed_is_flat(map->editor.selected_poly))
				ed_set_buttons_flat(win, map->editor.selected_poly);
			else if (ed_is_inclined(map->editor.selected_poly))
				ed_set_buttons_inclined(win, map->editor.selected_poly);
			map->editor.selected_mob = NULL;
			map->editor.selected_obj = NULL;
		}
		else
		{
			ed_clean_property(win, 1);
			map->editor.selected_mob = NULL;
			map->editor.selected_poly = NULL;
			map->editor.selected_obj = NULL;	
		}
	}
}

static int	ed_add_mob(t_win *win, t_map *map)
{
	t_mob	*mob;

	if (!(mob = ft_memalloc(sizeof(t_mob))))
		return (ui_ret_error("ed_add_mob", "mob allocation failed", 0));
	mob->pos.x = ed_get_map_x(map, win->winui->mouse.pos.x);
	mob->pos.y = ed_get_map_y(map, win->winui->mouse.pos.y);
	mob->pos.z = map->editor.settings.mob.z;
	mob->width = map->editor.settings.mob.width;
	mob->height = map->editor.settings.mob.height;
	mob->health = map->editor.settings.mob.health;
	mob->damage = map->editor.settings.mob.damage;
	mob->vel = map->editor.settings.mob.velocity;
	mob->texture = ft_strdup(map->editor.settings.texture);
	add_existing_mob(&map->mob, mob);
	return (1);
}

static void	ed_place_poly(t_win *win, t_map *map)
{
	SDL_bool	call_place;

	call_place = SDL_FALSE;
	if (win->winui->mouse.releasing & UI_MOUSE_LEFT && !(map->editor.flags & ED_FLAT)
													&& !(map->editor.flags & ED_INCLINED))
	{
		if (map->editor.flags & ED_MOB)
			ed_add_mob(win, map);
		else
		{
			add_existing_poly(&map->polys, map->editor.placing_poly);
			map->editor.placing_poly = NULL;
		}
	}
	else if (win->winui->mouse.clicked & UI_MOUSE_LEFT)
	{
		if (map->editor.flags & ED_WALL)
			ed_place_wall(win, map);
	}
	if (map->editor.flags & ED_FLAT || map->editor.flags & ED_INCLINED)
	{
		if (win->winui->mouse.clicking & UI_MOUSE_LEFT
		|| (win->winui->mouse.releasing & UI_MOUSE_LEFT && map->editor.place_step != 0))
			map->editor.place_step++;
		if (map->editor.place_step == 0
		&& win->winui->mouse.clicking & UI_MOUSE_LEFT)
			call_place = 1;
		else if (map->editor.place_step == 1
		&& win->winui->mouse.clicked & UI_MOUSE_LEFT)
			call_place = 1;
		else if (map->editor.place_step == 2)
			call_place = 1;
		else if (map->editor.place_step == 3)
		{
			add_existing_poly(&map->polys, map->editor.placing_poly);
			map->editor.placing_poly = NULL;
			map->editor.place_step = 0; 
		}
		if (call_place)
		{
			if (map->editor.flags & ED_FLAT)
				ed_place_flat(win, map);
			else if (map->editor.flags & ED_INCLINED)
				ed_place_inclined(win, map);
		}
	}
}

static void	ed_place_item(t_win *win, t_map *map)
{
	t_object	*obj;
	t_dot		pos;

	if (win->winui->mouse.releasing & UI_MOUSE_LEFT)
	{
		if ((obj = (t_object*)ft_memalloc(sizeof(t_object))))
		{
			pos = ed_get_map_point(map, win->winui->mouse.pos);
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
			else if (map->editor.flags & ED_GRAVITY)
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
				obj->texture = map->editor.settings.texture;
			}
			obj->pos.x = pos.x;
			obj->pos.y = pos.y;
			obj->pos.z = map->editor.settings.object.z;
			obj->width = map->editor.settings.object.width;
			obj->height = map->editor.settings.object.width;
			add_existing_object(&map->objects, obj);
		}
	}
}

static void	ed_action(t_win *win, t_map *map)
{
	// else if (map->editor.flags & ED_PLAYER)
	// 	ed_place_player(win, map);
	if ((win->winui->mouse.clicked & UI_MOUSE_RIGHT || map->editor.flags & ED_SELECTION) && !win->winui->ui.on_mouse_button)
		ed_selection(win, map);
	else if (map->editor.flags & ED_PLAYER  && !win->winui->ui.on_mouse_button)
		ed_place_player(win, map);
	else if ((map->editor.flags & ED_HEAL || map->editor.flags & ED_SHIELD || map->editor.flags & ED_GRAVITY || map->editor.flags & ED_BULLET || map->editor.flags & ED_BOX) && !win->winui->ui.on_mouse_button)
		ed_place_item(win , map);
	else if (map->editor.flags & ED_PLACE && !win->winui->ui.on_mouse_button)
		ed_place_poly(win, map);
	if (map->editor.flags & ED_MODE_CHANGED)
	{
		map->editor.flags ^= ED_MODE_CHANGED;
		if (map->editor.flags & ED_SELECTION || map->editor.flags & ED_PLACE)
			SDL_SetCursor(map->editor.cursor[CURSOR_SELECTING]);
		else
			SDL_SetCursor(map->editor.cursor[CURSOR_DEFAULT]);
	}
}

void	ed_delete_mob(t_mob **mobs, t_mob *mob)
{
	t_mob	*m;
	t_mob	*tmp_prev;
	t_mob	*tmp_next;

	if (mobs && mob)
	{
		tmp_prev = NULL;
		m = *mobs;
		while (m)
		{
			if (m == mob)			
			{
				tmp_next = m->next;
				free(m);
				if (tmp_prev)
					tmp_prev->next = tmp_next;
				else
					*mobs = tmp_next;
				m = tmp_next;
			}
			else
			{
				tmp_prev = m;
				m = m->next;
			}
		}
	}
}

void	ed_delete_obj(t_object **objects, t_object *object)
{
	t_object	*obj;
	t_object	*tmp_prev;
	t_object	*tmp_next;

	if (objects && object)
	{
		tmp_prev = NULL;
		obj = *objects;
		while (obj)
		{
			if (obj == object)
			{
				tmp_next = obj->next;
				free(obj);
				if (tmp_prev)
					tmp_prev->next = tmp_next;
				else
					*objects = tmp_next;
				obj = tmp_next;
			}
			else
			{
				tmp_prev = obj;
				obj = obj->next;
			}
		}
	}
}

int 		ed_event(t_win *win, t_map *map)
{
	const Uint8	*state;
	int			vel;

	state = SDL_GetKeyboardState(NULL);
	if (!win->winui->ui.clicked_button)
	{
		vel = 3;
		if (state[SDL_SCANCODE_LSHIFT])
			vel += 4;
		if (state[SDL_SCANCODE_A])
			map->editor.pos.x -= vel;
		if (state[SDL_SCANCODE_D])
			map->editor.pos.x += vel;
		if (state[SDL_SCANCODE_W])
			map->editor.pos.y -= vel;
		if (state[SDL_SCANCODE_S])
			map->editor.pos.y += vel;
	}
	if (state[SDL_SCANCODE_DELETE] && (map->editor.selected_poly || map->editor.selected_mob || map->editor.selected_obj))
	{
		ed_clean_property(win, 1);
		if (map->editor.selected_poly)
		{
			delete_poly(&map->polys, map->editor.selected_poly);
			map->editor.selected_poly = NULL;
		}
		else if (map->editor.selected_mob)
		{
			ed_delete_mob(&map->mob, map->editor.selected_mob);
			map->editor.selected_mob = NULL;
		}
		else if (map->editor.selected_obj)
		{
			ed_delete_obj(&map->objects, map->editor.selected_obj);
			map->editor.selected_obj = NULL;
		}
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		if (map->editor.flags & ED_DRAW_HELP)
			map->editor.flags ^= ED_DRAW_HELP;
	}
	else
	{
		if (!(map->editor.flags & ED_DRAW_HELP))
			map->editor.flags |= ED_DRAW_HELP;
	}
	if(win->winui->event.type == SDL_MOUSEWHEEL)
	{
		map->editor.unit += win->winui->event.wheel.y * 0.01;
		win->winui->event.wheel.y = 0;
	}
	ed_action(win, map);
	return (1);
}
