/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_rect.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:35:44 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:35:47 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_shape.h"

int		ui_is_dot_in_rect(t_dot dot, t_rect rect)
{
	return (dot.x >= rect.x
			&& dot.x < rect.x + rect.w
			&& dot.y >= rect.y
			&& dot.y < rect.y + rect.h);
}
