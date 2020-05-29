/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_set_z_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:44 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:22:44 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void			set_wall_z1(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[0].z = ft_atoi(button_output);
	poly->dots[1].z = ft_atoi(button_output);
}

void			set_wall_z2(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[2].z = ft_atoi(button_output);
	poly->dots[3].z = ft_atoi(button_output);
}

void			set_flat_z(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[0].z = ft_atoi(button_output);
	poly->dots[1].z = ft_atoi(button_output);
	poly->dots[2].z = ft_atoi(button_output);
	poly->dots[3].z = ft_atoi(button_output);
}

void			set_inclined_z1(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[0].z = ft_atoi(button_output);
	poly->dots[3].z = ft_atoi(button_output);
}

void			set_inclined_z2(void *argument, char *button_output)
{
	t_poly	*poly;

	poly = argument;
	poly->dots[1].z = ft_atoi(button_output);
	poly->dots[2].z = ft_atoi(button_output);
}
