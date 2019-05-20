/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:02:13 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 12:07:56 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ih;
	size_t	in;

	if (needle[0] == '\0')
		return ((char *)haystack);
	ih = 0;
	while (ih < len && haystack[ih] != '\0')
	{
		in = 0;
		while (needle[in] != '\0')
		{
			if (ih + in >= len || haystack[ih + in] != needle[in])
				break ;
			in++;
		}
		if (needle[in] == '\0')
			return ((char *)(haystack + ih));
		ih++;
	}
	return (0);
}
