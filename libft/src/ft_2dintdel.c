/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dintdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:44:06 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:19:56 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_2dintdel(int ***atab, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free((*atab)[i++]);
	free(*atab);
	*atab = NULL;
}
