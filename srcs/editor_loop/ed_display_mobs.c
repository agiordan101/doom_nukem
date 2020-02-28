#include "doom_nukem.h"
#include "ui_draw.h"

void	ed_display_mobs(t_win *win, const t_map *map)
{
	SDL_Color	color;
	t_mob		*m;
	t_dot		pos;

	m = map->mob;
	while (m)
	{
		color = ed_get_mob_display_color(map, m);
		ui_set_draw_color(win->winui->rend, (SDL_Color*)&color);
		pos = ed_get_display_point(map, (t_dot){m->pos.x, m->pos.y});
		draw_circle(win, (t_circle){pos.x, pos.y, m->width * map->editor.unit / 2});
		m = m->next;
	}
}