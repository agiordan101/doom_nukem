/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 12:48:55 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:26:23 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	ih;
	size_t	in;

	ih = 0;
	in = 0;
	if (needle[in] == '\0')
		return ((char *)haystack);
	while (haystack[ih])
	{
		while (haystack[ih + in] == needle[in])
		{
			if (needle[in + 1] == '\0')
				return ((char *)haystack + ih);
			in++;
		}
		in = 0;
		ih++;
	}
	return (NULL);
}
