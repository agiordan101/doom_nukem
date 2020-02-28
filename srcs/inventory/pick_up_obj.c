// #include "doom_nukem.h"

// void	del_poly_obj()
// {

// }

// int comp_pos(t_fdot_3d *pPlayer, t_fdot_3d *pObject)
// {

// 	if ((pPlayer->x == pObject->x) && (pPlayer->y == pObject->y) && (pPlayer->z == pObject->z))
// 		return (1);
// 	else
// 		return (0);
// }

// // (*poly)->dots[index].x = ft_atoi(ft_strrchr(tab[i], 'x') + 2);
// // (*poly)->dots[index].y = ft_atoi(ft_strrchr(tab[i], 'y') + 2);
// // (*poly)->dots[index].z = ft_atoi(ft_strrchr(tab[i], 'z') + 2);


// void 	pick_obj(t_map *map)
// {
// 	while (map->polys)
// 	{	
// 		if (ft_strcmp(map->polys->type, "object") == 0)
// 		{
// 			if (comp_pos(&(map->player.pos), &(map->polys->dots)) == 1)
// 			{
				
// 			}
// 		}
// 		map->polys = map->polys->next;
// 	}
// }