#include "doom_nukem.h"

void		delete_linedef(t_linedef **lines, Uint32 delete_flags)
{
	t_linedef	*new_lines;
	t_linedef	*tmp;

	new_lines = NULL;
	while (*lines)
	{
		if ((*lines)->flags & delete_flags)
		{
			tmp = (*lines);
			(*lines) = (*lines)->next;
			free(tmp);
		}
		else
		{
			tmp = (*lines)->next;
			add_linedef(&new_lines, *lines);
			*lines = tmp;
		}
	}
	*lines = new_lines;
}

void		delete_sector_linedef(t_sector *sectors, Uint32 delete_flags)
{
	t_sector	*s;

	s = sectors;
	while (s)
	{
		delete_linedef(&s->lines, delete_flags);
		s = s->next;
	}
}