/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 15:22:37 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:26:01 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)ft_memalloc(size + 1)))
		return (NULL);
	return (s);
}
