#include "doom_nukem.h"

static void	ed_write_line(int fd, const char *name, const char *value)
{
	ft_putstr_fd(name, fd);
	ft_putstr_fd(" = ", fd);
	ft_putendl_fd(value, fd);
}

void	ed_write_player(int fd, const t_player *player)
{
	char	*tmp;

	if (player)
	{
		ft_putendl_fd("Player", fd);
		ft_putendl_fd("{", fd);
		tmp = ft_itoa(player->pos.x);
		ed_write_line(fd, "\tposx", tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa(player->pos.y);
		ed_write_line(fd, "\tposy", tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa(player->pos.z);
		ed_write_line(fd, "\tposz", tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa(player->dir_init);
		ed_write_line(fd, "\tdir", tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa(player->width);
		ed_write_line(fd, "\twidth", tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa(player->height);
		ed_write_line(fd, "\theight", tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa(player->const_vel);
		ed_write_line(fd, "\tvelocity", tmp);
		ft_strdel(&tmp);
		ft_putendl_fd("}", fd);
	}
}

static void	ed_write_dot(int fd, const t_fdot_3d *dot, const t_player *player)
{
	char	*tmp;

	ft_putstr_fd("\tdot = x:", fd);
	tmp = ft_itoa(dot->x + player->pos.x);
	ft_putstr_fd(tmp, fd);
	ft_strdel(&tmp);
	ft_putstr_fd(" y:", fd);
	tmp = ft_itoa(dot->y + player->pos.y);
	ft_putstr_fd(tmp, fd);
	ft_strdel(&tmp);
	ft_putstr_fd(" z:", fd);
	tmp = ft_itoa(dot->z + player->pos.z);
	ft_putendl_fd(tmp, fd);
	ft_strdel(&tmp);
}

void	ed_write_poly(int fd, const t_poly *poly, const t_player *player)
{
	char	*tmp;

	ft_putendl_fd("Polygon", fd);
	ft_putendl_fd("{", fd);
	ed_write_dot(fd, &poly->dots[0], player);
	ed_write_dot(fd, &poly->dots[1], player);
	ed_write_dot(fd, &poly->dots[2], player);
	ed_write_dot(fd, &poly->dots[3], player);
	tmp = ft_itoa(poly->light_coef * 100);
	ed_write_line(fd, "\tlight", tmp);
	ft_strdel(&tmp);
	ed_write_line(fd, "\ttexture", poly->texture_name);
	ft_putendl_fd("}", fd);
}

void	ed_write_mob(int fd, const t_mob *m)
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
	tmp = ft_itoa(m->light_coef * 100);
	ed_write_line(fd, "\tlight", tmp);
	ft_strdel(&tmp);
	ed_write_line(fd, "\ttexture", m->texture);
	ft_putendl_fd("}", fd);
}

void	ed_write_item(int fd, const t_object *obj)
{
	char	*tmp;

	ft_putendl_fd("Object", fd);
	ft_putendl_fd("{", fd);
	if (obj->type & HEAL)
		tmp = "HEAL";
	else if (obj->type & ARMOR)
		tmp = "ARMOR";
	else if (obj->type & GRAVITY_INV)
		tmp = "GRAVITY_INV";
	else if (obj->type & BULLET)
		tmp = "BULLET";
	else if (obj->type & BOX)
		tmp = "BOX";
	else if (obj->type & DOOR)
		tmp = "DOOR";
	else if (obj->type & LIGHT)
		tmp = "LIGHT";
	else if (obj->type & TP)
		tmp = "TP";
	ed_write_line(fd, "\ttype", tmp);
	tmp = ft_itoa(obj->pos_rotz_only.x);
	ed_write_line(fd, "\tposx", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->pos_rotz_only.y);
	ed_write_line(fd, "\tposy", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->pos_rotz_only.z);
	ed_write_line(fd, "\tposz", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->width);
	ed_write_line(fd, "\twidth", tmp);
	ft_strdel(&tmp);
	tmp = ft_itoa(obj->height);
	ed_write_line(fd, "\theight", tmp);
	ft_strdel(&tmp);
	if (obj->dir)
	{
		tmp = ft_itoa(obj->dir);
		ed_write_line(fd, "\tdir", tmp);
		ft_strdel(&tmp);
	}
	tmp = ft_itoa(obj->light_coef * 100);
	ed_write_line(fd, "\tlight", tmp);
	ft_strdel(&tmp);
	ed_write_line(fd, "\ttexture", obj->texture);
	ft_putendl_fd("}", fd);
}