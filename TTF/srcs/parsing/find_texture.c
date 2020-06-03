/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:37:19 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 14:08:39 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

static void	free_find(char **s1, char **s2)
{
	if (s1)
		ft_strdel(s1);
	if (s2)
		ft_strdel(s2);
}

int			find_texture(t_map *map, char *tab, t_poly *poly)
{
	char	*tmp;
	char	*name;
	char	*tmp_free;

	name = NULL;
	tmp = NULL;
	name = ft_strdup(ft_strrchr(tab, '=') + 2);
	poly->texture_name = ft_strdup(name);
	tmp = ft_strdup("textures/");
	tmp_free = tmp;
	tmp = ft_strjoin(tmp, name);
	free_find(&tmp_free, &name);
	if (!is_id_in_stock(map->texture_stock, tmp))
		add_stock_texture(&map->texture_stock, new_stock_texture(tmp));
	poly->texture = get_surface_from_stock(map->texture_stock, tmp);
	ft_strdel(&tmp);
	return (0);
}
