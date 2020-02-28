#include "doom_nukem.h"
#include "ui_error.h"

void		ed_export(void *ed_export)
{
	int			fd;
	t_mob		*m;
	t_poly		*p;
	t_object	*obj;
	t_export	*export;
	t_map		*map;

	int grdy;

	grdy = 0; // TO DO: AJOUTER UNE OPTION SUR L'EDITEUR
	export = (t_export*)ed_export;
	map = (t_map*)export->map;
	printf("path = %s\n", export->path);
	fd = open(export->path,  O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
							| S_IWUSR | S_IRGRP | S_IROTH);
	if (fd)
	{
		ed_write_player(fd, &map->player);
		obj = map->objects;
		while (obj)
		{
			ed_write_item(fd, obj);
			obj = obj->next;
		}
		m = map->mob;
		while (m)
		{
			ed_write_mob(fd, m);
			m = m->next;
		}
		p = map->polys;
		while (p && !p->object) // && !p->object sinon boucle aussi sur les polys de obj et m
		{
			ed_write_poly(fd, p, &map->player);
			p = p->next;
		}
		if (grdy && !ed_export_ready(fd, map))
			ui_ret_error("ed_export (gameready)", "opening/creating failed", 0);	
	}
	else
		ui_ret_error("ed_export", "opening/creating failed", 0);
}