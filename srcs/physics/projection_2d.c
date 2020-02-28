#include "doom_nukem.h"
#include <time.h>

/*
**	Pour chaque poly :
**		On creer un nouveau tab de dot 3d pour ramener tout les dot.y en positif
**		On les projette en 2d
**		On creer la box
**		On la ramene sur les bords de l'ecran si necessaire
*/
/*
**	Tester pour les 4 cote chaque segments, si un segment est dessus
**	alors new point et suppr lancien (Comme pour ramener les y<0 devant soi)
**	On fais ca 4 fois au lieu de 1
*/

void				draw_projection(t_win *win)
{
	t_poly			*poly;
	int				i;
	int				k = -1;

	poly = win->map->polys;
	SDL_SetRenderDrawColor(win->rend, 0x50, 0xEE, 0x50, 0xFF);
	while (poly)
	{
		i = -1;
		if ((poly->object && poly->object->visible) ||\
			(!poly->object && poly->visible))
			while (++i < poly->n_proj)
				draw_line(win, poly->dots_proj[i],\
							poly->dots_proj[i ? i - 1 : poly->n_proj - 1]);
		k++;
		poly = poly->next;
	}
	printf("n poly : %d\n", k);
}

void				draw_all_square(t_win *win)
{
	t_poly			*poly;

	poly = win->map->polys;
	SDL_SetRenderDrawColor(win->rend, 0x50, 0x50, 0xEE, 0xFF);
	while (poly)
	{
		if ((poly->object && poly->object->visible) ||\
			(!poly->object && poly->visible))
		{
			draw_line(win, (t_dot){poly->box_x.x, poly->box_y.x},\
							(t_dot){poly->box_x.y, poly->box_y.x});
			draw_line(win, (t_dot){poly->box_x.x, poly->box_y.x},\
							(t_dot){poly->box_x.x, poly->box_y.y});
			draw_line(win, (t_dot){poly->box_x.y, poly->box_y.x},\
							(t_dot){poly->box_x.y, poly->box_y.y});
			draw_line(win, (t_dot){poly->box_x.x, poly->box_y.y},\
							(t_dot){poly->box_x.y, poly->box_y.y});
		}
		poly = poly->next;
	}
}

static void			set_box(t_poly *poly, t_dot *box_x, t_dot *box_y,\
							t_dot proj[N_DOTS_POLY * 2])
{
	int				i;

	i = -1;
	while (++i < poly->n_proj)
	{
		if (proj[i].x < box_x->x)
			box_x->x = proj[i].x;
		if (proj[i].x > box_x->y)
			box_x->y = proj[i].x;
		if (proj[i].y < box_y->x)
			box_y->x = proj[i].y;
		if (proj[i].y > box_y->y)
			box_y->y = proj[i].y;
	}
}

static void			set_proj(t_win *win, t_poly *poly)
{
	int				i;

	i = -1;
	while (++i < poly->n_dot)
	{
		poly->dots_proj[i].x = (win->map->player.fov_2 + poly->dots_new[i].y /\
								poly->dots_new[i].x) * win->w_div_fov;
		poly->dots_proj[i].y = (win->map->player.fov_up_2 - poly->dots_new[i].z\
								/ poly->dots_new[i].x) * win->h_div_fov;
	}
	poly->n_proj = poly->n_dot;
}

static t_fdot_3d	intersection_axe_y(t_fdot_3d d1, t_fdot_3d d2)
{
	float			t;

	t = (1 - d1.x) / (d2.x - d1.x);
	return ((t_fdot_3d){1,\
						(d2.y - d1.y) * t + d1.y,\
						(d2.z - d1.z) * t + d1.z});
}

static void			create_dot_on_axe_y(t_poly *poly)
{
	int			i;
	int			i2;

	poly->n_dot = 0;
	i = -1;
	while (++i < N_DOTS_POLY)
	{
		i2 = i ? i - 1 : N_DOTS_POLY - 1;
		if (poly->dots[i].x > 0)
		{
			if (poly->dots[i2].x < 0)
				poly->dots_new[poly->n_dot++] =\
							intersection_axe_y(poly->dots[i], poly->dots[i2]);
			poly->dots_new[poly->n_dot++] = poly->dots[i];
		}
		else if (poly->dots[i2].x > 0)
			poly->dots_new[poly->n_dot++] =\
							intersection_axe_y(poly->dots[i], poly->dots[i2]);
	}
}

static void			resize_box(t_win *win, t_poly *poly)
{
	if (poly->box_x.x < 0)
		poly->box_x.x = 0;
	if (poly->box_x.y > win->w)
		poly->box_x.y = win->w;
	if (poly->box_y.x < 0)
		poly->box_y.x = 0;
	if (poly->box_y.y > win->h)
		poly->box_y.y = win->h;
}

void				surround_walls(t_win *win, t_map *map)
{
	t_poly			*poly;

	poly = map->polys;
	while (poly)
	{
		poly->box_x = (t_dot){win->w, 0};
		poly->box_y = (t_dot){win->h, 0};
		poly->is_slide_ban = 0;
		if ((poly->object && poly->object->visible) ||\
			(!poly->object && poly->visible))
		{
			create_dot_on_axe_y(poly);
			set_proj(win, poly);
			// poly_reduction(win, poly);
			set_box(poly, &(poly->box_x), &(poly->box_y), poly->dots_proj);
			resize_box(win, poly);
		}
		poly = poly->next;
	}
}
