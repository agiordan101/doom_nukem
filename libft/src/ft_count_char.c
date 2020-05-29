/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:21:08 by gal               #+#    #+#             */
/*   Updated: 2020/05/17 23:06:35 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_count_char(char *str, int c)
{
	int	i;
	int	nb_char;

	i = 0;
	nb_char = 0;
	while (str[i])
	{
		if (str[i] == c)
			nb_char++;
		i++;
	}
	return (nb_char);
}
