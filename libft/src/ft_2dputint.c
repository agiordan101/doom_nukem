/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_2dputint.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/08 12:35:00 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 14:52:36 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

void	ft_2dputint(int **tab, int ilen, int jlen)
{
	int		i;
	int		j;

	if (tab)
	{
		i = 0;
		while (i < ilen)
		{
			j = 0;
			while (j < jlen)
			{
				ft_putnbr(tab[i][j++]);
				ft_putchar(' ');
			}
			ft_putchar('\n');
			i++;
		}
	}
}
