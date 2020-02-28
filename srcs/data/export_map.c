#include "doom_nukem.h"

int		export_map(t_map_editor *map, const char *filename)
{
	int 		fd;
	t_sector	*s;

	if (!(fd = open(ft_strjoin("./maps/", filename),  O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)))
			return (ret_error("failed to open/create file during export_map"));
	write_player(&map->player, fd);
	s = map->sectors;
	while (s)
	{
		write_sector(s, fd);
		s = s->next;
	}
	return (1);
}