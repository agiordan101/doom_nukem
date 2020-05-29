/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_draw_one_line_return.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:16:50 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:16:51 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_texture.h"
#include "ui_error.h"
#include "libft.h"

static char		*skip_first_word(char *str)
{
	while (*str && !ft_isprint(*str))
		str++;
	while (ft_isprint(*str))
		str++;
	while (*str && !ft_isprint(*str))
		str++;
	return (str);
}

static char		*remove_last_word(const char *str)
{
	char	*rev_str;
	char	*new_str;
	char	*tmp;
	char	*rev_start;

	if (!(rev_str = ft_strrev((char *)str)))
	{
		return (ui_ret_null_error("remove_last_word",
			"ft_strrev(rev_str) allocation failed", NULL));
	}
	rev_start = rev_str;
	rev_str = skip_first_word(rev_str);
	if (!(new_str = ft_strdup(rev_str)))
		ui_ret_null_error("remove_last_word",
		"rev_str allocation failed", NULL);
	tmp = new_str;
	if (!(new_str = ft_strrev(new_str)))
		ui_ret_null_error("remove_last_word",
		"ft_strrev(new_str) allocation failed", NULL);
	ft_strdel(&tmp);
	ft_strdel(&rev_start);
	return (new_str);
}

static char		*remove_words_from_end(const char *str, int n)
{
	char	*tmp;
	char	*new_str;
	int		i;

	i = 0;
	new_str = ft_strdup(str);
	while (i < n)
	{
		tmp = new_str;
		if (!(new_str = remove_last_word(new_str)))
		{
			return (ui_ret_null_error("remove_word_from_end",
			"remove_last_word failed", NULL));
		}
		ft_strdel(&tmp);
		i++;
	}
	return (new_str);
}

static int		remove_word(t_text_line_kit *text, char **str, int n_rem_words)
{
	int		width;
	char	*tmp;

	tmp = *str;
	*str = remove_words_from_end(text->str, n_rem_words);
	ft_strdel(&tmp);
	width = ui_get_text_width(text->font, *str, text->height);
	tmp = *str;
	*str = ft_strdup(text->str);
	ft_strdel(&tmp);
	return (width);
}

int				draw_one_line_return(SDL_Renderer *rend,
							t_text_line_kit *text,
							int n_to_rem,
							int n_words)
{
	int		width;
	char	*str;
	char	*tmp;
	int		n_rem_words;

	str = ft_strdup(text->str);
	width = ui_get_text_width(text->font, str, text->height);
	n_rem_words = 0;
	while (str && width > text->max_width
			&& n_to_rem + n_rem_words < n_words)
		width = remove_word(text, &str, ++n_rem_words);
	if (n_rem_words && width)
	{
		tmp = str;
		str = remove_words_from_end(text->str, n_rem_words);
		ft_strdel(&tmp);
	}
	if (n_to_rem + n_rem_words < n_words && ft_strlen(str))
		ui_draw_text_line(rend, &(t_text_line_kit){str,
			text->color, text->pos, text->max_width,
			text->height, text->font, text->alignment});
	ft_strdel(&str);
	return ((n_rem_words == 0) ? -1 : ft_count_words(text->str) - n_rem_words);
}
