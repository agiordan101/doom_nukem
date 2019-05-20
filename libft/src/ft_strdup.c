/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 21:10:21 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/02 13:43:42 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!(s2 = (char *)ft_memalloc(sizeof(*s1) * ft_strlen(s1) + 1)))
		return (0);
	i = 0;
	s2[ft_strlen(s1)] = '\0';
	while (*s1)
	{
		s2[i++] = *s1++;
	}
	return (s2);
}
