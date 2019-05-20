#include "doom_nukem.h"

static void			editor_display(t_win *win, const t_map_editor *map)
{
	t_dot		p1;
	t_dot		p2;
	t_sector	*s;
	t_linedef	*l;
	t_frame		*f;
	t_button	*b;

	SDL_SetRenderDrawColor(win->rend, 100, 100, 100, 255);
	draw_rect(win, (SDL_Rect){map->x, map->y, map->w * map->unit, map->h * map->unit});
	SDL_SetRenderDrawColor(win->rend, 150, 150, 150, 200);
	if (map->flags & MAP_SELECTING)
		draw_rect(win, map->rect_util);
	l = map->lines;
	while (l)
	{
		if (l->flags & LINEDEF_SELECTED)
			SDL_SetRenderDrawColor(win->rend, 0, 175, 175, 255);
		else if (l->flags & LINEDEF_MOUSE_POINTED)
			SDL_SetRenderDrawColor(win->rend, 50, 150, 150, 255);
		else
			SDL_SetRenderDrawColor(win->rend, 200, 200, 200, 255);
		p1 = (t_dot){l->p1.x * map->unit + map->x, l->p1.y * map->unit + map->y};
		p2 = (t_dot){l->p2.x * map->unit + map->x, l->p2.y * map->unit + map->y};
		if (is_in_screen(win, p1) || is_in_screen(win, p2))
			draw_line(win, p1, p2);
		l = l->next;
	}
	s = map->sectors;
	while (s)
	{
		l = s->lines;
		while (l)
		{
			if (l->flags & LINEDEF_SELECTED)
				SDL_SetRenderDrawColor(win->rend, 0, 175, 175, 255);
			else if (l->flags & LINEDEF_MOUSE_POINTED)
				SDL_SetRenderDrawColor(win->rend, 50, 150, 150, 255);
			else
				SDL_SetRenderDrawColor(win->rend, s->color.selected_color.r,
													s->color.selected_color.g,
													s->color.selected_color.b,
													s->color.selected_color.a);
			p1 = (t_dot){l->p1.x * map->unit + map->x, l->p1.y * map->unit + map->y};
			p2 = (t_dot){l->p2.x * map->unit + map->x, l->p2.y * map->unit + map->y};
			if (is_in_screen(win, p1) || is_in_screen(win, p2))
				draw_line(win, p1, p2);
			l = l->next;
		}
		s = s->next;
	}
	SDL_SetRenderDrawColor(win->rend, 200, 200, 200, 255);
	f = win->frames;
	while (f)
	{
		if (!(f->flags & FRAME_HIDE))
		{
			if (f->texture)
				printf("texture\n");
			else
				draw_ratio_rect(win, &(SDL_Rect){0, 0, win->w, win->h}, &f->ratio);
			b = f->buttons;
			while (b)
			{
				if (b->texture)
					SDL_RenderCopy(win->rend, b->texture, NULL, &b->rect);
				else
					draw_ratio_rect(win, &f->rect, &b->ratio);
				if (b->flags & BUTTON_COLOR_PICKER)
				{
					draw_color_picker(win, map->selected_sector->color.pos, b->rect);
					SDL_SetRenderDrawColor(win->rend, 200, 200, 200, 255);
				}
				b = b->next;
			}
		}
		f = f->next;
	}
	draw_fps();
}

static int		text_init(t_win *win)
{
	SDL_Surface		*surface;
	SDL_Texture		*tmp;
	char			*str;
	int				i;

	if (!(win->font = TTF_OpenFont("font.ttf", 20)))
		return (0);
	if (!(win->sectors_texture = (SDL_Texture**)ft_memalloc(sizeof(SDL_Texture*) * (MAX_SECTORS + 1))))
		return (0);
	if (!(win->sectors_texture_selected = (SDL_Texture**)ft_memalloc(sizeof(SDL_Texture*) * (MAX_SECTORS + 1))))
		return (0);
	i = 0;
	while (i <= MAX_SECTORS)
	{
		if (i < MAX_SECTORS)
			str = ft_itoa(i);
		else
		{
			str[0] = '+';
			str[1] = '\0';
		}
		if (!(surface = TTF_RenderText_Solid(win->font, str, (SDL_Color){200, 200, 200, 255})))
			return (0);
		if (!(tmp = SDL_CreateTextureFromSurface(win->rend, surface)))
			return (0);
		SDL_SetTextureBlendMode(tmp, SDL_BLENDMODE_BLEND);
		if (!(win->sectors_texture[i] = SDL_CreateTexture(win->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 30, 30)))
			return (0);
		if (!(win->sectors_texture_selected[i] = SDL_CreateTexture(win->rend, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 30, 30)))
			return (0);
		SDL_SetTextureBlendMode(win->sectors_texture[i], SDL_BLENDMODE_BLEND);
		SDL_SetTextureBlendMode(win->sectors_texture_selected[i], SDL_BLENDMODE_BLEND);

		SDL_SetRenderTarget(win->rend, win->sectors_texture[i]);
		SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 0);
		SDL_RenderClear(win->rend);
		SDL_RenderCopy(win->rend, tmp, NULL, &(SDL_Rect){10, 10, 12, 12});

		SDL_SetRenderTarget(win->rend, win->sectors_texture_selected[i]);
		SDL_SetRenderDrawColor(win->rend, 70, 70, 70, 100);
		SDL_RenderClear(win->rend);
		SDL_RenderCopy(win->rend, tmp, NULL, &(SDL_Rect){10, 10, 12, 12});

		SDL_SetRenderTarget(win->rend, NULL);
		SDL_DestroyTexture(tmp);
		SDL_FreeSurface(surface);
		i++;
	}
	return (1);
}

static int		ui_init(t_win *win)
{
	//	sector frame
	add_frame_to_window(win, new_frame((t_frect){0.05, 0.02, 0.9, 0.05}, NULL, FRAME_SECTORS, NULL));
	add_button_to_frame(&win->frames, new_button((t_frect){0, 0, 1.0 / MAX_SECTORS, 1}, win->sectors_texture[MAX_SECTORS], BUTTON_NONE));
	//	info sector frame
	add_frame_to_window(win, new_frame((t_frect){0.02, 0.1, 0.15, 0.4}, NULL, FRAME_INFO | FRAME_HIDE, NULL));
	//		color_picker
	add_button_to_frame(&win->frames, new_button((t_frect){0.1, 0.85, 0.8, 0.1}, NULL, BUTTON_COLOR_PICKER));
	return (1);
}

static int		editor_init(t_win *win, t_map_editor *map)
{
	map->x = 0;
	map->y = 0;
	map->w = 2000;
	map->h = 1200;
	map->unit = 1.0;
	map->sectors = NULL;
	map->selected_sector = NULL;
	map->lines = NULL;
	map->rect_util = (SDL_Rect){};
	map->flags = 0;
	if (!text_init(win))
		return (0);
	ui_init(win);
	return (1);
}

int				editor_loop(t_win *win)
{
	SDL_bool			loop;
	t_map_editor		map;
	SDL_Event			event;

	// if (!(parser_png("png_test_800_600.png")))
	// 	return (0);
	editor_init(win, &map);
	loop = SDL_TRUE;
	while (loop)
	{
		SDL_PumpEvents();
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
			loop = SDL_FALSE;

		clear_rend(win->rend, 30, 30, 30);
		editor_display(win, &map);
		editor_event(win, &map, &loop);
		SDL_RenderPresent(win->rend);
	}
	return (1);
}