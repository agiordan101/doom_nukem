/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:20:31 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:20:40 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int		is_neg;
	int		nb;

	is_neg = 1;
	nb = 0;
	if (str)
	{
		while (*str == '\t' || *str == '\v' || *str == '\n'
				|| *str == '\r' || *str == '\f' || *str == ' ')
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				is_neg = -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			nb *= 10;
			nb += *str - 48;
			str++;
		}
	}
	return (nb * is_neg);
}
