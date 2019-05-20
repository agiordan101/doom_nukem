#include "doom_nukem.h"

#include "doom_nukem.h"

/*
**	s = perimetre / 2 = somme des trois cotes / 2
**	On melange 2 formules sur l'aire du triangle : base * h / 2 = sqrt(s(s-a)(s-b)(s-c))
**	Et boom on a h par rapport aux 3 cotes.
*/

/*
static t_dot	direction(t_linedef *line, t_player *player, t_dot *newpos)
{
	t_dot		dir;

	if (line->equation.a > 0)
	{
		if ()
	}
	else
	{
		if ()
	}
	return (dir);
}*/
/*
static void	no_equation(t_linedef *line, t_player *player, t_dot *newpos)
{
	t_dot		collision;

	//printf("No equation\n");
	if (player->pos.y < )
	{
		if (player->pos.y < collision.y && collision.y < player->pos.y + player->vel.y)
			gliss(line, player, newpos);
	}
	else if (player->pos.y > collision.y && collision.y > player->pos.y + player->vel.y)
		gliss(line, player, newpos);
}*/

static void	gliss(t_linedef *line, t_player *player, t_dot *newpos)
{
	double	a;
	double	b;
	double	c;
	double	h;
	double	tmp;

	if (!line->portal)
	{
		//printf("\nCollisions !!! alpha = %f\n\n", (atan(line->equation.a) * 360) / (2 * M_PI));
		printf("Collisions !!!\n");
		a = dist(line->p2, *newpos);
		b = dist(*newpos, line->p1);
		c = dist(line->p1, line->p2);
		printf("Cotes : %f\t%f\t%f\t%f\n", a, b, c, a + b);
		if (a + b > c)
		{
			h = (a + b + c) / 2;
			h = (2 * sqrt(h * (h - a) * (h - b) * (h - c))) / c;
			printf("Hauteur : %lf\n", h);
			tmp = newpos->x + (line->equation.a * newpos->x + line->equation.b\
						> newpos->y ? 1 : -1) *\
						sin(line->angle) * (h + player->hitbox);
			printf("Correction x : %lf\n", sin(line->angle) * (h + player->hitbox));
			newpos->y += (line->equation.a * newpos->x + line->equation.b\
						> newpos->y ? 1 : -1) *\
						cos(line->angle) * (h + player->hitbox);
			printf("Correction x : %lf\n", cos(line->angle) * (h + player->hitbox));
			newpos->x = tmp;
			printf("New position : %d\t%d\n\n", newpos->x, newpos->y);
		}
	}
	else
		;
}

static void	coef_null(t_linedef *line, t_player *player, t_dot *newpos)
{
	t_dot		collision;

	//printf("Coef nulll sa mere\n");
	collision.x = player->pos.x;
	collision.y = line->equation.a * player->pos.x + line->equation.b;
	//printf("Coef dir. : %f\n", line->equation.a);
	printf("Collision : %d\t%d\n", collision.x, collision.y);
	printf("fdist collision : %f\n\n", dist(player->pos, collision));
	if (dist(player->pos, collision) == mag(player->vel))
	{
		player->vel = (t_vector){player->vel.x * 0.9, player->vel.y * 0.9};
		*newpos = (t_dot){newpos->x - player->vel.x * 0.25,\
							newpos->y - player->vel.y * 0.25};
		printf("Vel modif : x = %d\ty = %d\n", player->vel.x, player->vel.y);
	}
	if ((line->p1.x < collision.x && collision.x < line->p2.x) ||\
		(line->p2.x < collision.x && collision.x < line->p1.x))
	{
		if (player->vel.y > 0)
		{
			if (player->pos.y + player->hitbox < collision.y &&\
				collision.y <= player->pos.y + player->vel.y + player->hitbox)
				gliss(line, player, newpos);
		}
		else if (player->pos.y - player->hitbox > collision.y &&\
		collision.y >= player->pos.y + player->vel.y - player->hitbox)
			gliss(line, player, newpos);
	}
}

