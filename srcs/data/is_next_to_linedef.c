#include "doom_nukem.h"

static int		distance(t_dot p1, t_dot p2)
{
	t_dot	v;

	v.x = abs(p2.x - p1.x);
	v.y = abs(p2.y - p1.y);
	return (sqrt(v.x * v.x + v.y * v.y));
}

static int		is_next_to_lines(t_linedef **lines, t_dot *dot, int radius, t_dot *target)
{
	SDL_bool	is_next;
	int			dist;
	t_linedef	*l;
	
	is_next = SDL_FALSE;
	dist = -1;
	l = *lines;
	while (l)
	{
		if (!((dot->x == l->p1.x && dot->y == l->p1.y) || (dot->x == l->p2.x && dot->y == l->p2.y)))
			{
				if (is_next_point(l->p1, *dot, radius))
				{
					if (dist == -1 || distance(*dot, l->p1) < dist)
					{
						dist = distance(*dot, l->p1);
						*target = l->p1;
					}
					is_next = SDL_TRUE;
				}
				if (is_next_point(l->p2, *dot, radius))
				{
					if (dist == -1 || distance(*dot, l->p2) < dist)
					{
						dist = distance(*dot, l->p2);
						*target = l->p2;
					}
					is_next = SDL_TRUE;
				}
			}
		l = l->next;
	}
	return ((is_next) ? dist : -1);
}

SDL_bool 		is_next_to_linedef(t_map_editor *map, t_dot *dot, int radius)
{
	SDL_bool	is_next;
	int			dist;
	t_sector	*s;
	t_linedef 	*l;
	t_dot		target;

	is_next = SDL_FALSE;
	s = map->sectors;
	l = map->lines;
	if (dot)
	{
		if ((dist = is_next_to_lines(&map->lines, dot, radius, &target)) != -1)
			is_next = SDL_TRUE;
		while (s)
		{
			l = s->lines;
			while (l)
			{
				if (!((dot->x == l->p1.x && dot->y == l->p1.y) || (dot->x == l->p2.x && dot->y == l->p2.y)))
				{
					if (is_next_point(l->p1, *dot, radius))
					{
						if (dist == -1 ||  distance(*dot, l->p1) < dist)
						{
							dist = distance(*dot, l->p1);
							target = l->p1;
						}
						is_next = SDL_TRUE;
					}
					if (is_next_point(l->p2, *dot, radius))
					{
						if (dist == -1 ||  distance(*dot, l->p2) < dist)
						{
							dist = distance(*dot, l->p2);
							target = l->p2;
						}
						is_next = SDL_TRUE;
					}
				}
				l = l->next;
			}
			s = s->next;
		}
	}
	if (is_next)
		*dot = target;
	return (is_next);
}