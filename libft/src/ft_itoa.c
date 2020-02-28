/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 17:00:49 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/31 17:25:22 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static int		ft_len(int value)
{
	int		len;
	
	len = 0;
	if (value <= 0)
		len++;
	while (value != 0)
	{
		len++;
		value /= 10;
	}
	return (len);
}

char		*ft_itoa(int value)
{
	int		len;
	int		n;
	char	*str;
	int		i;

	len = ft_len(value);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (value < 0)
		str[0] = '-';
	else if (value == 0)
		str[0] = '0';
	i = len - 1;
	while (value != 0)
	{
		n = ft_intabs(value % 10);
		str[i--] = '0' + n;
		value /= 10;
	}
	return (str);
}

