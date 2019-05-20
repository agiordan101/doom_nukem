#include "doom_nukem.h"

int 			create_window(t_win *win, const char *title, SDL_Rect rect, Uint32 flags)
{
	if (!(win->ptr = SDL_CreateWindow(title, rect.x, rect.y, rect.w, rect.h, flags)))
		return (ret_error(SDL_GetError()));
	win->w = rect.w;
	win->h = rect.h;
	win->mouse = mouse_refresh();
	win->frames = NULL;
	if (!(win->rend = SDL_CreateRenderer(win->ptr, 0, SDL_RENDERER_SOFTWARE)))
		return (ret_error(SDL_GetError()));
	SDL_SetRenderDrawBlendMode(win->rend, SDL_BLENDMODE_BLEND);
	return (1);
}

void		add_frame_to_window(t_win *win, t_frame *new_frame)
{
	new_frame->rect.x = win->w * new_frame->ratio.x;
	new_frame->rect.y = win->h * new_frame->ratio.y;
	new_frame->rect.w = win->w * new_frame->ratio.w;
	new_frame->rect.h = win->h * new_frame->ratio.h;
	new_frame->next = win->frames;
	win->frames = new_frame;
}

SDL_bool		is_in_screen(t_win *win, t_dot p)
{
	return ((p.x >= 0 && p.x < win->w && p.y >= 0 && p.y < win->h));
}

