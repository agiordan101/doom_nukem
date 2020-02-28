#include "doom_nukem.h"

void		ft_find_coord_p1(t_linedef *line, char *tab)
{
	line->p1.x = ft_atoi(ft_strrchr(tab, '(') + 1);
	line->p1.y = ft_atoi(ft_strrchr(tab, ',') + 1);
}

void		ft_find_coord_p2(t_linedef *line, char *tab)
{
	line->p2.x = ft_atoi(ft_strrchr(tab, '(') + 1);
	line->p2.y = ft_atoi(ft_strrchr(tab, ',') + 1);
}

int			ft_chose_type(char *tab)
{
	int type;

	type = 0;
	if (!ft_strcmp(tab, "WALL"))
		type = WALL;
	else if (!ft_strcmp(tab, "PORTAL"))
		type = PORTAL;
	else if (!ft_strcmp(tab, "DOOR_CLOSE"))
		type = DOOR_CLOSE;
	else if (!ft_strcmp(tab, "DOOR_OPEN"))
		type = DOOR_OPEN;
	return (type);
}

void		ft_find_type(char *tab, t_linedef *line)
{
	char *tmp;

	tmp = NULL;
	tmp = ft_strdup(ft_strrchr(tab, '=') + 2);
	line->flags = ft_chose_type(tmp);
	ft_strdel(&tmp);
}

void		ft_find_id(char *id, t_linedef *line)		//////agiordan
{
	char	*tmp;

	tmp = NULL;
	tmp = ft_strdup(ft_strrchr(id, '=') + 2);
	line->id = ft_atoi(tmp);
	ft_strdel(&tmp);
}
