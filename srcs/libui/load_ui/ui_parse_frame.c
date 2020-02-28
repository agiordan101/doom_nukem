/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_parse_frame.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:34:49 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:51:46 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

static int		ui_ret_error_f(t_ui *ui,
								const char *function,
								const char *error_msg,
								int ret_value)
{
	t_frame *f;
	t_frame *next;

	f = ui->frames;
	if (f)
	{
		next = f->next;
		ui_free_frame(&f);
		ui->frames = next;
	}
	return (ui_ret_error(function, error_msg, ret_value));
}

static int		parse_frame_first_step(char **text, int *i, t_frame *f)
{
	int		index;

	index = 0;
	if (!check_line_name(text[index], "type")
		|| (f->type = get_frame_type(text[index])) <= 0)
	{
		return (ui_ret_error("parse_frame_first_step",
				"\"type : <t_type_frame>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	if (!check_line_name(text[index], "resize_type")
		|| (f->resize_type = get_resize_type(text[index])) <= 0)
	{
		return (ui_ret_error("parse_frame_first_step",
			"\"resize_type : <t_resize_type>\" expected", 0));
	}
	incre_double_int(&index, i, 1);
	return (index);
}

static char		**parse_frame_second_step(t_winui *win,
											char **text,
											int *i,
											t_frame *f)
{
	char	**skipped_text;
	int		index;

	index = 0;
	if (!check_line_name(text[index], "ratio")
		|| !get_ratio(text[index], &f->ratio))
	{
		return (ui_ret_null_error("parse_frame_second_step",
				"\"ratio : <t_frect>\" expected", NULL));
	}
	incre_double_int(&index, i, 1);
	if (!(f->data = parse_frame_data(win, &text[index], f->type, i)))
	{
		return (ui_ret_null_error("parse_frame_second_step",
				"frame data block expected", NULL));
	}
	if (!(skipped_text = skip_next_block(&text[index])))
	{
		return (ui_ret_null_error("parse_frame_second_step",
				"invalid data block {} syntax", NULL));
	}
	return (skipped_text);
}

int				parse_frame(t_winui *win, char **text, int *i)
{
	t_frame	*f;
	int		index;

	if (!(f = ui_new_frame(0, 0, (t_frect){0, 0, 0, 0}, NULL)))
		return (ui_ret_error("parse_frame", "f allocation failed", 0));
	ui_add_frame(&win->ui.frames, f);
	if (win && i)
	{
		if ((index = parse_frame_first_step(text, i, f)) == 0)
		{
			return (ui_ret_error_f(&win->ui, "parse_frame",
						"parse_frame_first_step failed", 0));
		}
		if (!(text = parse_frame_second_step(win, &text[index], i, f)))
		{
			return (ui_ret_error_f(&win->ui, "parse_frame",
						"parse_frame_second_step failed", 0));
		}
		index = 0;
		if (!parse_buttons(win, &text[index], i))
			return (ui_ret_error_f(&win->ui, "parse_frame", "prs_buttons", 0));
	}
	return (1);
}
