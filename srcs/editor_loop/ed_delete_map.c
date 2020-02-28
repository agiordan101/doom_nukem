#include "doom_nukem.h"

static void		ed_free_mob(t_mob **mob)
{
	t_mob	*m;

	m = *mob;
	if (m)
	{
		// if (m->poly)
		// 	free(m->poly);
		ft_strdel(&m->texture);
		free(m);
	}
	*mob = NULL;
}



void			ed_delete_map(void *map_ptr)
{
	t_map		*map;
	t_poly		*p;
	t_mob		*m;
	t_object	*obj;
	void		*next;

	map = (t_map*)map_ptr;
	if (map)
	{
		p = map->polys;
		while (p)
		{
			next = p->next;
			free(p);
			p = next;
		}
		map->polys = NULL;
		m = map->mob;
		while (m)
		{
			next = m->next;
			ed_free_mob(&m);
			m = next;
		}
		map->mob = NULL;
		obj = map->objects;
		while (obj)
		{
			next = obj->next;
			free(obj);
			obj = next;
		}
		map->objects = NULL;
	}
}