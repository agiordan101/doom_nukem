/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:20:16 by gal               #+#    #+#             */
/*   Updated: 2020/05/17 23:01:37 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_2dstrlen(char **tab)
{
	int	len;

	len = 0;
	if (tab)
	{
		while (tab[len])
			len++;
	}
	return (len);
}
