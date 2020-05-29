/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_maths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 22:48:53 by gal               #+#    #+#             */
/*   Updated: 2020/05/20 13:56:14 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

static void	init_matrix(t_win *win, t_player *player)
{
	init_matrix_rx(player);
	init_matrix_ry(player);
	init_matrix_rz(player);
	init_matrix_rx_inv(player);
	init_matrix_ry_inv(player);
	init_matrix_rz_inv(player);
	init_rays(win, player);
}

void		init_player_maths(t_win *win, t_player *player)
{
	win->map->view = TEXTURE_VIEW;
	translate_all_rotz_only(win->map, win->map->polys,
		(t_fdot_3d){-player->pos.x, -player->pos.y, -player->pos.z});
	rotate_all_rotz_only(win->map, win->map->polys,
						create_rz_matrix(-player->dir_init));
	win->map->gravity = player->const_vel / 2;
	player->jump = 0;
	player->rot_y = 0;
	player->fov = win->w * M_PI_2 / 1000;
	player->fov_up = win->h * M_PI_2 / 1000;
	player->fov_2 = player->fov / 2;
	player->fov_up_2 = player->fov_up / 2;
	player->width_2 = player->width / 2;
	player->f_height_10 = 2 * (float)player->height / 5;
	player->sneak = 0;
	player->collision_on = 1;
	player->fly = 0;
	win->w_div_fov = win->w / player->fov;
	win->h_div_fov = win->h / player->fov_up;
	init_matrix(win, player);
}
