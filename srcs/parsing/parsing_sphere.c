/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:54:45 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/16 23:27:15 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

static void		fill_sphere_pos(t_sphere *sphere, char **tab, int i)
{
	if (ft_strstr(tab[i], "posx ="))
		sphere->pos_rotz_only.x = ft_atoi(ft_strrchr(tab[i], '=') + 1);
	else if (ft_strstr(tab[i], "posy ="))
		sphere->pos_rotz_only.y = ft_atoi(ft_strrchr(tab[i], '=') + 1);
	else if (ft_strstr(tab[i], "posz ="))
		sphere->pos_rotz_only.z = ft_atoi(ft_strrchr(tab[i], '=') + 1);
}

static void		fill_sphere(t_sphere *sphere, char **tab, int i)
{
	char		*tmp;

	while ((ft_strchr(tab[i], '}') == NULL))
	{
		fill_sphere_pos(sphere, tab, i);
		if (ft_strstr(tab[i], "texture = "))
		{
			tmp = ft_strjoin("textures/", ft_strrchr(tab[i], '=') + 2);
			if ((sphere->texture = IMG_Load(tmp)))
			{
				sphere->texture = SDL_ConvertSurfaceFormat(\
								sphere->texture, SDL_PIXELFORMAT_ARGB8888, 0);
			}
			else
				ui_ret_error("fill_sphere", SDL_GetError(), 0);
			ft_strdel(&tmp);
		}
		else if (ft_strstr(tab[i], "radius = "))
			sphere->radius = ft_atoi(ft_strrchr(tab[i], '=') + 2);
		i++;
	}
}

void			new_sphere(t_sphere *sphere, char **tab, int i)
{
	sphere->pos_rotz_only = (t_fdot_3d){0, 0, 0};
	sphere->pos = (t_fdot_3d){0, 0, 0};
	sphere->radius = 1000;
	sphere->i_rotz_only = (t_fdot_3d){0, 0, -1};
	sphere->i = (t_fdot_3d){0, 0, -1};
	sphere->j_rotz_only = (t_fdot_3d){1, 0, 0};
	sphere->j = (t_fdot_3d){1, 0, 0};
	fill_sphere(sphere, tab, i);
}
