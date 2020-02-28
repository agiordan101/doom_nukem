#include "doom_nukem.h"

void		fill_mob_data_norm(t_mob **mob, char *tab)
{
	if (ft_strstr(tab, "type = "))
		(*mob)->type = ft_atoi(ft_strrchr(tab, '=') + 1);
	if (ft_strstr(tab, "posx = "))
		(*mob)->pos.x = ft_atoi(ft_strrchr(tab, '=') + 1);
	if (ft_strstr(tab, "posy = "))
		(*mob)->pos.y = ft_atoi(ft_strrchr(tab, '=') + 1);
	if (ft_strstr(tab, "posz = "))
		(*mob)->pos.z = ft_atoi(ft_strrchr(tab, '=') + 1);
	if (ft_strstr(tab, "dir = "))
		(*mob)->dir = ft_atoi(ft_strrchr(tab, '=') + 1);
	if (ft_strstr(tab, "light = "))
		(*mob)->light_coef = ft_atoi(ft_strrchr(tab, '=') + 1) / 100.0;
}

void		poly_del(t_poly *poly)
{
	t_poly *tmp_next;

	tmp_next = NULL;
	while (poly)
	{
		tmp_next = poly->next;
		free(poly);
		poly = tmp_next;
	}
	poly = NULL;
}
