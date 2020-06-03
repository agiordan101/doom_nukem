/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:17:55 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 15:21:49 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	free_p(t_poly *p, t_poly *tmp_prev,
					t_poly *tmp_next, t_poly **polys)
{
	if (p->texture_name)
		ft_strdel(&p->texture_name);
	free(p);
	if (tmp_prev)
		tmp_prev->next = tmp_next;
	else
		*polys = tmp_next;
}

void		delete_poly(t_poly **polys, t_poly *poly)
{
	t_poly	*p;
	t_poly	*tmp_prev;
	t_poly	*tmp_next;

	if (polys && poly)
	{
		tmp_prev = NULL;
		p = *polys;
		while (p)
		{
			if (p == poly)
			{
				tmp_next = p->next;
				free_p(p, tmp_prev, tmp_next, polys);
				p = tmp_next;
			}
			else
			{
				tmp_prev = p;
				p = p->next;
			}
		}
	}
}
