#include "doom_nukem.h"

static void		update_selected_ui(t_win *win)
{
	t_frame		*f;
	t_button	*button_tmp;

	win->selected_frame = NULL;
	win->selected_button = NULL;
	f = win->frames;
	while (f)
	{
		if (!(f->flags & FRAME_HIDE))
		{
			if (is_in_rect(f->rect, (t_dot){win->mouse->x, win->mouse->y}))
			{
				win->selected_frame = f;
				button_tmp = f->buttons;
				while (button_tmp)
				{
					if (is_in_rect(button_tmp->rect, (t_dot){win->mouse->x, win->mouse->y}))
					{
						win->selected_button = button_tmp;
						button_tmp = NULL;
						f = NULL;
					}
					if (button_tmp)
						button_tmp = button_tmp->next;
				}
			}
		}
		if (f)
			f = f->next;
	}
}

static void		update_ui_rect(t_win *win)
{
	t_frame		*frame_tmp;
	t_button	*button_tmp;

	frame_tmp = win->frames;
	while (frame_tmp)
	{
		frame_tmp->rect = (SDL_Rect){win->w * frame_tmp->ratio.x,
										win->h * frame_tmp->ratio.y,
										win->w * frame_tmp->ratio.w,
										win->h * frame_tmp->ratio.h};
		button_tmp = frame_tmp->buttons;
		while (button_tmp)
		{
			button_tmp->rect = (SDL_Rect){button_tmp->ratio.x * frame_tmp->rect.w + frame_tmp->rect.x,
								button_tmp->ratio.y * frame_tmp->rect.h + frame_tmp->rect.y,
								button_tmp->ratio.w * frame_tmp->rect.w,
								button_tmp->ratio.h * frame_tmp->rect.h};
			button_tmp = button_tmp->next;
		}
		frame_tmp = frame_tmp->next;
	}
}

int				editor_event(t_win *win, t_map_editor *map, SDL_bool *loop)
{
	SDL_Event	event;
	t_linedef	*tmp;
	t_dot		dot;

	tmp = NULL;
	SDL_PumpEvents();
	mouse_refresh();
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		*loop = SDL_FALSE;
	else if (event.type == SDL_MOUSEMOTION)
	{
		update_selected_ui(win);
	}
	else if(event.type == SDL_MOUSEWHEEL)
	{
		if (event.wheel.y > 0)
			map_zoom(map, 0.05);
		else if (event.wheel.y < 0)
			map_zoom(map, -0.05);
	}
	else if(event.type == SDL_WINDOWEVENT)
	{
		if(event.window.event == SDL_WINDOWEVENT_RESIZED)
		{
			SDL_GetWindowSize(win->ptr, &win->w, &win->h);
			update_ui_rect(win);
		}
	}
	if (win->mouse->button[MOUSE_LEFT].pressing)
	{
		if (!win->selected_frame)
		{
			dot = (t_dot){(win->mouse->x - map->x) / map->unit, (win->mouse->y - map->y) / map->unit};
			if (!key_pressed(SC_DRAW_FREE))
				is_next_to_linedef(map, &dot, map->unit * NEXT_FACTOR);
			if (!(tmp = new_linedef((t_line){dot, dot}, NULL, LINEDEF_NONE)))
				return (0);
			if (map->selected_sector)
				add_linedef(&map->selected_sector->lines, tmp);
			else
				add_linedef(&map->lines, tmp);
			map->flags = map->flags | DRAWING_LINE;
		}
	}
	else if (win->mouse->button[MOUSE_LEFT].releasing)
	{
		if (win->selected_frame)
			resolve_ui_left_release(win, map);
		else
		{
			if (map->flags & DRAWING_LINE)
			{
				dot = (t_dot){(win->mouse->x - map->x) / map->unit, (win->mouse->y - map->y) / map->unit};
				if (map->selected_sector)
				{
					if (!key_pressed(SC_DRAW_FREE))
						is_next_to_linedef(map, &dot, map->unit * NEXT_FACTOR);
					map->selected_sector->lines->p2 = dot;
				}
				else
				{
					if (!key_pressed(SC_DRAW_FREE))
						is_next_to_linedef(map, &dot, map->unit * NEXT_FACTOR);
					map->lines->p2 = dot;
				}
				map->flags -= DRAWING_LINE;
			}
		}
	}

	if (win->mouse->button[MOUSE_RIGHT].pressing)
	{
		if (!win->selected_frame)
		{
			map->rect_util = (SDL_Rect){win->mouse->x, win->mouse->y, 0, 0};
			map->flags = map->flags | MAP_SELECTING;
		}
	}
	else if (win->mouse->button[MOUSE_RIGHT].releasing)
	{
		if (map->flags & MAP_SELECTING)
		{
			selected_all_linedef(map, LINEDEF_SELECTED);
			map->rect_util = (SDL_Rect){};
			map->flags -= MAP_SELECTING;
		}
	}	
	if (win->mouse->button[MOUSE_MIDDLE].pressing)
		mouse_drag(win->mouse->x, win->mouse->y, SDL_FALSE);

	if (win->mouse->button[MOUSE_LEFT].pressed)
	{
		if (map->flags & DRAWING_LINE)
		{
			if (map->selected_sector)
			{
				map->selected_sector->lines->p2 = (t_dot){(win->mouse->x - map->x) / map->unit, (win->mouse->y - map->y) / map->unit};
				if (!key_pressed(SC_DRAW_FREE))
					is_next_to_linedef(map, &map->selected_sector->lines->p2, map->unit * NEXT_FACTOR);
			}
			else
			{
				map->lines->p2 = (t_dot){(win->mouse->x - map->x) / map->unit, (win->mouse->y - map->y) / map->unit};
				if (!key_pressed(SC_DRAW_FREE))
					is_next_to_linedef(map, &map->lines->p2, map->unit * NEXT_FACTOR);
			}
		}
	}
	if (win->mouse->button[MOUSE_RIGHT].pressed)
	{
		if (map->flags & MAP_SELECTING)
		{
			map->rect_util.w = win->mouse->x - map->rect_util.x;
			map->rect_util.h = win->mouse->y - map->rect_util.y;
			selected_all_linedef(map, LINEDEF_SELECTED);
		}
	}
	if (win->mouse->button[MOUSE_MIDDLE].pressed)
	{
		dot = mouse_drag(win->mouse->x, win->mouse->y, SDL_TRUE);
		map->x += dot.x;
		map->y += dot.y;
		mouse_drag(win->mouse->x, win->mouse->y, SDL_FALSE);
	}

	if (key_pressed(SDL_SCANCODE_DELETE))
		delete_all_linedef(map, LINEDEF_SELECTED);
	if (key_pressed(SDL_SCANCODE_W))
		map->y += 2;
	if (key_pressed(SDL_SCANCODE_S))
		map->y -= 2;
	if (key_pressed(SDL_SCANCODE_A))
		map->x += 2;
	if (key_pressed(SDL_SCANCODE_D))
		map->x -= 2;
	return (1);
}