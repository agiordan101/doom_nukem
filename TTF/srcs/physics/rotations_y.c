/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:24:14 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/20 13:55:52 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void				init_matrix_ry(t_player *player)
{
	player->ry.index_00 = cos(SENSITIVE);
	player->ry.index_01 = 0;
	player->ry.index_02 = sin(SENSITIVE);
	player->ry.index_10 = 0;
	player->ry.index_11 = 1;
	player->ry.index_12 = 0;
	player->ry.index_20 = -sin(SENSITIVE);
	player->ry.index_21 = 0;
	player->ry.index_22 = cos(SENSITIVE);
}

void				init_matrix_ry_inv(t_player *player)
{
	player->ry_inv.index_00 = cos(-SENSITIVE);
	player->ry_inv.index_01 = 0;
	player->ry_inv.index_02 = sin(-SENSITIVE);
	player->ry_inv.index_10 = 0;
	player->ry_inv.index_11 = 1;
	player->ry_inv.index_12 = 0;
	player->ry_inv.index_20 = -sin(-SENSITIVE);
	player->ry_inv.index_21 = 0;
	player->ry_inv.index_22 = cos(-SENSITIVE);
}

t_matrix			create_ry_matrix(float angle)
{
	return ((t_matrix){cos(angle), 0, sin(angle),\
						0, 1, 0,\
						-sin(angle), 0, cos(angle)});
}
