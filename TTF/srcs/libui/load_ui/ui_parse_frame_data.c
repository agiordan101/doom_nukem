/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_parse_frame_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:34:46 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:16:02 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

void				*parse_frame_data(t_winui *win,
										char **str,
										t_frame_type frame_type,
										int *i)
{
	void	*data;

	data = NULL;
	if (!ft_strstr(str[0], "data"))
	{
		return (ui_ret_null_error("parse_frame_data",
				"\"data\" (frame) is missing", NULL));
	}
	(*i) += 2;
	if (frame_type == UI_FRAME_SIMPLE)
		data = parse_simple_frame(win->rend, &win->ui.textures, &str[2], i);
	(*i)++;
	return (data);
}
