/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_parse_buttons.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:34:42 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:51:46 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

static int	parse_buttons_loop(t_winui *win, char **text, int *i, t_frame *frame)
{
	t_button	*b;
	int			index;

	index = 0;
	while (frame && ft_strstr(text[index], "button"))
	{
		incre_double_int(&index, i, 1);
		if (!ft_strchr(text[index], '{'))
		{
			return (ui_ret_error("parse_buttons",
					"'{' (to open button block) is missing", 0));
		}
		incre_double_int(&index, i, 1);
		if ((b = parse_button(win, &text[index], i)))
			ui_add_button(&frame->buttons, b);
		else
			return (ui_ret_error("parse_buttons", "parse_button failed", 0));
		if (!(text = skip_next_block(text)))
		{
			return (ui_ret_error("parse_buttons",
					"invalid button block {} syntax", 0));
		}
		index = 0;
	}
	return (1);
}

int			parse_buttons(t_winui *win, char **text, int *i)
{
	int			index;
	t_frame		*frame;

	index = 0;
	frame = win->ui.frames;
	if (!parse_buttons_loop(win, text, i, frame))
		return (ui_ret_error("parse_buttons", "parse_buttons_loop failed", 0));
	return (1);
}
