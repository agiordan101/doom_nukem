/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_words.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 16:11:59 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 16:12:04 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_count_words(char *str)
{
	int			i;
	int			i_words;

	i_words = 0;
	if (str)
	{
		i = 0;
		while (str[i])
		{
			if (ft_isprint(str[i]))
			{
				i_words++;
				while (ft_isprint(str[i]))
					i++;
			}
			while (str[i] && !ft_isprint(str[i]))
				i++;
		}
	}
	return (i_words);
}
