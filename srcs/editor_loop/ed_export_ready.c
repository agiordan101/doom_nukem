/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_export_ready.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:25:49 by widrye            #+#    #+#             */
/*   Updated: 2020/02/27 20:13:46 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int ed_write_texture(int fd, t_list **lst, char *texname)
{
	static char tmp[BUFSIZ];
	int fd_text;
	int n;

	if (!ft_content_already_inlist(*lst, texname))
	{
		*lst = ft_lst_pb(lst, texname);
		fd_text = open(ft_strjoin("textures/", texname), O_RDONLY);
		if (fd_text < 0)
			return (0);
		ft_putchar_fd('\t', fd);
		ft_putendl_fd(texname, fd);
		while ((n = read(fd_text, tmp, sizeof(tmp))))
			write(fd, tmp, n);
		ft_putendl_fd("", fd);
	}
	return (1);
}

int ed_export_textures(int fd, t_map *map)
{
	t_list		*lst;
	t_object	*obj;
	t_mob		*mob;
	t_poly		*poly;
	int			ret;

	lst = NULL;
	ret = 0;
	obj = map->objects;
	while (obj && (ret = ed_write_texture(fd, &lst, obj->texture)) == 1)
		obj = obj->next;
	mob = map->mob;
	while (ret && mob && (ret = ed_write_texture(fd, &lst, mob->texture)))
		mob = mob->next;
	poly = map->polys;
	while (ret && poly && !poly->object && (ret = ed_write_texture(fd, &lst, poly->texture_name)))
		poly = poly->next;
	ft_free_list(lst);
	return (ret);
}

int ed_export_ready(int fd, t_map *map)
{
	ft_putendl_fd("\nTextures\n{", fd);
	if (!ed_export_textures(fd, map))
		return (0);
	ft_putendl_fd("}", fd);
	ft_putendl_fd("\nSounds\n{", fd);
	if (!ed_export_sounds(fd))
		return (0);
	return (1);
}
