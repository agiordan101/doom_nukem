/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_text_area.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:33:22 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:33:25 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_button.h"
#include "ui_error.h"
#include "libft.h"

t_text_area		*ui_new_text_area(const char *text,
									float text_height,
									t_text_align text_align,
									t_resize_text resize_text)
{
	t_text_area	*text_area;

	if (!(text_area = (t_text_area*)ft_memalloc(sizeof(t_text_area))))
	{
		return (ui_ret_null_error("ui_new_text_area",
				"text_area allocation failed", NULL));
	}
	text_area->text = ft_strdup(text);
	text_area->text_height = text_height;
	text_area->text_align = text_align;
	text_area->resize_text = resize_text;
	text_area->text_color = (SDL_Color){255, 255, 255, 255};
	return (text_area);
}

void			ui_free_text_area(t_text_area **text_area)
{
	t_text_area	*t;

	t = *text_area;
	if (t)
	{
		if (t->text)
			ft_strdel(&t->text);
		free(t);
		*text_area = NULL;
	}
}
