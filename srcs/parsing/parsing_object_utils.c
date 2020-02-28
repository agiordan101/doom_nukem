#include "doom_nukem.h"

char			*object_data_fill(char **tab, t_object **object, int i)
{
	char		*type;

	type = NULL;
	while (ft_strchr(tab[i], '}') == NULL)
	{
		if (ft_strstr(tab[i], "type = "))
			type = ft_strdup(ft_strrchr(tab[i], '=') + 2);
		if (ft_strstr(tab[i], "texture = "))
			(*object)->texture = ft_strdup(ft_strrchr(tab[i], '=') + 2);
		if (ft_strstr(tab[i], "posx = "))
			(*object)->pos_rotz_only.x = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "posy = "))
			(*object)->pos_rotz_only.y = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "posz = "))
			(*object)->pos_rotz_only.z = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "width = "))
			(*object)->width = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "height = "))
			(*object)->height = ft_atoi(ft_strrchr(tab[i], '=') + 1);
		if (ft_strstr(tab[i], "light = "))
			(*object)->light_coef = ft_atoi(ft_strrchr(tab[i], '=') + 1) / 100.0;
		if (ft_strstr(tab[i], "data = "))
			(*object)->data = ft_atoi(ft_strrchr(tab[i], '=') + 1) / 100.0;
		if (ft_strstr(tab[i], "dir = "))
			(*object)->dir = ft_atof(ft_strrchr(tab[i], '=') + 1);
		i++;
	}
	return (type);
}

// void			save_lights(t_map *map)
// {
// 	t_object	*object;
// 	t_object	*last_light;
// 	int			i;

// 	last_light = NULL;
// 	i = 0;
// 	object = map->objects;
// 	while (object)
// 	{
// 		if (object->type == LIGHT)
// 		{
// 			printf("New light : %p\n", object);
// 			if (last_light)
// 				last_light->next_light = object;
// 			else
// 				map->lights = object;
// 			last_light = object;
// 		}
// 		object = object->next;
// 	}
// }
