/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_simple_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:34:06 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:15:17 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_frame.h"
#include "libft.h"
#include "ui_error.h"

t_simple_frame	*ui_new_simple_frame(char *text,
										t_frect text_ratio,
										SDL_Texture *texture,
										SDL_Texture *text_background)
{
	t_simple_frame	*simple_frame;

	if (!(simple_frame = (t_simple_frame*)ft_memalloc(sizeof(t_simple_frame))))
	{
		return (ui_ret_null_error("ui_new_simple_frame",
				"simple_frame allocation frame failed", NULL));
	}
	simple_frame->text = text;
	simple_frame->text_ratio = text_ratio;
	simple_frame->texture = texture;
	simple_frame->text_background = text_background;
	return (simple_frame);
}

void			ui_free_simple_frame(t_simple_frame **simple_frame)
{
	t_simple_frame	*f;

	f = *simple_frame;
	if (f)
	{
		if (f->text)
			ft_strdel(&f->text);
		if (f->texture)
			SDL_DestroyTexture(f->texture);
		if (f->text_background)
			SDL_DestroyTexture(f->text_background);
		free(f);
		*simple_frame = NULL;
	}
}
