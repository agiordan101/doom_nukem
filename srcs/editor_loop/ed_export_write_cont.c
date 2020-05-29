/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_export_write_cont.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 14:22:46 by gal               #+#    #+#             */
/*   Updated: 2020/05/24 12:00:19 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		ed_write_sphere(int fd, const t_sphere *skybox)
{
	char	*tmp;

	if (skybox)
	{
		ft_putendl_fd("Sphere\n{", fd);
		tmp = ft_itoa(skybox->pos_rotz_only.x);
		ed_write_line(fd, "\tposx", tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa(skybox->pos_rotz_only.y);
		ed_write_line(fd, "\tposy", tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa(skybox->pos_rotz_only.z);
		ed_write_line(fd, "\tposz", tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa(skybox->radius);
		ed_write_line(fd, "\tradius", tmp);
		ft_strdel(&tmp);
		ed_write_line(fd, "\ttexture", "desert.jpg");
		ft_putendl_fd("}", fd);
	}
}

void		ed_write_mob_cont(int fd, const t_mob *m)
{
	char	*tmp;

	tmp = ft_itoa(m->width);
	ed_write_line(fd, "\twidth", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(m->damage);
	ed_write_line(fd, "\tdamage", tmp);
	ft_strdel(&tmp);
	ed_write_line(fd, "\tdir", "-90");
	tmp = ft_itoa(m->vel);
	ed_write_line(fd, "\tvelocity", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(m->agro_dist);
	ed_write_line(fd, "\tagro_dist", tmp);
	ft_strdel(&tmp);
	ed_write_line(fd, "\ttexture", m->texture);
	tmp = ft_itoa(m->health);
	ed_write_line(fd, "\thealth", tmp);
	ft_strdel(&tmp);
}

void		ed_write_mob(int fd, const t_mob *m)
{
	char	*tmp;

	ft_putendl_fd("Mob", fd);
	ft_putendl_fd("{", fd);
	tmp = ft_itoa(m->pos.x);
	ed_write_line(fd, "\tposx", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(m->pos.y);
	ed_write_line(fd, "\tposy", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(m->pos.z);
	ed_write_line(fd, "\tposz", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(m->height);
	ed_write_line(fd, "\theight", tmp);
	ft_strdel(&tmp);
	ed_write_mob_cont(fd, m);
	ft_putendl_fd("}", fd);
}