static void	collisions(t_linedef *line, t_affine traj,\
						t_player *player, t_dot *newpos)
{
	t_dot		collision;

	//printf("Move\n");
	//printf("%f\t%f\n", line->equation.a, line->equation.b);
	if (traj.a != line->equation.a)
	{
		collision.x = (line->equation.b - traj.b) / (traj.a - line->equation.a);
		collision.y = traj.a * collision.x + traj.b;
		//printf("\nPosition : %f\t%f\n", player->pos.x, player->pos.y);
		printf("Collision : %d\t%d\n", collision.x, collision.y);
		printf("fdist collision : %f\n", dist(player->pos, collision));
		/*printf("fdist vel 2 : %f\n", fdist(player->pos, *newpos));
		//printf("Sign 1 : %d\n", sign(player->pos.x - newpos->x));
		//printf("Sign 2 : %d\n", sign(player->pos.x - collision.x));*/

		/*if (dist(player->pos, collision) < mag(player->vel) &&\
		sign(player->pos.x - newpos->x) == sign(player->pos.x - collision.x))
		{
			if (!line->portal)
				gliss(line, player, newpos);
			else
				;
		}*/
		if (dist(player->pos, collision) == mag(player->vel))
		{
			player->vel = (t_vector){player->vel.x * 0.9, player->vel.y * 0.9};
			*newpos = (t_dot){newpos->x - player->vel.x * 0.25,\
								newpos->y - player->vel.y * 0.25};
			printf("Vel modif : x = %d\ty = %d\n", player->vel.x, player->vel.y);
		}
		if ((line->p1.x < collision.x && collision.x < line->p2.x) ||\
			(line->p2.x < collision.x && collision.x < line->p1.x))
		{
			if (player->vel.x > 0)
			{
				if (player->pos.x < collision.x && collision.x <= newpos->x)
					gliss(line, player, newpos);
			}
			else if (player->pos.x > collision.x && collision.x >= newpos->x)
				gliss(line, player, newpos);
		}
	}
}

int		move(t_map *map, t_player *player)
{
	int			i;
	t_sector	*sector;
	t_linedef	*line;
	t_dot		newpos;
	t_affine	traj;

	if (!player->vel.x && !player->vel.y)
		return (0);
	printf("Vel : x = %d\ty = %d\n", player->vel.x, player->vel.y);
	newpos = (t_dot){player->pos.x + player->vel.x,\
						player->pos.y + player->vel.y};
	printf("Pos :\tx = %d\ty = %d\n", player->pos.x, player->pos.y);
	printf("Newpos :\tx = %d\ty = %d\n", newpos.x, newpos.y);
	i = -1;
	sector = map->sectors;
	while (++i < player->sector)
		sector = sector->next;
	line = sector->lines;
	if (player->vel.x)
	{
		traj.a = player->vel.y / player->vel.x;
		traj.b = player->pos.y - traj.a * player->pos.x;
		while (line)
		{
			collisions(line, traj, player, &newpos);
			line = line->next;
		}
	}
	else
		while (line)
		{
			coef_null(line, player, &newpos);
			line = line->next;
		}
	player->pos = newpos;
	printf("\n");
	return (0);
}









































SDL_bool	is_in_rect(SDL_Rect rect, t_dot p)
{
	int		tmp;
	
	if (rect.w < 0)
	{
		tmp = rect.x;
		rect.x = rect.x + rect.w;
		rect.w = tmp - rect.x;
	}
	if (rect.h < 0)
	{
		tmp = rect.y;
		rect.y = rect.y + rect.h;
		rect.h = tmp - rect.y;
	}
	return (p.x > rect.x &&
			p.x < rect.x + rect.w &&
			p.y > rect.y &&
			p.y < rect.y + rect.h);
}

SDL_bool intersect_line_rect(t_line line, SDL_Rect rect)
{
	int		tmp;
	if (rect.w < 0)
	{
		tmp = rect.x;
		rect.x = rect.x + rect.w;
		rect.w = tmp - rect.x;
	}
	if (rect.h < 0)
	{
		tmp = rect.y;
		rect.y = rect.y + rect.h;
		rect.h = tmp - rect.y;
	}
	return (SDL_IntersectRectAndLine(&rect, &line.p1.x, &line.p1.y, &line.p2.x, &line.p2.y));
}

SDL_bool is_next_point(t_dot dot, t_dot other, int distance)
{
	t_dot	vector;
	int		vnorme;

	vector.x = dot.x - other.x;
	vector.y = dot.y - other.y;
	vnorme = sqrt(vector.x * vector.x + vector.y * vector.y);
	return (vnorme <= distance);
}