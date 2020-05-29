/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_get_object_poly_count.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:21:12 by gal               #+#    #+#             */
/*   Updated: 2020/05/06 14:21:13 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int			ed_get_object_poly_count(const t_object *obj)
{
	if (obj->type == BOX)
		return (6);
	else if (obj->type == DOOR)
		return (2);
	else
		return (1);
}
