#include "doom_nukem.h"

/*
**	return intersectino segment edge faux ?
**	Premiere iteration dans up
*/

/*
**	Cast (t_dot){0, 0} allocation ? Adresse ? 
**	Return cast possible ?
**	Tab de struct, possible de copier un index : t_dot = t_dot ?
**	Copie de l'adresse ou des valeurs ? 
**	Tab static de struct, les struct sont colle dans la memoire ?
**	Difference architecture entre tab static struct et tab static var
*/

void 			print_poly(t_poly *poly, int arg)
{
	int			i = -1;

	printf("Poly %d\n", poly->index);
	if (arg == 0)
	{
		while (++i < N_DOTS_POLY)
			printf("D%d (%f, %f, %f)\n", i, poly->dots[i].x, poly->dots[i].y, poly->dots[i].z);
	}
	else if (arg == 1)
	{
		while (++i < N_DOTS_POLY)
			printf("D%d (%f, %f, %f)\n", i, poly->dots_rotz_only[i].x, poly->dots_rotz_only[i].y, poly->dots_rotz_only[i].z);
	}
	else if (arg == 2)
	{
		while (++i < poly->n_dot)
			printf("D%d (%f, %f, %f)\n", i, poly->dots_new[i].x, poly->dots_new[i].y, poly->dots_new[i].z);
	}
	else
		while (++i < poly->n_proj)
			printf("D%d (%d, %d)\n", i, poly->dots_proj[i].x, poly->dots_proj[i].y);
	printf("\n");
}

static void		poly_reduction_up(t_win *win, t_poly *poly, t_dot proj[N_DOTS_POLY * 2])
{
	int			tmp_n_proj;
	int			i;
	int			i2;

	if (poly->n_proj > 8)
	{
		printf("n proj > 8 ???? %d\n", poly->n_proj);
		exit(0);
	}
	tmp_n_proj = 0;
	i = -1;
	while (++i < poly->n_proj)
	{
		if (i == N_DOTS_POLY * 2)
		{
			printf("WTF PROJ NULL TAB STATIC UP NTM FILS DE PROJETDOOM DE MERDE up : %d\n", poly->n_proj);
			exit(0); //n proj == 765 ???????????????????????????????????????????????????
		}
		i2 = i ? i - 1 : poly->n_proj - 1;
		if (proj[i].y >= 0)
		{
			if (proj[i2].y <= 0)
			{
				// intersection_segment_edge(win, poly->dots_proj[tmp_n_proj++], proj[i], proj[i2], 0);
				poly->dots_proj[tmp_n_proj++] = intersection_segment_edge(win, proj[i], proj[i2], 0);
				// printf("Create new proj on edge up %d %d\n", poly->dots_proj[tmp_n_proj - 1].x, poly->dots_proj[poly->n_dot - 1].y);
			}
			poly->dots_proj[tmp_n_proj++] = proj[i];
			// printf("Add new dot : %d %d\n", proj[i].x, proj[i].y);
		}
		else if (proj[i2].y >= 0)
		{
			// intersection_segment_edge(win, poly->dots_proj[tmp_n_proj++], proj[i], proj[i2], 0);
			poly->dots_proj[tmp_n_proj++] = intersection_segment_edge(win, proj[i], proj[i2], 0);
			// printf("Create new proj on edge up %d %d\n", poly->dots_proj[tmp_n_proj - 1].x, poly->dots_proj[poly->n_dot - 1].y);
		}
	}
	poly->n_proj = tmp_n_proj;
}

static void		poly_reduction_right(t_win *win, t_poly *poly, t_dot proj[N_DOTS_POLY * 2])
{
	int			tmp_n_proj;
	int			i;
	int			i2;

	if (poly->n_proj > 8)
	{
		printf("n proj > 8 ???? %d\n", poly->n_proj);
		exit(0);
	}
	tmp_n_proj = 0;
	i = -1;
	while (++i < poly->n_proj)
	{
		if (i == N_DOTS_POLY * 2)
		{
			printf("WTF PROJ NULL TAB STATIC RIGHT NTM FILS DE PROJETDOOM DE MERDE right : %d\n", poly->n_proj);
			exit(0);
		}
		i2 = i ? i - 1 : poly->n_proj - 1;
		if (proj[i].x <= win->w)
		{
			if (proj[i2].x >= win->w)
			{
				// intersection_segment_edge(win, poly->dots_proj[tmp_n_proj++], proj[i], proj[i2], 1);
				poly->dots_proj[tmp_n_proj++] = intersection_segment_edge(win, proj[i], proj[i2], 1);
				// printf("Create new proj on edge right %d %d\n", poly->dots_proj[tmp_n_proj - 1].x, poly->dots_proj[poly->n_dot - 1].y);
			}
			poly->dots_proj[tmp_n_proj++] = proj[i];
			// printf("Add new dot : %d %d\n", proj[i].x, proj[i].y);
		}
		else if (proj[i2].x <= win->w)
		{
			// intersection_segment_edge(win, poly->dots_proj[tmp_n_proj++], proj[i], proj[i2], 1);
			poly->dots_proj[tmp_n_proj++] = intersection_segment_edge(win, proj[i], proj[i2], 1);
			// printf("Create new proj on edge right %d %d\n", poly->dots_proj[tmp_n_proj - 1].x, poly->dots_proj[poly->n_dot - 1].y);
		}
	}
	poly->n_proj = tmp_n_proj;
}

