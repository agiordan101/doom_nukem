#include "doom_nukem.h"

void    add_poly(t_poly **poly)
{
  	t_poly  *new_poly;

  	if (!(new_poly = (t_poly *)ft_memalloc(sizeof(t_poly))))
		return (ft_putendl("poly allocation failed in poly.c"));
  	new_poly->next = *poly;
	new_poly->light_coef = 1;
	//Mettre toute les variables de la structure poly a une valeur par default
  	*poly = new_poly;
}

void    add_existing_poly(t_poly **polys, t_poly *poly)
{
	if (poly)
	{
		poly->next = *polys;
		*polys = poly;
	}
}


void	delete_poly(t_poly **polys, t_poly *poly)
{
	t_poly	*p;
	t_poly	*tmp_prev;
	t_poly	*tmp_next;

	if (polys && poly)
	{
		tmp_prev = NULL;
		p = *polys;
		while (p)
		{
			if (p == poly)
			{
				tmp_next = p->next;
				free(p);
				if (tmp_prev)
					tmp_prev->next = tmp_next;
				else
					*polys = tmp_next;
				p = tmp_next;
			}
			else
			{
				tmp_prev = p;
				p = p->next;
			}
		}
	}
}

void	print_polys(t_poly **polys)
{
	t_poly	*p;

	if (polys)
	{
		p = *polys;
		while (p)
		{
			printf("poly = %p\n", p);
			p = p->next;
		}
	}
}