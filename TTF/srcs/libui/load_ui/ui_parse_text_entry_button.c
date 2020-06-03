/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_parse_text_entry_button.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:35:19 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:16:25 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

static t_text_entry_button	*ui_ret_null_error_te(
							t_text_entry_button **text_entry_button,
							const char *function,
							const char *error_msg,
							void *return_value)
{
	ui_free_text_entry_button(text_entry_button);
	return (ui_ret_null_error(function, error_msg, return_value));
}

static int					parse_one(char **text,
								int *i,
								t_text_entry_button *text_entry_button)
{
	int		index;

	index = 0;
	if (!check_line_name(text[index], "name")
	|| !(text_entry_button->name = parse_str(text[index])))
	{
		return (ui_ret_error(
		"parse_one", "\"name : <str>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "text"))
	{
		return (ui_ret_error(
		"parse_one", "\"text : <str>\" expected", 0));
	}
	return (index);
}

t_text_entry_button			*parse_text_entry_button(t_winui *win,
													char **text,
													int *i)
{
	t_text_entry_button	*b;
	int					index;

	index = 0;
	if (!(b = (t_text_entry_button*)
		ft_memalloc(sizeof(t_text_entry_button))))
	{
		return (ui_ret_null_error("parse_text_entry_button",
		"b allocation failed", NULL));
	}
	if (!(index = parse_one(text, i, b)))
	{
		return (ui_ret_null_error_te(&b,
		"parse_text_entry_button", "parse_one failed", NULL));
	}
	if (!parse_cut(win, &text[index], i, b))
	{
		return (ui_ret_null_error_te(&b,
		"parse_text_entry_button", "parse_cut failed", NULL));
	}
	(*i)++;
	return (b);
}
