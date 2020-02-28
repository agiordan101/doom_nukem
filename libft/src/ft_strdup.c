/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 21:10:21 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 17:52:58 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (NULL);
	if (!(s2 = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	s2[ft_strlen(s1)] = '\0';
	while (*s1)
	{
		s2[i++] = *s1++;
	}
	return (s2);
}
