#include "doom_nukem.h"

/*
**	x,y = coordonnees de la souris
**	end = False si debut du drag
**	end = True si fin du drag
*/

t_dot		mouse_drag(int x, int y, SDL_bool end)
{
	static t_dot pos = (t_dot){0, 0};

	if (!end)
	{
		pos = (t_dot){x, y};
		return ((t_dot){0, 0});
	}
	else
		return ((t_dot){x - pos.x, y - pos.y});
}