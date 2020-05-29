/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_rect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:35:44 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:16:46 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_shape.h"

int		ui_is_dot_in_rect(t_dot dot, t_rect rect)
{
	return (dot.x >= rect.x
			&& dot.x < rect.x + rect.w
			&& dot.y >= rect.y
			&& dot.y < rect.y + rect.h);
}
