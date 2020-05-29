/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:34:34 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/18 11:35:33 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ui.h"
#include "ui_error.h"
#include "libft.h"

char			**skip_next_block(char **str)
{
	int		j;
	int		loop;
	int		nb_bracket;

	j = 0;
	loop = 1;
	nb_bracket = 0;
	while (str[j] && !ft_strchr(str[j], '{'))
		j++;
	if (str[j])
		j++;
	while (str[j] && loop)
	{
		if (ft_strchr(str[j], '}') && nb_bracket == 0)
			loop = 0;
		if (ft_strchr(str[j], '{'))
			nb_bracket++;
		else if (ft_strchr(str[j], '}'))
			nb_bracket--;
		j++;
	}
	return (&str[j]);
}

static char		**read_ui(const char *path)
{
	char	*line;
	char	**text;
	void	*tmp;
	int		i;
	int		fd;

	text = NULL;
	line = NULL;
	if ((fd = open(path, O_RDONLY)) <= 0)
		return (ui_ret_null_error("read_ui", "ui file oppening failed", NULL));
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = text;
		if (!(text = ft_2dstrpushback(text, i, line)))
		{
			return (ui_ret_null_error("read_ui",
					"ft_2dstrpushback failed", NULL));
		}
		ft_2dstrdel((char***)(&tmp));
		ft_strdel(&line);
		i++;
	}
	return (text);
}

static int		ui_load_error(const char *function,
								const char *error_msg,
								int ret_value,
								int line)
{
	char	*str;
	char	*number;

	number = ft_itoa(line);
	str = ft_strjoin("read error line : ", number);
	ft_putendl_fd(str, 2);
	ft_strdel(&str);
	ft_strdel(&number);
	return (ui_ret_error(function, error_msg, ret_value));
}

static int		ui_load_text(t_winui *win, char **text)
{
	int		i;

	i = 0;
	while (text[i])
	{
		if (ft_strcmp(text[i], "frame") == 0)
		{
			i += 2;
			if (!parse_frame(win, &text[i], &i))
				return (ui_load_error("ui_load", "p_f failed", 0, i + 1));
			if (text[i])
			{
				if (ft_strcmp(text[i], "}") != 0)
				{
					return (ui_load_error("ui_load",
						"frame is not correctly closed (!!only '}' expected!!)",
						0, i + 1));
				}
				i++;
			}
		}
		else
			i++;
	}
	return (1);
}

int				ui_load(const char *path, t_winui *win)
{
	char	**text;

	if ((text = read_ui(path)) == NULL)
		return (ui_ret_error("ui_load", "read_ui failed", 0));
	if (!ui_load_text(win, text))
	{
		ft_2dstrdel(&text);
		return (ui_ret_error("ui_load", "ui_load_text failed", 0));
	}
	ui_update_frames_rect(win, SDL_TRUE);
	ui_update_buttons_rect(win, SDL_TRUE);
	ui_update_ui(win);
	ft_2dstrdel((char***)&text);
	return (1);
}
