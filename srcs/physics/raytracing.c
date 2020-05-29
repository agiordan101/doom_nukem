/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:18:49 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/24 14:08:19 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui_error.h"

/*
**	- Times of 'raycasting_3d()' : ~125-140 . 10e-3
**	Surround wall :		0.0
**	Raycasting :		~120-135
**		nSquare_tracing	0 - 0 - ~78 - 0 - ~33 - ~9 = always ~115-125
**		Draw			~8
**	Projection draw :	1
**	Square draw :		2
**
**	- Time of 'collisions()' : ~0.0 . 10e-3
**	- Nouveau 'collisions_sphere()' :	~ 0.5-1.7	. 10e-4
**	- Nouveau 'raycasting_3d()' :		~ 280-400	. 10e-4
**	- Nouveau 'game()' :				~ 280-400	. 10e-4
**			(Pareil que raycasting_3d())
**
**
**	// clock_t		t1;
**	// clock_t		t2;
**	// t1 = clock();
**	// t2 = clock();
**	// printf("Delta time %lf\n", ((float)t2 - t1) / (float)CLOCKS_PER_SEC);
*/

static int			find_pixel(t_poly *poly, t_fdot_3d collision)
{
	t_fdot			coord_plan;
	t_dot			coord_texture;

	if (!is_in_poly(poly, &coord_plan, collision))
		return (-1);
	if (!poly->texture)
		return (0xFFFF00FF);
	coord_texture = (poly->object || poly->mob) ?\
				(t_dot){coord_plan.x * poly->texture->w,\
						(1 - coord_plan.y) * poly->texture->h} :\
				(t_dot){modulo(coord_plan.x * poly->i_mag, poly->texture->w),\
						modulo(coord_plan.y * poly->j_mag, poly->texture->h)};
	return (((int *)poly->texture->pixels)[coord_texture.y * poly->texture->w +\
											coord_texture.x]);
}

static void			launch_ray_3d(t_poly *poly, t_cartesienne *ray)
{
	t_fdot_3d		collision;
	float			newdist;
	int				color;

	if (!intersection_plan_my_ray(&collision, poly->equation, ray) ||\
		collision.x < 0)
		return ;
	newdist = collision.x * collision.x +\
				collision.y * collision.y +\
				collision.z * collision.z;
	if ((!ray->poly || newdist < ray->dist) &&\
		(color = find_pixel(poly, collision)) != -1 && (color >> 24) & 0xFF)
	{
		ray->poly = poly;
		ray->color = color;
		ray->collision = collision;
		ray->dist = newdist;
	}
}

static void			*square_tracing(void *param)
{
	t_thread		*thread;
	t_poly			*poly;
	int				x;
	int				y;
	int				y_max;

	thread = (t_thread *)param;
	poly = thread->poly;
	if (!poly)
		return (NULL);
	y = poly->box_y.x + (poly->box_y.y - poly->box_y.x) *\
		(thread->i / (float)N_THREADS) - 1;
	y_max = poly->box_y.x + (poly->box_y.y - poly->box_y.x) *\
			((thread->i + 1) / (float)N_THREADS);
	while (poly->visible && ++y < y_max)
	{
		x = poly->box_x.x;
		while (++x < poly->box_x.y)
			launch_ray_3d(poly, &(thread->player->rays[y][x]));
	}
	thread->poly = thread->poly->next;
	square_tracing(thread);
	return (NULL);
}

static void			raytracing(t_win *win, t_map *map)
{
	int				i;

	i = -1;
	while (++i < N_THREADS)
	{
		win->threads[i].poly = map->polys;
		pthread_create(&(win->threads[i].thread), NULL,\
						square_tracing, &(win->threads[i]));
	}
	i = -1;
	while (++i < N_THREADS)
		pthread_join(win->threads[i].thread, NULL);
	i = -1;
	while (++i < N_THREADS)
		pthread_create(&(win->threads[i].thread), NULL,\
						draw_ray, &(win->threads[i]));
	i = -1;
	while (++i < N_THREADS)
		pthread_join(win->threads[i].thread, NULL);
	SDL_UpdateTexture(win->rend_texture, NULL, win->pixels,\
						win->w * sizeof(Uint32));
	SDL_RenderCopy(win->rend, win->rend_texture, NULL, NULL);
}

void				graphics_engine(t_win *win, t_map *map)
{
	surround_walls(win, map);
	if (map->view & TEXTURE_VIEW)
		raytracing(win, map);
	if (map->view & WALL_VIEW)
		draw_projection(win);
	if (map->view & BOX_VIEW)
		draw_all_square(win);
	draw_fps();
}
