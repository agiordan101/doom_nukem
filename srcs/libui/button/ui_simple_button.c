/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_simple_button.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:33:14 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:33:17 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_button.h"
#include "libft.h"
#include "ui_error.h"

t_simple_button		*ui_new_simple_button(t_mouse_button clicked_condition,
												void (*f)(void *argument),
												void *argument,
												t_simple_set textures)
{
	t_simple_button	*new_simple;

	if (!(new_simple = (t_simple_button*)ft_memalloc(
						sizeof(t_simple_button))))
	{
		return (ui_ret_null_error("ui_new_simple_button",
									"new_simple allocation_failed",
									NULL));
	}
	new_simple->textures = textures;
	new_simple->clicked_condition = clicked_condition;
	new_simple->f = f;
	new_simple->argurment = argument;
	new_simple->text = NULL;
	return (new_simple);
}

void				ui_free_simple_button(t_simple_button **simple_button)
{
	t_simple_button	*b;

	b = *simple_button;
	if (b)
	{
		if (b->text)
			ft_strdel(&b->text);
		ui_free_simple_set(b->textures);
		free(b);
	}
	*simple_button = NULL;
}
