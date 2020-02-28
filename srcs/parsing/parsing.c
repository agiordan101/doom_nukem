#include "doom_nukem.h"
#include "ui_error.h"

void		find_texture(char *tab, t_poly *poly)
{
	char *tmp;
	char *name;

	name = NULL;
	tmp = NULL;
	name = ft_strdup(ft_strrchr(tab, '=') + 2);
	poly->texture_name = name;
	tmp = ft_strdup("textures/");
	tmp = ft_strjoin(tmp, name);
	if (!(poly->texture = IMG_Load(tmp)))
	{
		exit(0);
		return ;
	}
	poly->texture = SDL_ConvertSurfaceFormat(poly->texture,
					SDL_PIXELFORMAT_ARGB8888, 0);
	free(tmp);
}

void		ft_fill_data(char **tab, t_poly **poly, int i)
{
	int index;

	index = 0;
	add_poly(poly);
	(*poly)->object = NULL;
	(*poly)->mob = NULL;
	while ((ft_strchr(tab[i], '}') == NULL))
	{
		if (ft_strstr(tab[i], "dot = "))	// Dangereux si il y a x y ou z sur la meme ligne
		{
			(*poly)->dots_rotz_only[index].x = ft_atoi(ft_strrchr(tab[i], 'x') + 2);
			(*poly)->dots_rotz_only[index].y = ft_atoi(ft_strrchr(tab[i], 'y') + 2);
			(*poly)->dots_rotz_only[index].z = ft_atoi(ft_strrchr(tab[i], 'z') + 2);
			index++;
		}
		if (ft_strstr(tab[i], "texture ="))
			find_texture(tab[i], *poly);
		if (ft_strstr(tab[i], "light = "))
		{
			(*poly)->light_coef = ft_atoi(ft_strrchr(tab[i], '=') + 1) / 100.0;
			printf("Str = '%s'\tCoef = %f\n", ft_strrchr(tab[i], '=') + 1, (*poly)->light_coef);
		}
		i++;
	}
}

void		fill_poly_mob(t_poly *poly, t_mob *mob)
{
	char *tmp;

	tmp = NULL;
	while (poly->next)
		poly = poly->next;
	while (mob)
	{
		tmp = ft_strdup("textures/");
		poly->next = mob->poly;
		poly->light_coef = mob->light_coef;
		poly = poly->next;
		tmp = ft_strjoin(tmp, mob->texture);
		if (!(poly->texture = IMG_Load(tmp)))
		{
			exit(0);
			return ;
		}
		poly->texture = SDL_ConvertSurfaceFormat(poly->texture,
						SDL_PIXELFORMAT_ARGB8888, 0);
		mob = mob->next;
		free(tmp);
	}
}

void		fill_poly_object(t_poly *poly, t_object *object)
{
	char	*tmp;
	t_poly	*poly_object;

	tmp = NULL;
	while (poly->next)
		poly = poly->next;
	while (object)
	{
		tmp = ft_strjoin("textures/", object->texture);
		poly_object = object->poly;
		poly->light_coef = object->light_coef;
		while (poly_object)
		{
			fill_poly_object_norm(tmp, poly_object);
			poly->next = poly_object;
			poly = poly->next;
			poly_object = poly_object->next;
			// printf("Poly : %p, plan  %f %f %f\n", poly, poly->dots_rotz_only[0].x, poly->dots_rotz_only[0].y, poly->dots_rotz_only[0].z);
		}
		ft_strdel(&tmp);
		object = object->next;
	}
}

t_poly		*ft_data_storing(int fd, int fd1, t_map *map, t_win *win)
{
	char		**tab;
	int			i;
	t_poly		*poly;

	i = -1;
	poly = NULL;
	map->mob = NULL;
	map->objects = NULL;
	tab = fillntesttab(fd, fd1);
	win->texhud = define_texhud(win);
	while (tab[++i])
	{
		printf("i %d\ttab i |%s\n", i, tab[i]);
		if (ft_strstr(tab[i], "Polygon"))
			ft_fill_data(tab, &poly, i);
		else if (ft_strstr(tab[i], "Object"))
		{
			if (object_data(tab, &(map->objects), i))
				return (NULL); //LEAKS - C'est temporaire
		}
		else if (ft_strstr(tab[i], "Player"))
			player_data(tab, &(map->player), i);
		else if (ft_strstr(tab[i], "Mob"))
			fill_mob_data(&(map->mob), tab, i);
	}
	fill_poly(poly, map);
	return (poly);
}
