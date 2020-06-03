/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:23:39 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:21:15 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_countnumbers(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			i++;
		else
		{
			nb++;
			while (ft_isdigit(str[i]) && str[i])
				i++;
		}
	}
	return (nb);
}
