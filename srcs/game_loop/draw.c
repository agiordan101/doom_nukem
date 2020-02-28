#include "doom_nukem.h"

/*
**	Il ne faut pas allonger l'image en largeur mais la repete
**	En hauteur aussi
**
**	player->dir_up est le milieu y du mur sur lecran,
**	On +/- le y du perso et le sneak.
**	La vision du perso retrecie en haut et en bas (On diminue HEIGHT_WALL)
**	On multiplie car prop() joue un role de facteur d'agrandissement
**	La taille du mur depend de la distance jusqua lui (1 / lenray)
**	On alonge ou retrecie haut et bas selon
**		les diff de hauteurs z entre le secteur et le perso
**
*/

// static void	draw_map(t_win *win, t_map *map)
// {
// 	t_sector	*sector;
// 	t_linedef	*line;
// 	t_dot		x;
// 	t_dot		y;
// 	t_dot		width;
// 	t_dot		height;

// 	SDL_SetRenderDrawColor(win->rend, 192, 244, 238, 255);
// 	width = (t_dot){win->w * 0.72, win->w * 0.97};
// 	height = (t_dot){win->h * 0.025, win->h * 0.275};
// 	x = (t_dot){10000000, -100000000};
// 	y = (t_dot){10000000, -100000000};
// 	sector = map->sectors;
// 	while (sector)
// 	{
// 		line = sector->lines;
// 		while (line)
// 		{
// 			if (line->p1.x < x.x)
// 				x.x = line->p1.x;
// 			if (line->p2.x < x.x)
// 				x.x = line->p2.x;
// 			if (line->p1.x > x.y)
// 				x.y = line->p1.x;
// 			if (line->p2.x > x.y)
// 				x.y = line->p2.x;
// 			if (line->p1.y < y.x)
// 				y.x = line->p1.y;
// 			if (line->p2.y < y.x)
// 				y.x = line->p2.y;
// 			if (line->p1.y > y.y)
// 				y.y = line->p1.y;
// 			if (line->p2.y > y.y)
// 				y.y = line->p2.y;
// 			line = line->next;
// 		}
// 		sector = sector->next;
// 	}
// 	// x = (t_dot){500, win->w};	//Pour annuler le rescale
// 	// y = (t_dot){0, win->h};
// 	sector = map->sectors;
// 	while (sector)
// 	{
// 		line = sector->lines;
// 		while (line)
// 		{
// 			draw_line(win, (t_dot){prop(line->p1.x, x, width),\
// 									prop(line->p1.y, y, height)},\
// 							(t_dot){prop(line->p2.x, x, width),\
// 									prop(line->p2.y, y, height)});
// 			line = line->next;
// 		}
// 		sector = sector->next;
// 	}

// 	draw_circle(win, (t_circle){prop(map->player.pos.x, x, width),\
// 							prop(map->player.pos.y, y, height), map->player.width / 2});
// 	draw_line(win,	(t_dot){prop(map->player.pos.x, x, width),\
// 							prop(map->player.pos.y, y, height)},\
// 					(t_dot){prop(map->player.pos.x + 30 * cos(map->player.dir), x, width),\
// 							prop(map->player.pos.y + 30 * sin(map->player.dir), y, height)});

// }
