#include "doom_nukem.h"

t_dot	ed_is_next_to_poly(const t_map *map, t_dot point, int radius)
{
	int		len;
	int		new_len;
	t_poly	*p;
	int		i;
	t_dot	result;

	len = -1;
	result = point;
	p = map->polys;
	while (p)
	{
		i = 0;
		while (i < 4)
		{
			new_len = ed_get_line_len(&(t_line){point, (t_dot){p->dots[i].x, p->dots[i].y}});
			if ((len == -1 && new_len <= radius) ||
				(new_len <= len && new_len <= radius))
			{
				result = (t_dot){p->dots[i].x, p->dots[i].y};
				len = new_len;
			}
			i++;
		}
		p = p->next;
	}
	return (result);
}
