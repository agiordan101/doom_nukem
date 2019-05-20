#include "doom_nukem.h"

void	selected_linedef(t_map_editor *map, t_linedef *lines, Uint32 flags)
{
	t_linedef	*l;

	l = lines;
	while (l)
	{
		if (intersect_line_rect((t_line){(t_dot){l->p1.x * map->unit + map->x,
												 l->p1.y * map->unit + map->y},
										 (t_dot){l->p2.x * map->unit + map->x,
										 		 l->p2.y * map->unit + map->y}}, map->rect_util))
			l->flags = l->flags | flags;
		else
			l->flags = LINEDEF_NONE;
		l = l->next;
	}
}

void		selected_sector_linedef(t_map_editor *map, t_sector *sectors, Uint32 flags)
{
	t_sector	*s;
	t_linedef	*l;

	s = sectors;
	while (s)
	{
		l = s->lines;
		while (l)
		{
			if (intersect_line_rect((t_line){(t_dot){l->p1.x * map->unit + map->x,
													l->p1.y * map->unit + map->y},
											(t_dot){l->p2.x * map->unit + map->x,
													l->p2.y * map->unit + map->y}}, map->rect_util))
				l->flags = l->flags | flags;
			else
				l->flags = LINEDEF_NONE;
			l = l->next;
		}
		s = s->next;
	}
}


void		selected_all_linedef(t_map_editor *map, Uint32 flags)
{
	selected_linedef(map, map->lines, flags);
	selected_sector_linedef(map, map->sectors, flags);
}