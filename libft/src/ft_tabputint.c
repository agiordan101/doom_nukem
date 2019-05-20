/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabputint.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 12:56:28 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 14:48:06 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_tabputint(int *tab, int len)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (i < len)
		{
			ft_putnbr(tab[i++]);
			ft_putchar(' ');
		}
	}
}
