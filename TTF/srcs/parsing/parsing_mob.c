/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_mob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:05:46 by aducimet          #+#    #+#             */
/*   Updated: 2020/05/24 12:25:39 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	set_mobs_dots_rotz_only(t_mob *mob)
{
	mob->poly->dots_rotz_only[0].x = mob->pos.x - mob->width_2;
	mob->poly->dots_rotz_only[0].y = mob->pos.y;
	mob->poly->dots_rotz_only[0].z = mob->pos.z - mob->height_2;
	mob->poly->dots_rotz_only[1].x = mob->pos.x + mob->width_2;
	mob->poly->dots_rotz_only[1].y = mob->pos.y;
	mob->poly->dots_rotz_only[1].z = mob->pos.z - mob->height_2;
	mob->poly->dots_rotz_only[2].x = mob->pos.x + mob->width_2;
	mob->poly->dots_rotz_only[2].y = mob->pos.y;
	mob->poly->dots_rotz_only[2].z = mob->pos.z + mob->height_2;
	mob->poly->dots_rotz_only[3].x = mob->pos.x - mob->width_2;
	mob->poly->dots_rotz_only[3].y = mob->pos.y;
	mob->poly->dots_rotz_only[3].z = mob->pos.z + mob->height_2;
}

int		add_mob(t_mob **mob)
{
	t_mob	*new_mob;

	if (!(new_mob = (t_mob *)ft_memalloc(sizeof(t_mob))))
		return (-1);
	new_mob->light_coef = 1;
	new_mob->next = *mob;
	new_mob->alive = 1;
	*mob = new_mob;
	return (0);
}

void	add_existing_mob(t_mob **mob, t_mob *new_mob)
{
	if (new_mob)
	{
		new_mob->next = *mob;
		*mob = new_mob;
	}
}

int		add_poly_mob(t_mob **mob)
{
	if (!((*mob)->poly = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (-1);
	else
	{
		set_mobs_dots_rotz_only(*mob);
		(*mob)->poly->mob = *mob;
		(*mob)->poly->object = NULL;
	}
	return (0);
}

int		fill_mob_data(t_mob **mob, char **tab, int i)
{
	if (add_mob(mob) == -1)
		return (-1);
	while (ft_strchr(tab[i], '}') == NULL)
	{
		fill_mob_data_norm(mob, tab[i]);
		if (ft_strstr(tab[i], "width = "))
		{
			(*mob)->width = ft_atoi(ft_strrchr(tab[i], '=') + 1);
			(*mob)->width_2 = (*mob)->width / 2;
		}
		if (ft_strstr(tab[i], "height = "))
		{
			(*mob)->height = ft_atoi(ft_strrchr(tab[i], '=') + 1);
			(*mob)->height_2 = (*mob)->height / 2;
		}
		if (ft_strstr(tab[i], "velocity = "))
			(*mob)->vel = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "health = "))
			(*mob)->health = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "agro_dist = "))
			(*mob)->agro_dist = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		i++;
	}
	return (add_poly_mob(mob));
}
