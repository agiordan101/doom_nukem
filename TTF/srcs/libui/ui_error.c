/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:37:47 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/17 20:06:45 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_error.h"
#include "libft.h"

int		ui_ret_error(const char *function, const char *error_msg, int ret_value)
{
	char	*str;
	char	*str_value;
	int		len;

	str_value = ft_itoa(ret_value);
	len = 0;
	len += ft_strlen(function);
	len += ft_strlen(error_msg);
	len += ft_strlen(str_value);
	len += 20;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (ret_value);
	ft_strcat(str, function);
	ft_strcat(str, " : ");
	ft_strcat(str, error_msg);
	ft_strcat(str, " (code error : ");
	ft_strcat(str, str_value);
	ft_strcat(str, ").");
	ft_putendl_fd(str, 2);
	if (str_value)
		ft_strdel(&str_value);
	if (str)
		ft_strdel(&str);
	return (ret_value);
}

void	*ui_ret_null_error(const char *function,
							const char *error_msg,
							void *return_value)
{
	char	*str;
	int		len;

	len = 0;
	len += ft_strlen(function);
	len += ft_strlen(error_msg);
	len += 3;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (return_value);
	ft_strcat(str, function);
	ft_strcat(str, " : ");
	ft_strcat(str, error_msg);
	ft_putendl_fd(str, 2);
	ft_strdel(&str);
	return (return_value);
}
