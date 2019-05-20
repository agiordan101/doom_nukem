/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 17:00:49 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 19:44:43 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static size_t	ft_nblen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		is_neg;

	is_neg = (n < 0) ? 1 : 0;
	len = (is_neg) ? ft_nblen(n) + 1 : ft_nblen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[0] = (n < 0) ? '-' : '\0';
	while (len)
	{
		if (len - 1 != 0 || !is_neg)
			str[len - 1] = '0' + ft_abs(n % 10);
		n /= 10;
		len--;
	}
	return (str);
}
