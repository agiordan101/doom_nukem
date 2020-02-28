#include "doom_nukem.h"

SDL_bool		ed_is_wall(t_poly *poly)
{
	int pairs;

	pairs = 0;
	if (poly->dots[0].x == poly->dots[3].x && poly->dots[0].y == poly->dots[3].y)
		pairs++;
	if (poly->dots[1].x == poly->dots[2].x && poly->dots[1].y == poly->dots[2].y)
		pairs++;
	return (pairs == 2);
}

SDL_bool		ed_is_inclined(t_poly *poly)
{
	return (poly->dots[0].z == poly->dots[3].z &&
			poly->dots[1].z == poly->dots[2].z &&
			poly->dots[0].z != poly->dots[1].z);
}

SDL_bool		ed_is_flat(t_poly *poly)
{
	return (poly->dots[0].z == poly->dots[1].z &&
			poly->dots[1].z == poly->dots[2].z &&
			poly->dots[2].z == poly->dots[3].z);
}
