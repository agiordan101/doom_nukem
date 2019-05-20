#include "doom_nukem.h"

void		ft_find_coord_p1(t_sector *sector, char *tab)
{
	sector->lines->p1.x = ft_atoi(ft_strrchr(tab, '(') + 1);
	sector->lines->p1.y = ft_atoi(ft_strrchr(tab, ',') + 1);
}

void		ft_find_coord_p2(t_sector *sector, char *tab)
{
	sector->lines->p2.x = ft_atoi(ft_strrchr(tab, '(') + 1);
	sector->lines->p2.y = ft_atoi(ft_strrchr(tab, ',') + 1);
}
