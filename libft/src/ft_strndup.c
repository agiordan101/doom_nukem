/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 13:25:57 by user42            #+#    #+#             */
/*   Updated: 2020/06/03 12:44:26 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	while (str[i] && i < n)
		i++;
	if (!(s = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		s[i] = str[i];
		i++;
	}
	s[i++] = '\0';
	return (s);
}
