/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_manage_property.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:21:34 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:21:34 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	ed_clean_property(t_win *win, int i_start)
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
			text_entry->f = NULL;
		}
		ft_strdel(&id);
		i_start++;
	}
}

void	ed_set_property(t_win *win, t_property *p)
{
	t_text_entry_button	*text_entry;

	ui_set_text_entry_function(win->winui, p->id, p->fn, p->variable);
	text_entry = ui_get_text_entry_button(win->winui, p->id);
	if (text_entry)
	{
		if (text_entry->name)
		{
			ft_strdel(&text_entry->name);
			text_entry->name = ft_strdup(p->name);
		}
		ft_strcpy(text_entry->text, p->content);
	}
}
