/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_general_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:34:18 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/17 23:44:59 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

char		*get_next_flag(const char *flags)
{
	char	*flag;
	int		i;
	int		start;
	int		len;

	i = 0;
	while (flags[i] && !ft_isprint(flags[i]))
		i++;
	start = i;
	len = 0;
	while (ft_isprint(flags[i]) && flags[i] != '|')
	{
		i++;
		len++;
	}
	if (!(flag = ft_strsub(flags, start, len)))
	{
		return (ui_ret_null_error("get_next_flag",
				"flag <- ft_strsub failed", NULL));
	}
	return (flag);
}

static void	skip_char(const char **flags)
{
	while (!ft_isprint(**flags) && **flags)
		(*flags)++;
	while (ft_isprint(**flags))
		(*flags)++;
	while (!ft_isprint(**flags) && **flags)
		(*flags)++;
}

char		**get_flags_tab(const char *flags)
{
	void	*tmp;
	char	**tab;
	char	*next_flag;
	int		i;

	tab = NULL;
	i = 0;
	while (*flags)
	{
		if (!(next_flag = get_next_flag(flags)))
		{
			return (ui_ret_null_error("get_flags_tab",
					"get_next_flag failed", NULL));
		}
		tmp = tab;
		tab = ft_2dstrpushback(tab, i++, next_flag);
		ft_strdel(&next_flag);
		ft_2dstrdel((char***)&tmp);
		skip_char(&flags);
		if (*flags == '|')
			flags++;
	}
	return (tab);
}

int			get_float(char *str, double *fnb_ptr)
{
	double	fnb;
	int		i;

	i = 0;
	while (str[i] && !ft_isprint(str[i]))
		i++;
	fnb = ft_atof(str);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.' || str[i] == ',')
	{
		i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	*fnb_ptr = fnb;
	return (i);
}

int			get_ratio(const char *line, t_frect *ratio_ptr)
{
	char	*ratio_str;

	if (!(ratio_str = ft_strstr(line, " : ")))
		return (ui_ret_error("get_ratio", "\" : \" not found", 0));
	ratio_str += 3;
	ratio_str += get_float(ratio_str, &ratio_ptr->x);
	ratio_str += get_float(ratio_str, &ratio_ptr->y);
	ratio_str += get_float(ratio_str, &ratio_ptr->w);
	ratio_str += get_float(ratio_str, &ratio_ptr->h);
	return (1);
}
