/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:31:31 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/06 17:29:46 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	create_ray(t_cartesienne *ray, float angle_xy, float angle_zx)
{
	ray->ox = 0;
	ray->oy = 0;
	ray->oz = 0;
	ray->vx = 1;
	ray->vy = angle_xy;
	ray->vz = angle_zx;
	ray->dist = -1;
	ray->poly = NULL;
	ray->color = 0xFF505050;
	ray->next = NULL;
}

int			malloc_ray(t_win *win, t_player *player,\
								float angle_zx, int coord_y)
{
	float	angle_xy;
	float	dangle_xy;
	int		coord_x;

	dangle_xy = player->fov / win->w;
	if (!(player->rays[coord_y] = (t_cartesienne *)malloc(\
										sizeof(t_cartesienne) * (win->w + 1))))
		return (1);
	angle_xy = -player->fov_2;
	coord_x = -1;
	while (++coord_x < win->w)
	{
		create_ray(&(player->rays[coord_y][coord_x]), angle_xy, angle_zx);
		angle_xy += dangle_xy;
	}
	return (0);
}

int			init_rays(t_win *win, t_player *player)
{
	float	angle_zx;
	float	dangle_zx;
	int		coord_y;

	dangle_zx = player->fov_up / win->h;
	if (!(player->rays = (t_cartesienne **)malloc(sizeof(t_cartesienne *) *\
																(win->h + 1))))
		return (1);
	player->rays[win->h] = NULL;
	angle_zx = player->fov_up_2;
	coord_y = -1;
	while (++coord_y < win->h)
	{
		if (malloc_ray(win, player, angle_zx, coord_y))
			return (1);
		angle_zx -= dangle_zx;
	}
	return (0);
}

int			init_threads(t_win *win, t_map *map, t_player *player)
{
	int		i;

	if (!(win->threads = (t_thread *)malloc(sizeof(t_thread) * N_THREADS)))
		return (1);
	i = -1;
	while (++i < N_THREADS)
	{
		win->threads[i].i = i;
		win->threads[i].win = win;
		win->threads[i].map = map;
		win->threads[i].player = player;
	}
	return (0);
}
