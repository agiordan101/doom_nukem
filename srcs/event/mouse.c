#include "doom_nukem.h"

t_mouse		*mouse_refresh()
{
	int		i;
	Uint32	tmp;
	static t_mouse mouse = (t_mouse){0, 0, 
									SDL_FALSE,
									{(t_mouse_button){0, 0, 0},
									(t_mouse_button){0, 0, 0},
									(t_mouse_button){0, 0, 0}}};

	tmp = mouse.flags;
	mouse.flags = SDL_GetMouseState(&mouse.x, &mouse.y);
	i = 1;
	while (i < 4)
	{			
		if (!(tmp & SDL_BUTTON(i)) && (mouse.flags & SDL_BUTTON(i)))
		{
			mouse.button[i - 1].pressing = SDL_TRUE;
			mouse.button[i - 1].pressed = SDL_TRUE;
			mouse.button[i - 1].releasing = SDL_FALSE;
		}
		else if ((tmp & SDL_BUTTON(i)) && !(mouse.flags & SDL_BUTTON(i)))
		{
			mouse.button[i - 1].releasing = SDL_TRUE;
			mouse.button[i - 1].pressing = SDL_FALSE;
			mouse.button[i - 1].pressed = SDL_FALSE;
		}
		else
		{
			mouse.button[i - 1].pressing = SDL_FALSE;
			mouse.button[i - 1].releasing = SDL_FALSE;
		}
		i++;
	}
	return (&mouse);
}

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