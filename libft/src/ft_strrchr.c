/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:42:47 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:43:14 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
