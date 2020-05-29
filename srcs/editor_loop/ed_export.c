/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:21:03 by gal               #+#    #+#             */
/*   Updated: 2020/05/18 12:51:55 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

void		export_content(t_export *export)
{
	t_mob		*m;
	t_poly		*p;
	t_object	*obj;
	t_map		*map;

	map = (t_map*)export->map;
	obj = map->objects;
	while (obj)
	{
		ed_write_item(export->fd, obj, map->player.pos);
		obj = obj->next;
	}
	m = map->mob;
	while (m)
	{
		ed_write_mob(export->fd, m);
		m = m->next;
	}
	p = map->polys;
	while (p)
	{
		if (ed_is_real_poly(map, p) && !ed_is_poly_point(p))
			ed_write_poly(export->fd, p, &map->player);
		p = p->next;
	}
}

void		ed_export(void *ed_export)
{
	t_export	*export;
	t_map		*map;

	export = (t_export*)ed_export;
	map = (t_map*)export->map;
	export->fd = open(export->path, O_WRONLY | O_CREAT | O_TRUNC,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (export->fd)
	{
		ft_putendl_fd("\n###########", export->fd);
		ed_write_player(export->fd, &map->player);
		ed_write_sphere(export->fd, &map->sky_box);
		export_content(export);
	}
	else
		ui_ret_error("ed_export", "opening/creating failed", 0);
	ft_putendl("--Map Exported--");
}

void		ed_package(void *ed_exp)
{
	t_export	*export;

	export = (t_export*)ed_exp;
	export->fd = open(export->path, O_CREAT | O_WRONLY | O_TRUNC,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	ft_putendl_fd("#GAMEREADY#\nTextures", export->fd);
	if (!ed_export_textures(export->fd, (t_map *)export->map))
	{
		ui_ret_error("ed_package", "failed to export textures", 0);
		return ;
	}
	ft_putendl_fd("Sounds", export->fd);
	if (!ed_export_sounds(export->fd))
	{
		ui_ret_error("ed_package", "failed to export sounds", 0);
		return ;
	}
	ft_putendl_fd("\nFonts", export->fd);
	if (!ed_export_fonts(export->fd))
	{
		ui_ret_error("ed_package", "failed to export fonts", 0);
		return ;
	}
	ed_export(ed_exp);
}
