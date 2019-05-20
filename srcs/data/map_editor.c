#include "doom_nukem.h"

SDL_bool	is_line_horizontal(int y1, int y2, int pitch)
{
	return (abs(y1 - y2) < pitch);
}

SDL_bool	is_line_vertical(int x1, int x2, int pitch)
{
	return (abs(x1 - x2) < pitch);
}

void		map_zoom(t_map_editor *map, double zoom)
{
	map->x -= map->unit * zoom * map->w / 2;
	map->y -= map->unit * zoom * map->h / 2;
	map->unit += map->unit * zoom;
}

// void	map_add_line(t_map *map, int n_sector, t_linedef *line)
// {
// 	t_sector	*sector;
// 	t_linedef	*tmp;
// 	int			i;

// 	sector = map->sectors;
// 	i = -1;
// 	while (++i < n_sector)
// 		sector = sector->next;
// 	if (sector->lines)
// 	{
// 		tmp = sector->lines;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		tmp->next = line;
// 	}
// 	else
// 		sector->lines = line;
// }

