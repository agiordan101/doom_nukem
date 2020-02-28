/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_parse_type.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:35:31 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 15:09:26 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui.h"
#include "ui_error.h"

int					parse_int(const char *str, int *n)
{
	int		i;
	char	*tmp;

	if (!(tmp = ft_strchr(str, ':')))
		return (ui_ret_error("parse_int", "no \":\" found, 0 returned", 0));
	i = 0;
	while (tmp[i] && !ft_isdigit(tmp[i]) && tmp[i] != '-' && tmp[i] != '+')
		i++;
	if (!tmp[i])
		return (ui_ret_error("parse_int", "no <int> found in str", 0));
	*n = ft_atoi(&tmp[i]);
	return (1);
}

static char			*get_new_str(char *str, int len, int start)
{
	int		i;
	char	*new_str;

	if (!(new_str = (char*)ft_memalloc(sizeof(char) * (len + 1))))
	{
		return (ui_ret_null_error("get_new_str",
			"new_str allocation failed", NULL));
	}
	i = start + 1;
	while (str[i] != '\"' && str[i])
	{
		new_str[i - start - 1] = str[i];
		i++;
	}
	new_str[i - start - 1] = '\0';
	return (new_str);
}

char				*parse_str(char *str)
{
	char	*new_str;
	int		len;
	int		i;
	int		start;

	i = 0;
	while (str[i] != '\"' && str[i])
		i++;
	if (str[i] != '\"')
		return (ui_ret_null_error("parse_str", "no <\"str\"> found", NULL));
	start = i;
	i++;
	len = 0;
	while (str[i] != '\"' && str[i])
	{
		i++;
		len++;
	}
	if (str[i] != '\"')
		return (ui_ret_null_error("parse_str", "bad <\"str\"> format", NULL));
	if (!(new_str = get_new_str(str, len, start)))
		return (ui_ret_null_error("parse_str", "get_new_str failed", NULL));
	return (new_str);
}
