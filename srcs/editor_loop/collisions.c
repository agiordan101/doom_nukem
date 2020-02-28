// #include "doom_nukem.h"

// SDL_bool	is_in_rect(SDL_Rect rect, t_dot p)
// {
// 	int		tmp;
	
// 	if (rect.w < 0)
// 	{
// 		tmp = rect.x;
// 		rect.x = rect.x + rect.w;
// 		rect.w = tmp - rect.x;
// 	}
// 	if (rect.h < 0)
// 	{
// 		tmp = rect.y;
// 		rect.y = rect.y + rect.h;
// 		rect.h = tmp - rect.y;
// 	}
// 	return (p.x > rect.x &&
// 			p.x < rect.x + rect.w &&
// 			p.y > rect.y &&
// 			p.y < rect.y + rect.h);
// }

// SDL_bool	intersect_line_rect(t_line line, SDL_Rect rect)
// {
// 	int		tmp;
// 	if (rect.w < 0)
// 	{
// 		tmp = rect.x;
// 		rect.x = rect.x + rect.w;
// 		rect.w = tmp - rect.x;
// 	}
// 	if (rect.h < 0)
// 	{
// 		tmp = rect.y;
// 		rect.y = rect.y + rect.h;
// 		rect.h = tmp - rect.y;
// 	}
// 	return (SDL_IntersectRectAndLine(&rect, &line.p1.x, &line.p1.y, &line.p2.x, &line.p2.y));
// }

// SDL_bool	is_next_point(t_dot dot, t_dot other, int distance)
// {
// 	t_dot	vector;
// 	int		vnorme;

// 	vector.x = dot.x - other.x;
// 	vector.y = dot.y - other.y;
// 	vnorme = sqrt(vector.x * vector.x + vector.y * vector.y);
// 	return (vnorme <= distance);
// }