/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 20:41:41 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/14 17:29:45 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;
	unsigned char	*ret;

	x = 0;
	ret = (unsigned char *)s;
	while (x < n)
	{
		if (ret[x] == (unsigned char)c)
			return (ret + x);
		x++;
	}
	return (NULL);
}
