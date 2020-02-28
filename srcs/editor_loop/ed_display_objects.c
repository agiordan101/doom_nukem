#include "doom_nukem.h"
#include "ui_draw.h"

void	ed_display_object(t_win *win, const t_map *map, t_object *obj)
{
	t_dot		pos;

	pos = ed_get_display_point(map, (t_dot){obj->pos.x, obj->pos.y});
	draw_circle(win, (t_circle){pos.x, pos.y, obj->width * map->editor.unit / 2});
}

void	ed_display_objects(t_win *win, const t_map *map)
{
	t_object	*obj;
	SDL_Color	color;
	obj = map->objects;
	while (obj)
	{
		color = ed_get_obj_display_color(map, obj);
		ui_set_draw_color(win->winui->rend, (SDL_Color*)&color);
		ed_display_object(win, map, obj);
		obj = obj->next;
	}
}