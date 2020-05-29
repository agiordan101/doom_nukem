/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:36 by gal               #+#    #+#             */
/*   Updated: 2020/05/19 09:16:11 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	ed_remove_flags_next(t_arg_menu *arg_menu)
{
	if (*(arg_menu->loop) & ED_BOX)
		*(arg_menu->loop) ^= ED_BOX;
	else if (*(arg_menu->loop) & ED_DOOR)
		*(arg_menu->loop) ^= ED_DOOR;
	else if (*(arg_menu->loop) & ED_PLAYER)
		*(arg_menu->loop) ^= ED_PLAYER;
	else if (*(arg_menu->loop) & ED_MOB)
		*(arg_menu->loop) ^= ED_MOB;
	else if (*(arg_menu->loop) & ED_END)
		*(arg_menu->loop) ^= ED_END;
	else if (*(arg_menu->loop) & ED_LIGHT)
		*(arg_menu->loop) ^= ED_LIGHT;
}

static void	ed_remove_flags(t_arg_menu *arg_menu)
{
	if (*(arg_menu->loop) & ED_WALL)
		*(arg_menu->loop) ^= ED_WALL;
	else if (*(arg_menu->loop) & ED_FLAT)
		*(arg_menu->loop) ^= ED_FLAT;
	else if (*(arg_menu->loop) & ED_INCLINED)
		*(arg_menu->loop) ^= ED_INCLINED;
	else if (*(arg_menu->loop) & ED_HEAL)
		*(arg_menu->loop) ^= ED_HEAL;
	else if (*(arg_menu->loop) & ED_SHIELD)
		*(arg_menu->loop) ^= ED_SHIELD;
	else if (*(arg_menu->loop) & ED_GRAVITY)
		*(arg_menu->loop) ^= ED_GRAVITY;
	else if (*(arg_menu->loop) & ED_BULLET)
		*(arg_menu->loop) ^= ED_BULLET;
	else
		ed_remove_flags_next(arg_menu);
}

static void	ed_remove_loop_flags(t_arg_menu *arg_menu)
{
	ed_remove_flags(arg_menu);
	if (*(arg_menu->loop) & ED_SELECTION)
		*(arg_menu->loop) ^= ED_SELECTION;
	*(arg_menu->loop) |= arg_menu->value;
}

static void	ed_add_value(t_arg_menu *arg_menu)
{
	*(arg_menu->loop) |= arg_menu->value;
	if (*(arg_menu->loop) & ED_WALL)
		*(arg_menu->loop) ^= ED_WALL;
	else if (*(arg_menu->loop) & ED_FLAT)
		*(arg_menu->loop) ^= ED_FLAT;
	else if (*(arg_menu->loop) & ED_INCLINED)
		*(arg_menu->loop) ^= ED_INCLINED;
	if (*(arg_menu->loop) & ED_PLACE)
		*(arg_menu->loop) ^= ED_PLACE;
}

void		set_editor_flags(void *argument)
{
	t_arg_menu	*arg_menu;

	arg_menu = (t_arg_menu*)argument;
	if (ED_ALL_TYPES & arg_menu->value)
	{
		if (*(arg_menu->loop) & arg_menu->value)
		{
			*(arg_menu->loop) ^= arg_menu->value;
			*(arg_menu->loop) ^= ED_PLACE;
		}
		else
		{
			ed_remove_loop_flags(arg_menu);
			*(arg_menu->loop) |= ED_PLACE;
		}
	}
	else
	{
		if (*(arg_menu->loop) & arg_menu->value)
			*(arg_menu->loop) ^= arg_menu->value;
		else
			ed_add_value(arg_menu);
	}
	*(arg_menu->loop) |= ED_MODE_CHANGED;
}
