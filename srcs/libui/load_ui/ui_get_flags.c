/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_get_flags.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:34:26 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:34:28 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

int		get_text_side(const char *line)
{
	char	*type;

	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_text_side", "\" : \" not found", -1));
	type += 3;
	if (ft_strcmp(type, "UI_TEXT_SIDE_LEFT") == 0)
		return (UI_TEXT_SIDE_LEFT);
	else if (ft_strcmp(type, "UI_TEXT_SIDE_RIGHT") == 0)
		return (UI_TEXT_SIDE_RIGHT);
	else if (ft_strcmp(type, "UI_TEXT_SIDE_TOP") == 0)
		return (UI_TEXT_SIDE_TOP);
	else if (ft_strcmp(type, "UI_TEXT_SIDE_BOT") == 0)
		return (UI_TEXT_SIDE_BOT);
	else
		return (ui_ret_error("get_text_side", "invalid text_side", -1));
}

int		get_text_type(const char *line)
{
	char	*type;

	if (!(type = ft_strstr(line, " : ")))
		return (ui_ret_error("get_text_type", "\" : \" not found", -1));
	type += 3;
	if (ft_strcmp(type, "UI_TEXT_TYPE_DIGITAL") == 0)
		return (UI_TEXT_TYPE_DIGITAL);
	else if (ft_strcmp(type, "UI_TEXT_TYPE_NONE") == 0)
		return (UI_TEXT_TYPE_NONE);
	else
		return (ui_ret_error("get_text_type", "invalid text_type", -1));
}
