/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_text_line_return.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:16:52 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:16:53 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_texture.h"
#include "ui_error.h"
#include "libft.h"

static char		*jump_n_words(const char *str, int n)
{
	int			i;
	int			i_words;

	i_words = 0;
	i = 0;
	if (str)
	{
		while (str[i] && i_words < n)
		{
			if (str[i] != ' ')
			{
				i_words++;
				while (str[i] && str[i] != ' ')
					i++;
			}
			while (str[i] && str[i] == ' ')
				i++;
		}
		if (str[i])
			return (ft_strdup(&str[i]));
	}
	return (NULL);
}

int				ui_draw_text_line_return(SDL_Renderer *rend,
								t_text_line_kit *text)
{
	int				rem_count;
	int				n_words;
	int				jumped;
	t_text_line_kit	text_tmp;
	char			*tmp;

	if (text)
	{
		jumped = 0;
		rem_count = 0;
		n_words = ft_count_words(text->str);
		text_tmp = *text;
		text_tmp.str = ft_strdup(text_tmp.str);
		while (text_tmp.str && jumped != -1 && rem_count < n_words)
		{
			jumped = draw_one_line_return(rend, &text_tmp, rem_count, n_words);
			text_tmp.pos.y += text_tmp.height;
			tmp = text_tmp.str;
			text_tmp.str = jump_n_words(text_tmp.str, jumped);
			ft_strdel(&tmp);
			rem_count += jumped;
		}
		ft_strdel(&text_tmp.str);
	}
	return (1);
}