static void		poly_reduction_down(t_win *win, t_poly *poly, t_dot proj[N_DOTS_POLY * 2])
{
	int			tmp_n_proj;
	int			i;
	int			i2;

	if (poly->n_proj > 8)
	{
		printf("n proj > 8 ???? %d\n", poly->n_proj);
		exit(0);
	}
	tmp_n_proj = 0;
	i = -1;
	while (++i < poly->n_proj)
	{
		if (i == N_DOTS_POLY * 2)
		{
			printf("WTF PROJ NULL TAB STATIC DOWN NTM FILS DE PROJETDOOM DE MERDE down : %d\n", poly->n_proj);
			exit(0);
		}
		i2 = i ? i - 1 : poly->n_proj - 1;
		if (proj[i].y <= win->h)
		{
			if (proj[i2].y >= win->h)
			{
				//intersection_segment_edge(win, poly->dots_proj[tmp_n_proj++], proj[i], proj[i2], 2);
				poly->dots_proj[tmp_n_proj++] = intersection_segment_edge(win, proj[i], proj[i2], 2);
				// printf("Create new proj on edge down %d %d\n", poly->dots_proj[tmp_n_proj - 1].x, poly->dots_proj[poly->n_dot - 1].y);
			}
			poly->dots_proj[tmp_n_proj++] = proj[i];
			// printf("Add new dot : %d %d\n", proj[i].x, proj[i].y);
		}
		else if (proj[i2].y <= win->h)
		{
			// intersection_segment_edge(win, poly->dots_proj[tmp_n_proj++], proj[i], proj[i2], 2);
			poly->dots_proj[tmp_n_proj++] = intersection_segment_edge(win, proj[i], proj[i2], 2);
			// printf("Create new proj on edge down %d %d\n", poly->dots_proj[tmp_n_proj - 1].x, poly->dots_proj[poly->n_dot - 1].y);
		}
	}
	poly->n_proj = tmp_n_proj;
}

static void		poly_reduction_left(t_win *win, t_poly *poly, t_dot proj[N_DOTS_POLY * 2])
{
	int			tmp_n_proj;
	int			i;
	int			i2;

	if (poly->n_proj > 8)
	{
		printf("n proj > 8 ???? %d\n", poly->n_proj);
		exit(0);
	}
	tmp_n_proj = 0;
	i = -1;
	while (++i < poly->n_proj)
	{
		i2 = i ? i - 1 : poly->n_proj - 1;
		if (i == N_DOTS_POLY * 2)
		{
			printf("WTF PROJ NULL TAB STATIC LEFT NTM FILS DE PROJETDOOM DE MERDE left : %d\n", poly->n_proj);
			exit(0);
		}
		if (proj[i].x >= 0)
		{
			if (proj[i2].x <= 0)
			{
				// intersection_segment_edge(win, poly->dots_proj[tmp_n_proj++], proj[i], proj[i2], 3);
				poly->dots_proj[tmp_n_proj++] = intersection_segment_edge(win, proj[i], proj[i2], 3);
				// printf("Create new proj on edge left %d %d\n", poly->dots_proj[tmp_n_proj - 1].x, poly->dots_proj[poly->n_dot - 1].y);
			}
			poly->dots_proj[tmp_n_proj++] = proj[i];
			// printf("Add new dot : %d %d\n", proj[i].x, proj[i].y);
		}
		else if (proj[i2].x >= 0)
		{
			// intersection_segment_edge(win, poly->dots_proj[tmp_n_proj++], proj[i], proj[i2], 3);
			poly->dots_proj[tmp_n_proj++] = intersection_segment_edge(win, proj[i], proj[i2], 3);
			// printf("Create new proj on edge left %d %d\n", poly->dots_proj[tmp_n_proj - 1].x, poly->dots_proj[poly->n_dot - 1].y);
		}
	}
	poly->n_proj = tmp_n_proj;
}

void			poly_reduction(t_win *win, t_poly *poly)
{
	t_dot	proj[N_DOTS_POLY * 2];
	// int		i;

	// printf("%p -- %p\n", &proj, &(poly->dots_proj));
	// i = -1;
	// while (++i < N_DOTS_POLY * 2)
	// {
	// 	// proj[i] = poly->dots_proj[i];
	// 	printf("%d %d --- %d %d\n", proj[i].x, proj[i].y, poly->dots_proj[i].x, poly->dots_proj[i].y);
	// 	// printf("%p -- %p\n", &(proj[i]), &(poly->dots_proj[i]));
	// }
	ft_memcpy(proj, poly->dots_proj, sizeof(t_dot) * N_DOTS_POLY * 2);
	poly_reduction_up(win, poly, proj);
	// print_poly(poly, 2);

	ft_memcpy(proj, poly->dots_proj, sizeof(t_dot) * N_DOTS_POLY * 2);
	poly_reduction_right(win, poly, proj);
	// print_poly(poly, 2);

	ft_memcpy(proj, poly->dots_proj, sizeof(t_dot) * N_DOTS_POLY * 2);
	poly_reduction_down(win, poly, proj);
	// print_poly(poly, 2);

	ft_memcpy(proj, poly->dots_proj, sizeof(t_dot) * N_DOTS_POLY * 2);
	poly_reduction_left(win, poly, proj);
	// print_poly(poly, 2);
}
