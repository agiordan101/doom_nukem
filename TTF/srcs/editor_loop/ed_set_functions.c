/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_set_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:39 by gal               #+#    #+#             */
/*   Updated: 2020/05/19 09:17:54 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		set_int_value(void *argument, char *button_output)
{
	*((int*)argument) = ft_atoi(button_output);
}

void		set_float_value(void *argument, char *button_output)
{
	*((float*)argument) = ft_atoi(button_output);
}

void		set_coef_value(void *argument, char *button_output)
{
	*((float*)argument) = ft_atoi(button_output) / 100.f;
}

void		set_str_value(void *argument, char *button_output)
{
	if (*((char**)argument))
		ft_strdel((char**)argument);
	*((char**)argument) = ft_strdup(button_output);
}

void		set_editor_calc(void *argument)
{
	t_arg_menu	*arg;

	arg = (t_arg_menu*)argument;
	*(arg->loop) = arg->value;
}
