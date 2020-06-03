/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:46:58 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:25:57 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		len;

	if (!s1 || !s2)
		return (0);
	len = 0;
	while (*s1 != '\0' && *s2 != '\0' && len < n)
	{
		if (*s1++ != *s2++)
			return (0);
		len++;
	}
	if ((*s1 == '\0' && *s2 == '\0') || len == n)
		return (1);
	else
		return (0);
}
