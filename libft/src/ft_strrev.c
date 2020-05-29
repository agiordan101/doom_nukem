/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:26:11 by gal               #+#    #+#             */
/*   Updated: 2020/05/17 23:05:21 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strrev(char *str)
{
	char	*str_rev;
	int		i;
	int		i_rev;

	if (str)
	{
		if (!(str_rev = (char*)ft_memalloc(sizeof(char) *\
														(ft_strlen(str) + 1))))
			return (NULL);
		i = ft_strlen(str) - 1;
		i_rev = 0;
		while (i >= 0)
			str_rev[i_rev++] = str[i--];
		return (str_rev);
	}
	return (NULL);
}
