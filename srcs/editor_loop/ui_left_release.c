#include "doom_nukem.h"

SDL_Color	get_selected_color(float picker_position)
{
	SDL_Color	color;
	int			pos;

	pos = picker_position / 0.33;

	// printf("pos = %d\n", pos);
	color = (SDL_Color){0, 0, 0, 255};
	if (pos == 0)
	{
		color.r = 255 - 255 * picker_position;	
		color.g = 255 * picker_position;
		color.b = 0;
	}
	else if (pos == 1)
	{
		color.r = 0;	
		color.g = 255 - 255 * picker_position;
		color.b = 255 * picker_position;
	}
	else if (pos == 2)
	{
		color.r = 255 - 255 * picker_position;	
		color.g = 255 * picker_position;
		color.b = 0;
	}
	else if (pos == 3)
	{
		color.r = 255 * picker_position;	
		color.g = 0;
		color.b = 255 - 255 * picker_position;
	}
	return (color);
}

void		resolve_ui_left_release(t_win *win, t_map_editor *map)
{
	t_frame		*f;
	t_button	*b;
	t_sector	*s;
	int			i;
	int			i_sector;
	int			nb_sectors;

	nb_sectors = get_nb_sectors(map->sectors);
	f = win->selected_frame;
	if (f->flags & FRAME_SECTORS)
	{
		printf("al\n");
		if (win->mouse->x < f->rect.x + (f->rect.w / MAX_SECTORS) * (f->nb_buttons - 1))
		{
			i_sector = (win->mouse->x - f->rect.x) / (f->rect.w / MAX_SECTORS);
			s = map->sectors;
			i = 0;
			while (i < nb_sectors - i_sector - 1)
			{
				s = s->next;
				i++;
			}
			if (map->selected_sector == s)
			{
				add_frame_flags(&win->frames, FRAME_INFO, FRAME_HIDE);
				map->selected_sector = NULL;
			}
			else
			{
				remove_frame_flags(&win->frames, FRAME_INFO, FRAME_HIDE);
				map->selected_sector = s;
			}
			i = 0;
			b = f->buttons;
			b->texture = win->sectors_texture[MAX_SECTORS];
			b = b->next;
			while (b)
			{
				if (is_in_rect(b->rect, (t_dot){win->mouse->x, win->mouse->y}) && map->selected_sector)
					b->texture = win->sectors_texture_selected[nb_sectors - i - 1];
				else
					b->texture = win->sectors_texture[nb_sectors - i - 1];
				b = b->next;
				i++;
			}
			printf("map->selected_sector = %p\n", map->selected_sector);
		}
		else if (win->mouse->x > f->rect.x + (f->rect.w / MAX_SECTORS) * (f->nb_buttons - 1) &&
				win->mouse->x < f->rect.x + (f->rect.w / MAX_SECTORS) * f->nb_buttons)
		{
			add_button_to_frame(&win->selected_frame, new_button((t_frect){1.0 / MAX_SECTORS * f->nb_buttons, 0, 1.0 / MAX_SECTORS, 1}, NULL, 0));
			add_sector(&map->sectors, new_sector());
			b = f->buttons;
			i = 0;
			b->texture = win->sectors_texture[MAX_SECTORS];
			b = b->next;
			while (b)
			{
				b->texture = win->sectors_texture[nb_sectors - i];
				b = b->next;
				i++;
			}
		}
	}
	else if (f->flags & FRAME_INFO)
	{
		if (win->selected_button)
		{
			b = win->selected_button;
			if (b->flags & BUTTON_COLOR_PICKER)
			{
				map->selected_sector->color.pos = (win->mouse->x - b->rect.x) / (float)b->rect.w;
				if (map->selected_sector)
					map->selected_sector->color.selected_color = get_selected_color(map->selected_sector->color.pos);
			}
		}
	}
}