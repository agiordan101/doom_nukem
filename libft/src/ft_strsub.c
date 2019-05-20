/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/14 17:24:01 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 19:48:47 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	is;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (NULL);
	is = start;
	if (!(str = (char *)malloc((sizeof(char) * len) + 1)))
		return (NULL);
	str[len] = '\0';
	while (i < len && s[start])
	{
		str[i++] = s[is++];
	}
	return (str);
}
