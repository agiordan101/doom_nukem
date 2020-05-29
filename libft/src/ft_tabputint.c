/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabputint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:56:28 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:26:50 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_tabputint(int *tab, int len)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (i < len)
		{
			ft_putnbr(tab[i++]);
			ft_putchar(' ');
		}
	}
}
