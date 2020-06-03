/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:56:29 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/19 09:38:57 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void				draw(t_win *win, t_map *map, t_player *player)
{
	if (player->sneak)
	{
		translate_all_poly_rotz_only(map->polys,\
				(t_fdot_3d){0, 0, map->player.f_height_10});
		copy_rotate_rotz_only(map, map->polys,\
				create_ry_matrix(-player->rot_y));
		translate_all_poly_rotz_only(map->polys,\
				(t_fdot_3d){0, 0, -map->player.f_height_10});
	}
	else
		copy_rotate_rotz_only(map, map->polys,\
				create_ry_matrix(-player->rot_y));
	objects_movements(map, player, map->objects);
	clear_rend(win->rend, 0x40, 0x40, 0x40);
	graphics_engine(win, map);
	reload_cd(map);
	hud(win, player, win->texhud);
	print_content_slot(win, player, win->texhud);
}

static int			select_color(t_thread *thread, t_cartesienne *ray)
{
	if (ray->poly)
		return (process_light(thread->win->map, ray->poly,\
								ray->collision, ray->color));
	else
		return (thread->win->map->sky_box.texture ?\
								sky_box(&(thread->win->map->sky_box), ray) :\
								(int)0xFF505050);
}

void				*draw_ray(void *param)
{
	t_thread		*thread;
	t_cartesienne	*ray;
	int				x;
	int				y;
	int				y_max;

	thread = (t_thread *)param;
	y = (thread->i / (float)N_THREADS) * thread->win->h - 1;
	y_max = ((thread->i + 1) / (float)N_THREADS) * thread->win->h;
	while (++y < y_max)
	{
		x = -1;
		while (++x < thread->win->w)
		{
			ray = &(thread->player->rays[y][x]);
			thread->win->pixels[y * thread->win->w + x] =\
													select_color(thread, ray);
			ray->poly = NULL;
			ray->color = 0xFF505050;
		}
	}
	return (NULL);
}

void				draw_projection(t_win *win)
{
	t_poly			*poly;
	int				i;

	poly = win->map->polys;
	SDL_SetRenderDrawColor(win->rend, 0x50, 0xEE, 0x50, 0xFF);
	while (poly)
	{
		i = -1;
		if ((poly->object && poly->object->visible) ||\
			(!poly->object && poly->visible))
			while (++i < poly->n_proj)
				draw_line(win, poly->dots_proj[i],\
							poly->dots_proj[i ? i - 1 : poly->n_proj - 1]);
		poly = poly->next;
	}
}

void				draw_all_square(t_win *win)
{
	t_poly			*poly;

	poly = win->map->polys;
	SDL_SetRenderDrawColor(win->rend, 0x50, 0x50, 0xEE, 0xFF);
	while (poly)
	{
		if ((poly->object && poly->object->visible) ||\
			(!poly->object && poly->visible))
		{
			draw_line(win, (t_dot){poly->box_x.x, poly->box_y.x},\
							(t_dot){poly->box_x.y, poly->box_y.x});
			draw_line(win, (t_dot){poly->box_x.x, poly->box_y.x},\
							(t_dot){poly->box_x.x, poly->box_y.y});
			draw_line(win, (t_dot){poly->box_x.y, poly->box_y.x},\
							(t_dot){poly->box_x.y, poly->box_y.y});
			draw_line(win, (t_dot){poly->box_x.x, poly->box_y.y},\
							(t_dot){poly->box_x.y, poly->box_y.y});
		}
		poly = poly->next;
	}
}
