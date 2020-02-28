// #include "doom_nukem.h"

// static int	is_intersection(t_dot d1, t_dot d2, int x, int y)
// {
// 	float	a;
// 	float	b;
// 	int		num;
// 	int		denom;
// 	float	x2;

// 	if (!(num = d1.y - d2.y))
// 		return (0);
// 	if (!(denom = d1.x - d2.x))
// 		return ((d1.x == 0 || (0 < d1.x && d1.x < x)) &&\
// 				((d1.y <= y && y <= d2.y) ||\
// 				(d2.y <= y && y <= d1.y)));
// 	a = num / (float)denom;
// 	b = d1.y - a * d1.x;
// 	x2 = (y - b) / a;
// 	// printf("Num denom : %d %d with %d %d\t%d %d\tx2 = %f\ta b %f %f\n", num, denom, d1.x, d1.y, d2.x, d2.y, x2, a, b);
// 	return (!(x2 < 0 || x2 > x));
// }
// // 2 intersec si le corner est sur le segment (0,y) (x,y)
// static int	inside_one_poly(t_poly *poly, int x, int y)
// {
// 	int		i;
// 	int		i2;
// 	int		count;
// 	int		corner;

// 	corner = 0;
// 	count = 0;
// 	i = -1;
// 	while (++i < poly->n_proj)
// 	{
// 		i2 = i ? i - 1 : poly->n_proj - 1;
// 		if ((poly->dots_proj[i].y == y &&\
// 			(0 <= poly->dots_proj[i].x && poly->dots_proj[i].x <= x)) ||\
// 			(poly->dots_proj[i2].y == y &&\
// 			(0 <= poly->dots_proj[i2].x && poly->dots_proj[i2].x <= x)))
// 		{
// 			if (!corner)
// 			{
// 				// if (x < 5 || x > 995)
// 				// 	printf("corner of poly +1 %p\n", poly);
// 				corner = 1;
// 				count++;
// 			}
// 		}
// 		else if (is_intersection(poly->dots_proj[i], poly->dots_proj[i2], x, y))
// 		{
// 			// if (x < 5 || x > 995)
// 			// 	printf("\td1 %d %d\t\td2 %d %d\t\t%d\n", poly->dots_proj[i].x, poly->dots_proj[i].y, poly->dots_proj[i2].x, poly->dots_proj[i2].y, 1);
// 			count++;
// 		}
// 		// else if (x < 5 || x > 995)
// 		// 	printf("\td1 %d %d\t\td2 %d %d\t\t%d\n", poly->dots_proj[i].x, poly->dots_proj[i].y, poly->dots_proj[i2].x, poly->dots_proj[i2].y, 0);
// 	}
// 	// if (x < 5 || x > 995)
// 	// 	printf("%d %d : n edge %d with poly %p nproj %d\n", x, y, count, poly, poly->n_proj);
// 	return (count % 2);
// }

// t_poly		*inside_poly(t_poly *last_poly, t_poly *poly, int x, int y)
// {
// 	if (last_poly && inside_one_poly(last_poly, x, y))
// 		return (last_poly);
// 	// printf("New poly %d %d\n", x, y);
// 	while (poly)
// 	{
// 		if (poly != last_poly &&\
// 			inside_one_poly(poly, x, y))
// 			return (poly);
// 		poly = poly->next;
// 	}
// 	// printf("A linterieur de personne wtfff ?\n");
// 	// exit(0);
// 	return (NULL);
// }