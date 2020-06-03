/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:23:08 by widrye            #+#    #+#             */
/*   Updated: 2020/05/19 18:23:30 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

int			fill_poly_object_norm(t_map *map, char *tmp, t_poly *poly_object)
{
	if (!is_id_in_stock(map->texture_stock, tmp))
		add_stock_texture(&map->texture_stock, new_stock_texture(tmp));
	poly_object->texture = get_surface_from_stock(map->texture_stock, tmp);
	return (0);
}

char		**lst_to_tab(t_list *lst, int height)
{
	int		i;
	char	**tab;
	t_list	*l;

	i = 0;
	l = lst;
	if (!(tab = (char **)malloc(sizeof(char *) * (height + 1))))
		return (NULL);
	tab[height] = NULL;
	while (l && i < height)
	{
		if (!(tab[i] = ft_strdup(l->content)))
			return (NULL);
		i++;
		l = l->next;
	}
	ft_free_list(lst);
	return (tab);
}

char		**ft_fill_map(int fd)
{
	char	*line;
	t_list	*lst;
	int		i;
	int		ret;

	i = 0;
	lst = NULL;
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == -1 || (lst = ft_lst_pb(&lst, line)) == NULL)
		{
			ft_free_list(lst);
			return (NULL);
		}
		i++;
	}
	return (lst_to_tab(lst, i));
}

char		**fillntesttab(int fd)
{
	char		**tab;
	static char	tmp[13];

	tmp[12] = '\0';
	if ((read(fd, tmp, 12)) > 0)
	{
		if (!(ft_strcmp(tmp, "#GAMEREADY#\n")))
			create_tmp_bin_files(fd);
		else if (ft_strcmp(tmp, "\n###########") != 0)
		{
			ft_putendl("error map syntax");
			return (NULL);
		}
	}
	tab = NULL;
	tab = ft_fill_map(fd);
	if (ft_parse_error(tab) == (-1))
		return (NULL);
	return (tab);
}

int			fill_poly(t_poly *poly, t_map *map)
{
	if (fill_poly_mob(map, poly, map->mob) == -1 ||
	fill_poly_object(map, poly, map->objects) == -1)
		return (-1);
	ft_putendl("Fin parsing\n");
	return (0);
}
