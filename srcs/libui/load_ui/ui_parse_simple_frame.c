/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_parse_simple_frame.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:34:57 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:34:59 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

static t_simple_frame	*ui_ret_null_error_sf(t_simple_frame **simple_frame,
												const char *function,
												const char *error_msg,
												void *return_value)
{
	ui_free_simple_frame(simple_frame);
	return (ui_ret_null_error(function, error_msg, return_value));
}

t_simple_frame			*parse_simple_frame(SDL_Renderer *rend,
											t_texture **textures,
											char **str,
											int *i)
{
	t_simple_frame	*simple_frame;

	if (!(simple_frame = ft_memalloc(sizeof(t_simple_frame))))
	{
		return (ui_ret_null_error_sf(&simple_frame, "parse_simple_frame",
				"simple_frame allocation failed", NULL));
	}
	simple_frame->text = NULL;
	simple_frame->text_background = NULL;
	simple_frame->text_ratio = (t_frect){0, 0, 0, 0};
	if (!(simple_frame->texture = parse_texture(rend, textures,
										"texture", str[0])))
	{
		return (ui_ret_null_error_sf(&simple_frame, "parse_simple_frame",
				"parse_texture failed (expected line_name : \"texture\")",
				NULL));
	}
	(*i)++;
	return (simple_frame);
}
