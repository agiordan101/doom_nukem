/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_frame.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:33:58 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:34:04 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_frame.h"
#include "libft.h"
#include "ui_error.h"

t_frame		*ui_new_frame(t_frame_type type,
							t_resize_type resize_type,
							t_frect ratio,
							void *data)
{
	t_frame	*frame;

	if (!(frame = (t_frame*)ft_memalloc(sizeof(t_frame))))
	{
		return (ui_ret_null_error("ui_new_frame",
				"frame allocation failed", NULL));
	}
	frame->type = type;
	frame->resize_type = resize_type;
	frame->ratio = ratio;
	frame->data = data;
	frame->next = NULL;
	frame->buttons = NULL;
	return (frame);
}

void		ui_add_frame(t_frame **frames, t_frame *new_frame)
{
	if (new_frame)
	{
		new_frame->next = *frames;
		*frames = new_frame;
	}
}

void		ui_free_frame(t_frame **frame)
{
	t_frame	*f;

	f = *frame;
	if (f)
	{
		if (f->buttons)
			ui_free_buttons(&f->buttons);
		if (f->data)
		{
			if (f->type == UI_FRAME_SIMPLE)
				ui_free_simple_frame((t_simple_frame**)&f->data);
		}
		f->next = NULL;
		free(f);
		*frame = NULL;
	}
}

void		ui_free_frames(t_frame **frames)
{
	t_frame	*f;
	t_frame *next;

	f = *frames;
	while (f)
	{
		next = f->next;
		ui_free_frame(&f);
		f = next;
	}
}
