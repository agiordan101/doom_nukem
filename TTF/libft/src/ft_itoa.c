/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:00:49 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/17 23:04:58 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len(int value)
{
	int		len;

	len = 0;
	if (value <= 0)
		len++;
	while (value != 0)
	{
		len++;
		value /= 10;
	}
	return (len);
}

char		*ft_itoa(int value)
{
	int		len;
	int		n;
	char	*str;
	int		i;

	len = ft_len(value);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (value < 0)
		str[0] = '-';
	else if (value == 0)
		str[0] = '0';
	i = len - 1;
	while (value != 0)
	{
		n = ft_intabs(value % 10);
		str[i--] = '0' + n;
		value /= 10;
	}
	return (str);
}
