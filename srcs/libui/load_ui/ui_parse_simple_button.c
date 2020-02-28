/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_parse_simple_button.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:34:53 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:54:52 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

static t_simple_button	*ui_ret_null_error_s(t_simple_button **simple_button,
												const char *function,
												const char *error_msg,
												void *return_value)
{
	ui_free_simple_button(simple_button);
	return (ui_ret_null_error(function, error_msg, return_value));
}

static int				parse_simple_button_first_step(t_winui *win,
												char **text,
												int *i,
												t_simple_button *simple_button)
{
	int		index;

	index = 0;
	if (!check_line_name(text[index], "text")
		|| !(simple_button->text = parse_str(text[index])))
	{
		return (ui_ret_error("parse_simple_button",
					"\"text : <str>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	if (!(simple_button->textures.normal = parse_texture(win->rend,
					&win->ui.textures, "texture_normal", text[index])))
	{
		return (ui_ret_error("parse_simple_button",
		"parse_texture failed (expected line_name : \"texture_normal\")",
		0));
	}
	incre_double_int(&index, i, 1);
	return (index);
}

static int				parse_simple_button_second_step(t_winui *win,
										char **text,
										int *i,
										t_simple_button *simple_button)
{
	int		index;

	index = 0;
	if (!(simple_button->textures.clicked = parse_texture(win->rend,
			&win->ui.textures, "texture_clicked", text[index])))
	{
		return (ui_ret_error("parse_simple_button_second_step",
		"parse_texture failed (expected line_name : \"texture_clicked\")",
		0));
	}
	incre_double_int(&index, i, 1);
	if (!(simple_button->textures.on_mouse = parse_texture(win->rend,
				&win->ui.textures, "texture_on_mouse", text[index])))
	{
		return (ui_ret_error("parse_simple_button_second_step",
		"parse_texture failed (expected line_name : \"texture_on_mouse\")",
		0));
	}
	incre_double_int(&index, i, 1);
	return (index);
}

static int				last_step(char **text,
									int *i,
									t_simple_button *simple_button)
{
	int		index;

	index = 0;
	if (!check_line_name(text[index], "clicked_condition")
	|| (simple_button->clicked_condition = get_clicked_condition(
											text[index])) <= 0)
	{
		return (ui_ret_error("parse_simple_button",
		"\"clicked_condition : <t_mouse_button>\" expected", 0));
	}
	(*i)++;
	return (1);
}

t_simple_button			*parse_simple_button(t_winui *win,
										char **text,
										int *i)
{
	t_simple_button *simple_button;
	int				index;

	index = 0;
	if (!(simple_button = (t_simple_button*)
			ft_memalloc(sizeof(t_simple_button))))
	{
		return (ui_ret_null_error_s(&simple_button, "parse_simple_button",
					"simple_button allocation failed", NULL));
	}
	if (!(index = parse_simple_button_first_step(win, text, i, simple_button)))
	{
		return (ui_ret_null_error_s(&simple_button, "parse_simple_button",
							"parse_simple_button_f_s failed", NULL));
	}
	if (!parse_simple_button_second_step(win, &text[index], i, simple_button))
	{
		return (ui_ret_null_error_s(&simple_button, "parse_simple_button",
							"parse_simple_button_s_s failed", NULL));
	}
	index += 2;
	if (!last_step(&text[index], i, simple_button))
		return (ui_ret_null_error_s(&simple_button, "p_s_b", "l_s", NULL));
	return (simple_button);
}
