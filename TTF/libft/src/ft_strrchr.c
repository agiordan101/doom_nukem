/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:42:47 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:26:09 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	cr;

	i = 0;
	cr = c;
	while (s[i])
		i++;
	while (i >= 0 && s[i] != cr)
		i--;
	if (i < 0)
		return (NULL);
	return ((char *)s + i);
}
