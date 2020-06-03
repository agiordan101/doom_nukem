/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:11:59 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:21:12 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_count_words(char *str)
{
	int			i;
	int			i_words;

	i_words = 0;
	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (ft_isprint(str[i]))
			{
				i_words++;
				while (ft_isprint(str[i]))
					i++;
			}
			while (str[i] && !ft_isprint(str[i]))
				i++;
		}
	}
	return (i_words);
}
