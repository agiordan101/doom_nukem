/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 13:14:36 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:25:49 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (*tmp1 == *tmp2 && *tmp1 != '\0' && *tmp2 != '\0' && i < n)
	{
		tmp1++;
		tmp2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*tmp1 - *tmp2);
}
