// #include "doom_nukem.h"

// void	check_file(t_map_editor *map)
// {
// 	t_sector	*sector;
// 	t_linedef	*line;
// 	t_linedef	*last;
// 	t_linedef	*tmp;

// 	sector = map->sectors;
// 	while (sector)
// 	{
// 		tmp = NULL;
// 		line = sector->lines;
// 		while (line)
// 		{
// 			if (line->p1.x == line->p2.x && line->p1.y == line->p2.y)
// 			{
// 				if (last)
// 					last->next = line->next;
// 				else
// 					sector->lines = line->next;
// 				ft_strdel(&(line->name));
// 				tmp = line;
// 				line = line->next;
// 				free(line);
// 			}
// 			else
// 			{
// 				last = line;
// 				line = line->next;
// 			}
// 		}
// 		sector = sector->next;
// 	}
// }
