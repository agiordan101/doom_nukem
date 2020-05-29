/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_write_item.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:35:43 by gal               #+#    #+#             */
/*   Updated: 2020/05/19 08:57:20 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		ed_write_item_cont(int fd, const t_object *obj, t_fdot_3d playerpos)
{
	char	*tmp;

	tmp = ft_itoa(obj->pos_rotz_only.x + playerpos.x);
	ed_write_line(fd, "\tposx", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->pos_rotz_only.y + playerpos.y);
	ed_write_line(fd, "\tposy", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->pos_rotz_only.z + playerpos.z);
	ed_write_line(fd, "\tposz", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->width);
	ed_write_line(fd, "\twidth", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->height);
	ed_write_line(fd, "\theight", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->dir);
	ed_write_line(fd, "\tdir", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->light_coef * 100);
	ed_write_line(fd, "\tlight", tmp);
	ft_strdel(&tmp);
	ed_write_line(fd, "\ttexture", obj->texture);
}

static void	ed_write_set_tmp(const t_object *obj, char **tmp)
{
	if (obj->type & HEAL)
		*tmp = "HEAL";
	else if (obj->type & ARMOR)
		*tmp = "ARMOR";
	else if (obj->type & GRAVITY_INV)
		*tmp = "GRAVITY_INV";
	else if (obj->type & BULLET)
		*tmp = "BULLET";
	else if (obj->type & BOX)
		*tmp = "BOX";
	else if (obj->type & DOOR)
		*tmp = "DOOR";
	else if (obj->type & LIGHT)
		*tmp = "LIGHT";
	else if (obj->type & TP)
		*tmp = "TP";
	else if (obj->type & END)
		*tmp = "END";
}

void		ed_write_item(int fd, const t_object *obj, t_fdot_3d playerpos)
{
	char	*tmp;

	tmp = NULL;
	ed_write_set_tmp(obj, &tmp);
	ft_putendl_fd("Object", fd);
	ft_putendl_fd("{", fd);
	ed_write_line(fd, "\ttype", tmp);
	ed_write_item_cont(fd, obj, playerpos);
	ft_putendl_fd("}", fd);
}
