/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 21:08:00 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/03 15:50:25 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t		ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	return (len);
}
