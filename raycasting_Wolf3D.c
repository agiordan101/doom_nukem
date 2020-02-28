/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 19:27:03 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:27:39 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	save_orientation : Save orientation S/N/E/W du mur touche.
**
**	save_texture	: Save la distance entre le point d'impact du rayon
**						et le 'debut' gauche du mur.
**
**	test_wall		: 1 si mur, 0 si vide, -1 si bords de map.
**						Et save des donnees selon le mode de texture.
**
**	affine_function : Parcourt la droite jusqu'a un mur.
**
**	raycasting		: Calcul les equations de droites representees par tout
**						les rayons et lance plusieures fois 'affine_function'.
*/

static void		save_orientation(t_calculs *calculs, t_dot_2d dot)
{
	if (ft_dec(dot.y))
	{
		if (calculs->vector.x > 0)
			calculs->orientation[calculs->i] = 1;
		else
			calculs->orientation[calculs->i] = 3;
	}
	else
	{
		if (calculs->vector.y > 0)
			calculs->orientation[calculs->i] = 2;
		else
			calculs->orientation[calculs->i] = 4;
	}
}

static void		save_texture(t_calculs *calculs, t_dot_2d dot)
{
	if (ft_dec(dot.y))
	{
		if (calculs->vector.x > 0)
			calculs->xray[calculs->i] = ft_dec(dot.y);
		else
			calculs->xray[calculs->i] = 1 - ft_dec(dot.y);
	}
	else
	{
		if (calculs->vector.y > 0)
			calculs->xray[calculs->i] = 1 - ft_dec(dot.x);
		else
			calculs->xray[calculs->i] = ft_dec(dot.x);
	}
}

static int		test_wall(t_win *win, t_map *map, t_calculs *calculs,\
																t_dot_2d dot)
{
	int	i;
	int	j;

	j = ft_dtoi_low(dot.x);
	i = ft_dtoi_low(dot.y);
	if (!ft_dec(dot.x))
		j -= calculs->vector.x >= 0 ? 0 : 1;
	if (!ft_dec(dot.y))
		i -= calculs->vector.y >= 0 ? 0 : 1;
	if (i < 0 || i >= map->len_y || j < 0 || j >= map->len_x)
		return (-1);
	if (map->tab[i][j] == 0 || map->tab[i][j] == 5 ||\
		map->tab[i][j] == PLAYER_TILE)
		return (0);
	save_texture(calculs, dot);
	if (win->textures_mode == 1)
		save_orientation(calculs, dot);
	else
		calculs->orientation[calculs->i] = map->tab[i][j];
	return (1);
}

void			affine_function(t_player *player, t_calculs *calculs,\
								t_dot_2d *next, t_dot_2d *nextindex)
{
	t_dot_2d	d1;
	t_dot_2d	d2;

	if (calculs->vector.x > 0)
		d1.x = ft_dtoi_up(player->pos.x) + nextindex->x;
	else
		d1.x = ft_dtoi_low(player->pos.x) + nextindex->x;
	if (calculs->vector.y > 0)
		d2.y = ft_dtoi_up(player->pos.y) + nextindex->y;
	else
		d2.y = ft_dtoi_low(player->pos.y) + nextindex->y;
	d1.y = calculs->a * d1.x + calculs->b;
	d2.x = (d2.y - calculs->b) / calculs->a;
	if (ft__abs(dist_dot_2d(d1, player->pos)) <\
		ft__abs(dist_dot_2d(d2, player->pos)))
	{
		*next = d1;
		nextindex->x += calculs->vector.x > 0 ? 1 : -1;
	}
	else
	{
		*next = d2;
		nextindex->y += calculs->vector.y > 0 ? 1 : -1;
	}
}

void			raycasting(t_win *win, t_player *player, t_calculs *calculs)
{
	double		dangle;
	t_dot_2d	next;
	t_dot_2d	nextindex;
	int			ret;

	dangle = player->fov / win->width;
	calculs->angle = player->fov / 2;
	calculs->i = -1;
	while (++(calculs->i) < win->width)
	{
		calculs->vector = (t_vector_2d){.origin = player->pos,\
							.x = cos(player->dir + calculs->angle),
							.y = -sin(player->dir + calculs->angle)};
		next = player->pos;
		nextindex = (t_dot_2d){.x = 0, .y = 0};
		calculs->a = calculs->vector.y / calculs->vector.x;
		calculs->b = calculs->vector.origin.y -\
									calculs->a * calculs->vector.origin.x;
		while ((ret = test_wall(win, &(win->map), calculs, next)) == 0)
			affine_function(player, calculs, &next, &nextindex);
		calculs->dist[calculs->i] = (ret == -1 ? -1 :\
		cos(calculs->angle) * dist_dot_2d(next, player->pos));
		calculs->angle -= dangle;
	}
}
