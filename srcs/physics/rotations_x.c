#include "doom_nukem.h"

/*
**	ATTENTION les sin doivent doivent etre inverse par rapport aux matrixs normales
*/

void				init_matrix_rx(t_player *player)
{
	player->rx._00 = 1;
	player->rx._01 = 0;
	player->rx._02 = 0;
	player->rx._10 = 0;
	player->rx._11 = cos(player->ddir);
	player->rx._12 = -sin(player->ddir);
	player->rx._20 = 0;
	player->rx._21 = sin(player->ddir);
	player->rx._22 = cos(player->ddir);
}

void				init_matrix_rx_inv(t_player *player)
{
	player->rx_inv._00 = 1;
	player->rx_inv._01 = 0;
	player->rx_inv._02 = 0;
	player->rx_inv._10 = 0;
	player->rx_inv._11 = cos(-player->ddir);
	player->rx_inv._12 = -sin(-player->ddir);
	player->rx_inv._20 = 0;
	player->rx_inv._21 = sin(-player->ddir);
	player->rx_inv._22 = cos(-player->ddir);
}

t_matrix			create_rx_matrix(float angle)
{
	return ((t_matrix){1, 0, 0, 0, cos(-angle), -sin(-angle), 0, sin(-angle), cos(-angle)});
}

// t_matrix			create_matrix(t_fdot_3d axe, float angle)
// {
// 	float			c;
// 	float			s;

// 	c = cos(angle);
// 	s = cos(angle);
// 	return ((t_matrix){	axe.x * axe.x * (1 - c) + c,\
// 						axe.x * axe.y * (1 - c) - axe.z * s,\
// 						axe.x * axe.z * (1 - c) + axe.y * s,\
// 						axe.y * axe.x * (1 - c) + axe.z * s,\
// 						axe.y * axe.y * (1 - c) + c,\
// 						axe.y * axe.z * (1 - c) - axe.x * s,\
// 						axe.z * axe.x * (1 - c) - axe.y * c,\
// 						axe.z * axe.y * (1 - c) + axe.x * s,\
// 						axe.z * axe.z * (1 - c) + c});
// }