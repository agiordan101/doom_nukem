/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:34:31 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:15:40 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

int					get_frame_type(const char *line)
{
	char	*type;

	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_frame_type", "\" : \" not found", -1));
	type += 3;
	if (ft_strcmp(type, "UI_FRAME_SIMPLE") == 0)
		return (UI_FRAME_SIMPLE);
	else
		return (ui_ret_error("get_frame_type", "invalid frame type", -1));
}

int					get_button_type(const char *line)
{
	char	*type;

	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_button_type", "\" : \" not found", -1));
	type += 3;
	if (ft_strcmp(type, "UI_BUTTON_SIMPLE") == 0)
		return (UI_BUTTON_SIMPLE);
	else if (ft_strcmp(type, "UI_BUTTON_TEXT_ENTRY") == 0)
		return (UI_BUTTON_TEXT_ENTRY);
	else if (ft_strcmp(type, "UI_BUTTON_TEXT_AREA") == 0)
		return (UI_BUTTON_TEXT_AREA);
	else
		return (ui_ret_error("get_button_type", "invalid button type", -1));
}

int					get_clicked_condition(const char *line)
{
	char	*type;

	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_clicked_condition", "\" : \" not found", -1));
	type += 3;
	if (ft_strcmp(type, "UI_MOUSE_LEFT") == 0)
		return (UI_MOUSE_LEFT);
	else if (ft_strcmp(type, "UI_MOUSE_RIGHT") == 0)
		return (UI_MOUSE_RIGHT);
	else if (ft_strcmp(type, "UI_MOUSE_MIDDLE") == 0)
		return (UI_MOUSE_MIDDLE);
	else
	{
		return (ui_ret_error("get_clicked_condition",
				"invalid flag <t_mouse_button>", -1));
	}
}

static t_text_align	convert_str_flag(const char *flag)
{
	if (ft_strcmp(flag, "TEXT_ALIGN_LEFT") == 0)
		return (TEXT_ALIGN_LEFT);
	else if (ft_strcmp(flag, "TEXT_ALIGN_RIGHT") == 0)
		return (TEXT_ALIGN_RIGHT);
	else if (ft_strcmp(flag, "TEXT_ALIGN_CENTER") == 0)
		return (TEXT_ALIGN_CENTER);
	else if (ft_strcmp(flag, "TEXT_ALIGN_V_MIDDLE") == 0)
		return (TEXT_ALIGN_V_MIDDLE);
	else if (ft_strcmp(flag, "TEXT_ALIGN_V_TOP") == 0)
		return (TEXT_ALIGN_V_TOP);
	else if (ft_strcmp(flag, "TEXT_ALIGN_V_BOT") == 0)
		return (TEXT_ALIGN_V_BOT);
	else
		return (0);
}

int					get_text_align(const char *line)
{
	char			**flags_tab;
	char			*flags;
	t_text_align	text_align;
	int				i;

	text_align = 0;
	if (!(flags = ft_strstr(line, " : ")))
		return (ui_ret_error("get_text_align", "\" : \" not found", -1));
	if (!(flags_tab = get_flags_tab(flags)))
	{
		ft_2dstrdel((char***)&flags_tab);
		return (ui_ret_error("get_text_align",
		"text_align : <t_text_align> expected", -1));
	}
	i = 0;
	while (flags_tab[i])
		text_align |= convert_str_flag(flags_tab[i++]);
	ft_2dstrdel((char***)&flags_tab);
	if (text_align)
		return (text_align);
	else
		return (ui_ret_error("get_text_align", "invalid text_align type", -1));
}
