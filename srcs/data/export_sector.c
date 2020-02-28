#include "doom_nukem.h"

int				export_sector(t_player *player, t_sector *sector, const char* filename)
{
	int		fd;

	if (!(fd = open(ft_strjoin("./maps/sectors/", filename), O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)))
		return(ret_error("failed to open/create file during export_sector"));
	write_player(player, fd);
	write_sector(sector, fd);
	return (1);
}