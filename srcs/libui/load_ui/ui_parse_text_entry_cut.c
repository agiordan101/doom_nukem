/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_parse_text_entry_cut.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:35:23 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:16:29 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

static int			parse_two(char **text,
					int *i, t_text_entry_button *b)
{
	char	*tmp;
	int		index;

	index = 0;
	tmp = parse_str(text[index]);
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "max_text_size")
	|| !parse_int(text[index], &b->max_text_size))
		return (ui_ret_error("p_t", "\"max_text_size : <int>\" expected", 0));
	if (!(b->text = (char*)ft_memalloc(
					sizeof(char) * (b->max_text_size + 1))))
		return (ui_ret_error("parse_two", "b allocation failed", 0));
	if (!(b->new_text = (char*)ft_memalloc(
			sizeof(char) * (b->max_text_size + 1))))
		return (0);
	ft_strcpy(b->text, tmp);
	if (tmp)
		ft_strdel(&tmp);
	incre_double_int(&index, i, 1);
	return (1);
}

static int			parse_three(t_winui *win,
					char **text,
					int *i,
					t_text_entry_button *b)
{
	int		index;

	index = 0;
	if (!check_line_name(text[index], "min_int")
	|| !parse_int(text[index], &b->min_int))
		return (ui_ret_error("parse_three", "\"min_int : <int>\" expected", 0));
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "max_int")
	|| !parse_int(text[index], &b->max_int))
	{
		return (ui_ret_error("parse_text_entry_button",
		"\"max_int : <int>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	if (!(b->textures.name_side_texture = parse_texture(
		win->rend, &win->ui.textures, "name_side_texture", text[index])))
	{
		return (ui_ret_error("parse_text_entry_button", "parse_texture failed \
		(expected line_name : \"name_side_texture\")", 0));
	}
	incre_double_int(&index, i, 1);
	return (1);
}

static int			parse_four(t_winui *win,
					char **text,
					int *i,
					t_text_entry_button *b)
{
	int		index;

	index = 0;
	if (!(b->textures.normal_box_texture = parse_texture(
		win->rend, &win->ui.textures, "normal_box_texture", text[index])))
	{
		return (ui_ret_error("parse_four", "parse_texture failed \
		(expected line_name : \"normal_box_texture\")", 0));
	}
	incre_double_int(&index, i, 1);
	if (!(b->textures.writting_box_texture = parse_texture(
		win->rend, &win->ui.textures, "writting_box_texture", text[index])))
	{
		return (ui_ret_error("parse_four", "parse_texture failed \
		(expected line_name : \"writting_box_texture\")", 0));
	}
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "text_side")
	|| !(b->text_side = get_text_side(text[index])))
	{
		return (ui_ret_error("parse_four", "\"text_side : \" expected", 0));
	}
	incre_double_int(&index, i, 1);
	return (index);
}

int					parse_cut(t_winui *win,
						char **text,
						int *i,
						t_text_entry_button *b)
{
	int		index;

	index = 0;
	if (!parse_two(&text[index], i, b))
		return (ui_ret_error("parse_cut", "parse_two failed", 0));
	index += 2;
	if (!parse_three(win, &text[index], i, b))
		return (ui_ret_error("parse_cut", "parse_three failed", 0));
	index += 3;
	if (!parse_four(win, &text[index], i, b))
		return (ui_ret_error("parse_cut", "parse_four failed", 0));
	index += 3;
	if (!check_line_name(text[index], "text_type")
	|| (int)(b->text_type = get_text_type(text[index])) == -1)
		return (ui_ret_error("parse_cut", "\"text_type : \" expected", 0));
	index += 2;
	return (index);
}
