#include "doom_nukem.h"

void	ed_place_player(t_win *win, t_map *map)
{
	t_poly		*p;
	t_object	*obj;
	t_mob		*mob;
	t_dot		player_pos;
	int			i;

	if (win->winui->mouse.releasing & UI_MOUSE_LEFT)
	{
		player_pos = ed_get_map_point(map, win->winui->mouse.pos);
		p = map->polys;
		while (p)
		{
			i = 0;
			while (i < 4)
			{
				p->dots[i].x -= player_pos.x;
				p->dots[i].y -= player_pos.y;
				i++;
			}
			p = p->next;
		}
		obj = map->objects;
		while (obj)
		{
			obj->pos.x -= player_pos.x;
			obj->pos.y -= player_pos.y;
			obj = obj->next;
		}
		mob = map->mob;
		while (mob)
		{
			mob->pos.x -= player_pos.x;
			mob->pos.y -= player_pos.y;
			mob = mob->next;
		}
		map->editor.pos.x -= player_pos.x;
		map->editor.pos.y -= player_pos.y;
	}
}
