/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:57:12 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:26:17 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>
#include <stdlib.h>

static int	ft_countword(const char *src, char c)
{
	int		i;
	int		cword;

	i = 0;
	cword = 0;
	while (src[i])
	{
		if (src[i] == c)
			i++;
		if (src[i] != c && src[i])
		{
			cword++;
			while (src[i] != c && src[i])
				i++;
		}
	}
	return (cword);
}

static char	*ft_getnextword(const char *s, char c)
{
	char	*dst;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	if (!(dst = ft_memalloc(sizeof(dst) * len + 1)))
		return (NULL);
	dst[len] = '\0';
	i = 0;
	while (s[i] != c && s[i])
	{
		dst[i] = s[i];
		i++;
	}
	return (dst);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**split;
	int		is;

	if (!s || !c)
		return (NULL);
	if (!(split = (char**)malloc(sizeof(split) * ft_countword(s, c) + 1)))
		return (NULL);
	is = 0;
	while (*s)
	{
		if (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			split[is++] = ft_getnextword(s, c);
			while (*s != c && *s)
				s++;
		}
	}
	split[is] = NULL;
	return (split);
}
