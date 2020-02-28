// #include "doom_nukem.h"

// static int		distance(t_dot p1, t_dot p2)
// {
// 	t_dot	v;

// 	v.x = abs(p2.x - p1.x);
// 	v.y = abs(p2.y - p1.y);
// 	return (sqrt(v.x * v.x + v.y * v.y));
// }

// SDL_bool 		is_next_to_linedef(t_map_editor *map, t_dot *dot, int radius)
// {
// 	SDL_bool	is_next;
// 	int			dist;
// 	t_sector	*s;
// 	t_linedef 	*l;
// 	t_dot		target;

// 	dist = -1;
// 	is_next = SDL_FALSE;
// 	s = map->sectors;
// 	if (dot)
// 	{
// 		while (s)
// 		{
// 			l = s->lines;
// 			while (l)
// 			{
// 				if (!((dot->x == l->p1.x && dot->y == l->p1.y) || (dot->x == l->p2.x && dot->y == l->p2.y)))
// 				{
// 					if (is_next_point(l->p1, *dot, radius))
// 					{
// 						if (dist == -1 ||  distance(*dot, l->p1) < dist)
// 						{
// 							dist = distance(*dot, l->p1);
// 							target = l->p1;
// 						}
// 						is_next = SDL_TRUE;
// 					}
// 					if (is_next_point(l->p2, *dot, radius))
// 					{
// 						if (dist == -1 ||  distance(*dot, l->p2) < dist)
// 						{
// 							dist = distance(*dot, l->p2);
// 							target = l->p2;
// 						}
// 						is_next = SDL_TRUE;
// 					}
// 				}
// 				l = l->next;
// 			}
// 			s = s->next;
// 		}
// 	}
// 	if (is_next)
// 		*dot = target;
// 	return (is_next);
// }

// void	fill_abscissa_ordinate(t_map_editor *map, t_dot mouse, int gap)
// {
// 	t_sector	*s;
// 	t_linedef	*l;
// 	SDL_bool	a_filled;
// 	SDL_bool	o_filled;

// 	s = map->sectors;
// 	a_filled = SDL_FALSE;
// 	o_filled = SDL_FALSE;
// 	while (s)
// 	{
// 		l = s->lines;
// 		while (l)
// 		{
// 			if (mouse.x > l->p1.x - gap / map->unit && mouse.x < l->p1.x + gap / map->unit)
// 			{
// 				map->abscissa = (t_line){(t_dot){l->p1.x, mouse.y}, l->p1};
// 				a_filled = SDL_TRUE;
// 			}
// 			if (mouse.y > l->p1.y - gap / map->unit && mouse.y < l->p1.y + gap / map->unit)
// 			{
// 				map->ordinate = (t_line){(t_dot){mouse.x, l->p1.y}, l->p1};
// 				o_filled = SDL_TRUE;
// 			}
// 			if (mouse.x > l->p2.x - gap / map->unit && mouse.x < l->p2.x + gap / map->unit)
// 			{
// 				map->abscissa = (t_line){(t_dot){l->p2.x, mouse.y}, l->p2};
// 				a_filled = SDL_TRUE;
// 			}
// 			if (mouse.y > l->p2.y - gap / map->unit && mouse.y < l->p2.y + gap / map->unit)
// 			{
// 				map->ordinate = (t_line){(t_dot){mouse.x, l->p2.y}, l->p2};
// 				o_filled = SDL_TRUE;
// 			}
// 			l = l->next;
// 		}
// 		s = s->next;
// 	}
// 	map->abscissa_b = a_filled;
// 	map->ordinate_b = o_filled;
// 	if (!a_filled)
// 		map->abscissa = (t_line){(t_dot){0, 0}, (t_dot){0, 0}};
// 	if (!o_filled)
// 		map->ordinate = (t_line){(t_dot){0, 0}, (t_dot){0, 0}};
// }

// SDL_bool		is_line_horizontally(t_dot lp1, t_dot lp2, float angle)
// {
// 	t_dot	p1;
// 	t_dot	p2;
// 	int		dx;
// 	int		dy;
// 	float	line_angle;

// 	if (lp1.x == lp2.x)
// 		return (SDL_FALSE);
// 	if (lp1.x < lp2.x)
// 	{
// 		p1 = lp1;
// 		p2 = lp2;
// 	}
// 	else
// 	{
// 		p1 = lp2;
// 		p2 = lp1;
// 	}
// 	if (p1.y > p2.y)
// 	{
// 		lp1 = p1;
// 		p1.y = p2.y;
// 		p2.y = lp1.y;
// 	}
// 	dy = p2.y - p1.y;
// 	dx = p2.x - p1.x;
// 	line_angle = atan(dy/(float)dx) * 180 / M_PI;
// 	return ((line_angle < angle) ? SDL_TRUE : SDL_FALSE);
// }


// SDL_bool		is_line_vertically(t_dot lp1, t_dot lp2, float angle)
// {
// 	t_dot	p1;
// 	t_dot	p2;

// 	p1.x = lp1.y;
// 	p1.y = lp1.x;
// 	p2.x = lp2.y;
// 	p2.y = lp2.x;
// 	return (is_line_horizontally(p1, p2, angle));
// }