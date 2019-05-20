/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 16:39:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 19:48:55 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

static size_t	ft_strtrimlen(char const *s)
{
	size_t	trimlen;
	size_t	i;

	if (!s)
		return (0);
	trimlen = ft_strlen(s);
	i = trimlen - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		trimlen--;
		if (i == 0)
			return (0);
	}
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		trimlen--;
	}
	return (trimlen);
}

char			*ft_strtrim(char const *s)
{
	char	*strim;
	size_t	trimlen;
	size_t	i;

	if (!s)
		return (NULL);
	trimlen = ft_strtrimlen(s);
	if (!(strim = ft_memalloc(trimlen + 1)))
		return (NULL);
	strim[trimlen] = '\0';
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	i = 0;
	while (trimlen)
	{
		trimlen--;
		strim[i++] = *s++;
	}
	return (strim);
}
