/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countnumbers.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 20:23:39 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 17:25:40 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_countnumbers(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			i++;
		else
		{
			nb++;
			while (ft_isdigit(str[i]) && str[i])
				i++;
		}
	}
	return (nb);
}
