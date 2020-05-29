/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_selected.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 16:13:41 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 15:32:23 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

t_selected	*ed_new_selected(void *ptr, t_selected_type selected_type)
{
	t_selected	*selected;

	if (!(selected = ft_memalloc(sizeof(t_selected))))
	{
		return (ui_ret_null_error("ed_new_selected",
								"allocation failed", NULL));
	}
	selected->ptr = ptr;
	selected->selected_type = selected_type;
	selected->next = NULL;
	return (selected);
}

void		ed_add_selected(t_selected **list_selected, t_selected *selected)
{
	if (selected)
	{
		selected->next = *list_selected;
		*list_selected = selected;
	}
}

void		ed_free_selected(t_selected **list_selected)
{
	t_selected	*l;
	t_selected	*next;

	l = *list_selected;
	while (l)
	{
		next = l->next;
		free(l);
		l = next;
	}
	*list_selected = NULL;
}

void		ed_incre_selected(t_selected *list_selected, t_selected **selected)
{
	if (*selected)
	{
		*selected = (*selected)->next;
		if (!(*selected))
			*selected = list_selected;
	}
}
