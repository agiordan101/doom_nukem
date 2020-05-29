/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_set_menu_button_function.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:41 by gal               #+#    #+#             */
/*   Updated: 2020/05/19 09:20:51 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void		set_menu_button_function_first(t_win *win, t_map *map)
{
	ui_set_simple_button_function(win->winui,
								"b_select",
								&set_editor_flags,
								&map->editor.arg_menu_tab[0]);
	ui_set_simple_button_function(win->winui,
								"b_wall",
								&set_editor_flags,
								&map->editor.arg_menu_tab[1]);
	ui_set_simple_button_function(win->winui,
								"b_flat",
								&set_editor_flags,
								&map->editor.arg_menu_tab[2]);
	ui_set_simple_button_function(win->winui,
								"b_inclined",
								&set_editor_flags,
								&map->editor.arg_menu_tab[3]);
	ui_set_simple_button_function(win->winui,
								"b_player",
								&set_editor_flags,
								&map->editor.arg_menu_tab[4]);
	ui_set_simple_button_function(win->winui,
								"b_calc_normal",
								&set_editor_calc,
								&map->editor.arg_menu_tab[5]);
}

static void		set_menu_button_function_second(t_win *win, t_map *map)
{
	ui_set_simple_button_function(win->winui,
								"b_calc_z",
								&set_editor_calc,
								&map->editor.arg_menu_tab[6]);
	ui_set_simple_button_function(win->winui,
								"b_mob",
								&set_editor_flags,
								&map->editor.arg_menu_tab[7]);
	ui_set_simple_button_function(win->winui,
								"b_heal",
								&set_editor_flags,
								&map->editor.arg_menu_tab[8]);
	ui_set_simple_button_function(win->winui,
								"b_shield",
								&set_editor_flags,
								&map->editor.arg_menu_tab[9]);
	ui_set_simple_button_function(win->winui,
								"b_gravity",
								&set_editor_flags,
								&map->editor.arg_menu_tab[10]);
	ui_set_simple_button_function(win->winui,
								"b_bullet",
								&set_editor_flags,
								&map->editor.arg_menu_tab[11]);
}

static void		set_menu_button_function_third(t_win *win, t_map *map)
{
	ui_set_simple_button_function(win->winui,
								"b_box",
								&set_editor_flags,
								&map->editor.arg_menu_tab[12]);
	ui_set_simple_button_function(win->winui,
								"b_door",
								&set_editor_flags,
								&map->editor.arg_menu_tab[13]);
	ui_set_simple_button_function(win->winui,
								"b_end",
								&set_editor_flags,
								&map->editor.arg_menu_tab[14]);
	ui_set_simple_button_function(win->winui,
								"b_light",
								&set_editor_flags,
								&map->editor.arg_menu_tab[15]);
}

static void		set_menu_button_function_fourth(t_win *win, t_map *map)
{
	ui_set_simple_button_function(win->winui,
								"b_export",
								&ed_export,
								&map->editor.export);
	ui_set_simple_button_function(win->winui,
								"b_package",
								&ed_package,
								&map->editor.export);
	ui_set_simple_button_function(win->winui,
								"b_delete",
								&ed_delete_map,
								map);
}

void			ed_set_menu_button_function(t_win *win, t_map *map)
{
	set_menu_button_function_first(win, map);
	set_menu_button_function_second(win, map);
	set_menu_button_function_third(win, map);
	set_menu_button_function_fourth(win, map);
	ui_set_text_entry_function(win->winui, "b_z_min",
								&set_int_value, &map->editor.z_min);
	ui_set_text_entry_function(win->winui, "b_z_max",
								&set_int_value, &map->editor.z_max);
	ui_set_text_entry_function(win->winui, "b_export_path",
								&set_str_value, &map->editor.export.path);
}
