/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_button.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:33:09 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:33:11 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_button.h"
#include "libft.h"
#include "ui_error.h"

t_button	*ui_new_button(t_button_type type,
							t_resize_type resize_type,
							t_frect ratio,
							void *data)
{
	t_button	*new_button;

	if (!(new_button = (t_button*)ft_memalloc(sizeof(t_button))))
	{
		return (ui_ret_null_error("ui_new_button",
								"new_button allocation failed",
								NULL));
	}
	new_button->id = NULL;
	new_button->data = data;
	new_button->type = type;
	new_button->resize_type = resize_type;
	new_button->ratio = ratio;
	new_button->next = NULL;
	return (new_button);
}

void		ui_add_button(t_button **buttons,
							t_button *new_button)
{
	if (new_button)
	{
		new_button->next = *buttons;
		*buttons = new_button;
	}
	else
		ui_ret_error("ui_add_button", "new_button is NULL", 0);
}

void		ui_free_button(t_button **button)
{
	t_button	*b;

	b = *button;
	if (b)
	{
		if (b->id)
			ft_strdel(&b->id);
		if (b->data)
		{
			if (b->type == UI_BUTTON_SIMPLE)
				ui_free_simple_button((t_simple_button**)&b->data);
			else if (b->type == UI_BUTTON_TEXT_ENTRY)
				ui_free_text_entry_button((t_text_entry_button**)&b->data);
			else if (b->type == UI_BUTTON_TEXT_AREA)
				ui_free_text_area((t_text_area**)&b->data);
		}
		b->next = NULL;
		free(b);
	}
	*button = NULL;
}

void		ui_free_buttons(t_button **buttons)
{
	t_button	*b;
	t_button	*next;

	b = *buttons;
	while (b)
	{
		next = b->next;
		ui_free_button(&b);
		b = next;
	}
}
