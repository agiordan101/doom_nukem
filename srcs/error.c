/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 00:03:48 by gal               #+#    #+#             */
/*   Updated: 2020/05/17 00:03:48 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		ret_num_error(const char *error_msg, int i)
{
	ft_putstr(error_msg);
	ft_putchar('\t');
	ft_putnbr(i);
	ft_putchar('\n');
	return (0);
}

int		ret_error(const char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	return (0);
}

void	*ret_null_error(const char *error_msg)
{
	ft_putendl_fd(error_msg, 2);
	return (NULL);
}

int		ret_perror(const char *error_msg)
{
	perror(error_msg);
	return (0);
}

void	*ret_null_perror(const char *error_msg)
{
	perror(error_msg);
	return (NULL);
}
