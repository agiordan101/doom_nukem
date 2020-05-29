/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_parse_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:34:39 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:15:53 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

void		incre_double_int(int *a, int *b, int value)
{
	if (a)
		(*a) += value;
	if (b)
		(*b) += value;
}

static void	*parse_button_data(t_winui *win,
								char **text,
								t_button_type button_type,
								int *i)
{
	void	*data;

	data = NULL;
	if (!ft_strstr(text[0], "data"))
	{
		return (ui_ret_null_error("parse_button_data",
				"\"data\" (button) is missing", NULL));
	}
	(*i) += 2;
	if (button_type == UI_BUTTON_SIMPLE)
		data = parse_simple_button(win, &text[2], i);
	else if (button_type == UI_BUTTON_TEXT_ENTRY)
	{
		data = parse_text_entry_button(win,
								&text[2], i);
	}
	else if (button_type == UI_BUTTON_TEXT_AREA)
		data = parse_text_area(&text[2], i);
	(*i)++;
	return (data);
}

static void	*ui_ret_null_error_b(t_button **b,
									const char *function,
									const char *error_msg,
									void *return_value)
{
	ui_free_button(b);
	return (ui_ret_null_error(function, error_msg, return_value));
}

static int	parse_button_first_step(char **text, int *i, t_button *b)
{
	int	index;

	index = 0;
	if (!check_line_name((const char *)text[index], "id")
		|| !(b->id = parse_str(text[index])))
	{
		return (ui_ret_error("parse_button_first_step",
				"\"id : <str>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	if (!check_line_name((const char *)text[index], "type")
		|| (b->type = get_button_type((const char*)text[index])) <= 0)
	{
		return (ui_ret_error("parse_button_first_step",
				"\"type : <t_button_type>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	if (!check_line_name((const char *)text[index], "resize_type")
		|| (b->resize_type = get_resize_type((const char*)text[index])) <= 0)
	{
		return (ui_ret_error("parse_button_first_step",
				"\"resize_type : <t_resize_type>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	return (index);
}

t_button	*parse_button(t_winui *win, char **text, int *i)
{
	t_button	*b;
	int			index;

	if (!(b = (t_button*)ft_memalloc(sizeof(t_button))))
	{
		return (ui_ret_null_error_b(&b, "parse_button",
				"b allocation failed", NULL));
	}
	index = 0;
	if ((index = parse_button_first_step(text, i, b)) == 0)
		ui_ret_null_error_b(&b, "parse_button", "parse_button_first", NULL);
	if (!check_line_name((const char *)text[index], "ratio")
		|| !get_ratio((char*)text[index], &b->ratio))
	{
		return (ui_ret_null_error_b(&b, "parse_button",
				"\"ratio : <t_frect>\" expected", NULL));
	}
	incre_double_int(&index, i, 1);
	if ((!(b->data = parse_button_data(win, &text[index], b->type, i))))
	{
		return (ui_ret_null_error_b(&b, "parse_button",
				"invalid button data block", NULL));
	}
	(*i)++;
	return (b);
}
