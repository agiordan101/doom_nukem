/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atof.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 16:23:42 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 16:26:19 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	zero_count_dec(const char *str, float *fnb)
{
	int		zero_count;

	zero_count = 0;
	if (*str == '.' || *str == ',')
	{
		str++;
		while (*str == '0')
		{
			str++;
			zero_count++;
		}
		*fnb = ft_atoi(str);
		while (*fnb >= 1)
			*fnb /= 10;
		while (zero_count--)
			*fnb /= 10;
	}
}

float		ft_atof(const char *str)
{
	float	is_neg;
	float	nb;
	float	fnb;

	is_neg = 1;
	nb = 0;
	fnb = 0;
	if (str)
	{
		while (!ft_isprint(*str) && *str)
			str++;
		nb = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
		zero_count_dec(str, &fnb);
	}
	return ((nb + fnb) * is_neg);
}
