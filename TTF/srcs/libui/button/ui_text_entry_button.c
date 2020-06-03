/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_text_entry_button.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:33:29 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:14:50 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_button.h"
#include "libft.h"
#include "ui_error.h"

static void			ui_init_new_text_entry_button(
						t_text_entry_button *new_text_entry,
						char *name,
						void (*f)(void *argument,
								char *button_output),
						void *argument)
{
	new_text_entry->name = name;
	new_text_entry->max_int = 2147483647;
	new_text_entry->min_int = -2147483648;
	new_text_entry->text[new_text_entry->max_text_size] = '\0';
	new_text_entry->new_text[new_text_entry->max_text_size] = '\0';
	new_text_entry->f = f;
	new_text_entry->argument = argument;
	new_text_entry->text_side = UI_TEXT_SIDE_LEFT;
	new_text_entry->text_type = UI_TEXT_TYPE_NONE;
	new_text_entry->textures = (t_text_entry_set){NULL, NULL, NULL, NULL};
}

t_text_entry_button	*ui_new_text_entry_button(char *name,
													void (*f)(void *argument,
													char *button_output),
													void *argument,
													int max_text_size)
{
	t_text_entry_button	*new_text_entry;

	if (!(new_text_entry = (t_text_entry_button*)ft_memalloc(
							sizeof(t_text_entry_button))))
	{
		return (ui_ret_null_error("ui_new_text_entry_button",
									"new_text_entry allocation failed", NULL));
	}
	if (!(new_text_entry->text = (char*)ft_memalloc(
									sizeof(char) * (max_text_size + 1))))
	{
		return (ui_ret_null_error("ui_new_text_entry_button",
									"new_text_entry->text allocation failed",
									NULL));
	}
	if (!(new_text_entry->new_text = (char*)ft_memalloc(
										sizeof(char) * (max_text_size + 1))))
	{
		return (ui_ret_null_error("ui_new_text_entry_button",
									"new_text_entry->new_text\
									allocation failed", NULL));
	}
	new_text_entry->max_text_size = max_text_size;
	ui_init_new_text_entry_button(new_text_entry, name, f, argument);
	return (new_text_entry);
}

void				ui_free_text_entry_button(t_text_entry_button **text_entry)
{
	t_text_entry_button *b;

	b = *text_entry;
	if (b)
	{
		if (b->name)
			ft_strdel(&b->name);
		if (b->text)
			ft_strdel(&b->text);
		if (b->new_text)
			ft_strdel(&b->new_text);
		ui_free_text_entry_set(b->textures);
		free(b);
		*text_entry = NULL;
	}
}
