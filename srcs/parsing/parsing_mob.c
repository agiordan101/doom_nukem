#include "doom_nukem.h"

void    set_mobs_dots_rotz_only(t_mob *mob)
{
    mob->poly->dots_rotz_only[0].x = mob->pos.x - mob->width_2;
    mob->poly->dots_rotz_only[0].y = mob->pos.y;
    mob->poly->dots_rotz_only[0].z = mob->pos.z - mob->height_2;
    mob->poly->dots_rotz_only[1].x = mob->pos.x + mob->width_2;
    mob->poly->dots_rotz_only[1].y = mob->pos.y;
    mob->poly->dots_rotz_only[1].z = mob->pos.z - mob->height_2;
    mob->poly->dots_rotz_only[2].x = mob->pos.x + mob->width_2;
    mob->poly->dots_rotz_only[2].y = mob->pos.y;
    mob->poly->dots_rotz_only[2].z = mob->pos.z + mob->height_2;
    mob->poly->dots_rotz_only[3].x = mob->pos.x - mob->width_2;
    mob->poly->dots_rotz_only[3].y = mob->pos.y;
    mob->poly->dots_rotz_only[3].z = mob->pos.z + mob->height_2;
}

void		add_mob(t_mob **mob)
{
	t_mob	*new_mob;

	if (!(new_mob = (t_mob *)ft_memalloc(sizeof(t_mob))))
		ft_putendl("error malloc in parsing_mob.c l.24");
	new_mob->next = *mob;
	new_mob->alive = 1;
	*mob = new_mob;
}

void		add_existing_mob(t_mob **mob, t_mob *new_mob)
{
	if (new_mob)
	{
		new_mob->next = *mob;
		*mob = new_mob;
	}
}

void		add_poly_mob(t_mob **mob)
{
    (*mob)->poly = (t_poly *)ft_memalloc(sizeof(t_poly));
    if ((*mob)->poly != NULL)
	{
        set_mobs_dots_rotz_only(*mob);
		(*mob)->poly->mob = *mob;
		(*mob)->poly->object = NULL;
	}
}

void		fill_mob_data(t_mob **mob, char **tab, int i)
{
	add_mob(mob);
	while (ft_strchr(tab[i], '}') == NULL)
	{
		fill_mob_data_norm(mob, tab[i]);
		if (ft_strstr(tab[i], "width = "))
		{
			(*mob)->width = ft_atoi(ft_strrchr(tab[i], '=') + 1);
			(*mob)->width_2 = (*mob)->width / 2;
		}
		if (ft_strstr(tab[i], "height = "))
		{
			(*mob)->height = ft_atoi(ft_strrchr(tab[i], '=') + 1);
			(*mob)->height_2 = (*mob)->height / 2;
		}
		if (ft_strstr(tab[i], "velocity = "))
			(*mob)->vel = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "health = "))
			(*mob)->health = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "damage = "))
			(*mob)->damage = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "texture = "))
			(*mob)->texture = ft_strdup(ft_strrchr(tab[i], '=') + 2);
		i++;
	}
	add_poly_mob(mob);
}
