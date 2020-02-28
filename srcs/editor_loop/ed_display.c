#include "doom_nukem.h"
#include "ui_draw.h"

// static void			display_buttons(t_win *win, t_frame *f)
// {
// 	t_button	*b;

// 	b = f->buttons;
// 	while (b)
// 	{
// 		if (b->texture)
// 			SDL_RenderCopy(win->rend, b->texture, NULL, &b->rect);
// 		else
// 			draw_ratio_rect(win, &f->rect, &b->ratio);
// 		b = b->next;
// 	}
// }

// static void			display_frames(t_win *win)
// {
// 	t_frame		*f;

// 	SDL_SetRenderDrawColor(win->rend, 200, 200, 200, 255);
// 	f = win->frames;
// 	while (f)
// 	{
// 		if (!(f->flags & FRAME_HIDE))
// 		{
// 			if (f->texture)
// 				SDL_RenderCopy(win->rend, f->texture, NULL, &f->rect);
// 			else
// 				draw_ratio_rect(win, &(SDL_Rect){0, 0, win->w, win->h}, &f->ratio);
// 			display_buttons(win, f);
// 		}
// 		f = f->next;
// 	}
// }

// static t_sector			*get_player_sector(t_sector *sectors, int i_sector)
// {
// 	t_sector	*s;
// 	int			i;
// 	int			i_target;

// 	s = sectors;
// 	i = 0;
// 	i_target = get_nb_sectors(sectors) - i_sector - 1;
// 	while (s && i < i_target)
// 	{
// 		i++;
// 		s = s->next;
// 	}
// 	return (s);
// }

// static void				display_errors(t_win *win)
// {
// 	t_frame		*f;
// 	t_dot		pos;
// 	int			i;
// 	int			nb_lines;


// 	f = get_frame(&win->frames, FRAME_ERROR);
// 	pos.x = f->rect.x;
// 	pos.y = f->rect.y;
// 	if (win->nb_error_msg != 0 && f)
// 	{
// 		i = 0;
// 		while (win->error_msg[i])
// 		{
// 			nb_lines = display_text(win, pos, f->rect.w, win->error_msg[i]);
// 			pos.y += win->h * TEXT_RATIO * nb_lines;
// 			i++;
// 		}
// 	}
// }

// static int		draw_id(t_win *win, t_dot pos, int id, float unit)
// {
// 	SDL_Texture		*texture;

// 	if (!(texture = generate_text(win->rend, win->font.digital, ft_itoa(id), (SDL_Color){200, 0, 200, 255})))
// 	{
// 		ft_putendl_fd(SDL_GetError(), 2);
// 		return (ret_error("draw_id : text generation failed"));
// 	}	
// 	if (SDL_RenderCopy(win->rend, texture, NULL, &(SDL_Rect){pos.x, pos.y, ID_SIZE * unit, ID_SIZE * unit}) == -1)
// 	{
// 		ft_putendl_fd(SDL_GetError(), 2);
// 		return (ret_error("draw_id : SDL_RenderCopy failed"));
// 	}	
// 	SDL_DestroyTexture(texture);
// 	return (1);
// }

// static void			draw_perpendicular(t_win *win, t_linedef l, float unit)
// {
// 	float	a1;
// 	float	a2;
// 	int		dx;
// 	int		dy;
// 	float	angle;
// 	t_dot	center;
// 	int		len;

// 	len = SIDE_LEN * unit;
// 	if (l.side != SIDE_NONE)
// 	{
// 		if (l.p2.x - l.p1.x != 0)
// 		{
// 			if (l.p2.y - l.p1.y == 0)
// 			{
// 				dx = 0;
// 				dy = (l.side == SIDE_RIGHT) ? len : -len;
// 				if (l.p2.x < l.p1.x)
// 					dy *= -1;
// 			}
// 			else
// 			{
// 				a1 = (l.p2.y - l.p1.y) / (float)(l.p2.x - l.p1.x);
// 				a2 = -1 / a1;
// 				angle = atan(a2);
// 				dx = (l.side == SIDE_RIGHT) ? cos(angle) * len : -cos(angle) * len;
// 				if (l.p2.y > l.p1.y)
// 					dx *= -1;
// 				dy = dx * a2;
// 			}
// 		}
// 		else
// 		{
// 			dx = (l.side == SIDE_RIGHT) ? len : -len;
// 			dy = 0;
// 			if (l.p1.y < l.p2.y)
// 				dx *= -1;
// 		}
// 		center.x = (l.p1.x + l.p2.x) / 2;
// 		center.y = (l.p1.y + l.p2.y) / 2;
// 		draw_line(win, center, (t_dot){center.x + dx, center.y + dy});
// 		draw_id(win, (t_dot){center.x - dx, center.y - dy}, l.id, unit);
// 	}
// }

// static SDL_Color	ed_get_display_color(t_poly *poly)
// {
// 	if (ed_is_wall(poly))
// 		return ((SDL_Color){0, 0, 255, 255});
// 	else if (ed_is_inclined(poly))
// 		return ((SDL_Color){255, 0, 0, 255});
// 	else if (ed_is_flat(poly))
// 		return ((SDL_Color){0, 255, 0, 255});
// 	else
// 		return ((SDL_Color){255, 255, 255, 255});
// }

// static void			ed_print_FUCKING_dots(t_poly *poly)
// {
// 	printf("poly:\ndot[0] : x = %f y = %f\ndot[1] : x = %f y = %f\ndot[2] : x = %f y = %f\ndot[3] : x = %f y = %f\n",
// 	poly->dots[0].x, poly->dots[0].y, poly->dots[1].x, poly->dots[1].y,
// 	poly->dots[2].x, poly->dots[2].y, poly->dots[3].x, poly->dots[3].y);
// }

SDL_bool		ed_is_poly_printable(const t_map *map, t_poly *poly)
{
	int	inter;
	int	min;
	int	max;

	inter = ft_abs(map->editor.max_pos_z - map->editor.min_pos_z);
	min = map->editor.min_pos_z + inter * (map->editor.z_min / 100.f);
	max = map->editor.min_pos_z + inter * (map->editor.z_max / 100.f);
	if ((poly->dots[0].z >= min && poly->dots[0].z <= max) ||
			(poly->dots[1].z >= min && poly->dots[1].z <= max) ||
			(poly->dots[2].z >= min && poly->dots[2].z <= max) ||
			(poly->dots[3].z >= min && poly->dots[3].z <= max))
		return (1);
	else
		return (0);
}


static void			ed_display_polys_flat(t_win *win, const t_map *map)
{
	t_poly		*poly;
	SDL_Color	color;

	poly = map->polys;
	while (poly)
	{
		color = ed_get_flat_display_color(map, poly);
		ui_set_draw_color(win->rend, &color);
		if (ed_is_flat(poly) && ed_is_poly_printable(map, poly))
			ed_display_flat(win, map, poly);	
		poly = poly->next;
	}
}

static void			ed_display_polys_inclined(t_win *win, const t_map *map)
{
	t_poly		*poly;
	SDL_Color	color;

	color = (SDL_Color){255, 0, 0, 255};
	ui_set_draw_color(win->rend, &color);
	poly = map->polys;
	while (poly)
	{
		if (ed_is_inclined(poly) && ed_is_poly_printable(map, poly))
			ed_display_inclined(win, map, poly);
		poly = poly->next;
	}
}

static void			ed_display_polys_wall(t_win *win, const t_map *map)
{
	t_poly		*poly;
	SDL_Color	color;

	poly = map->polys;
	while (poly)
	{
		color = ed_get_wall_display_color(map, poly);
		ui_set_draw_color(win->rend, &color);
		if (ed_is_wall(poly) && ed_is_poly_printable(map, poly))
			ed_display_wall(win, map, poly);
		poly = poly->next;
	}
}

static void			ed_display_placing_poly(t_win *win, const t_map *map)
{
	ui_set_draw_color(win->winui->rend,
					&(SDL_Color){255, 225, 0, 255});
	if (map->editor.placing_poly)
	{
		if (ed_is_wall(map->editor.placing_poly))
			ed_display_wall(win, map, map->editor.placing_poly);
		else if (ed_is_flat(map->editor.placing_poly))
			ed_display_flat(win, map, map->editor.placing_poly);
		else if (ed_is_inclined(map->editor.placing_poly))	
			ed_display_inclined(win, map, map->editor.placing_poly);
		else
			printf("poly z : %f %f %f %f\n", map->editor.placing_poly->dots[0].z,
											map->editor.placing_poly->dots[1].z,
											map->editor.placing_poly->dots[2].z,
											map->editor.placing_poly->dots[3].z);
	}
}

static void			ed_display_polys(t_win *win, const t_map *map)
{
	ed_display_polys_flat(win, map);
	ed_display_polys_inclined(win, map);
	ed_display_polys_wall(win, map);
	ed_display_mobs(win, map);
	ed_display_selected_poly(win, map);
	ed_display_selected_mob(win, map);
	ed_display_placing_poly(win, map);
}

static void			ed_display_mouse_position(t_win *win, const t_map *map)
{
	t_text_area		*text_area;
	char			*tmp;

	if (map->editor.selected_poly)
	{
		text_area = ui_get_text_area_button(win->winui, "b_poly_dot_0");
		if (text_area)
		{
			ft_strdel(&text_area->text);
			tmp = ft_itoa(map->editor.selected_poly->dots[0].z);
			text_area->text = ft_strjoin("dot[0] = ", tmp);
		}
		text_area = ui_get_text_area_button(win->winui, "b_poly_dot_1");
		if (text_area)
		{
			ft_strdel(&text_area->text);
			tmp = ft_itoa(map->editor.selected_poly->dots[1].z);
			text_area->text = ft_strjoin("dot[1] = ", tmp);
		}
		text_area = ui_get_text_area_button(win->winui, "b_poly_dot_2");
		if (text_area)
		{
			ft_strdel(&text_area->text);
			tmp = ft_itoa(map->editor.selected_poly->dots[2].z);
			text_area->text = ft_strjoin("dot[2] = ", tmp);
		}
		text_area = ui_get_text_area_button(win->winui, "b_poly_dot_3");
		if (text_area)
		{
			ft_strdel(&text_area->text);
			tmp = ft_itoa(map->editor.selected_poly->dots[3].z);
			text_area->text = ft_strjoin("dot[3] = ", tmp);
		}
	}
}

static void			ed_display_selection_rect(t_win *win, const t_map *map)
{
	t_dot	pos;

	pos = ed_get_display_point(map, (t_dot){map->editor.select_rect.x,
											map->editor.select_rect.y});
	ui_set_draw_color(win->winui->rend, &(SDL_Color){225, 225, 225, 255});
	if (win->winui->mouse.clicked & UI_MOUSE_RIGHT ||
		(map->editor.flags & ED_SELECTION
		&& win->winui->mouse.clicked & UI_MOUSE_LEFT))
		ui_draw_rect(win->winui->rend, &(t_rect){
		pos.x,
		pos.y,
		map->editor.select_rect.w * map->editor.unit,
		map->editor.select_rect.h * map->editor.unit});
}

void			ed_display(t_win *win, const t_map *map)
{
	ed_display_polys(win, map);
	ed_display_objects(win, map);
	ed_display_player(win, map);
	ed_display_selected_obj(win, map);
	ed_display_mouse_position(win, map);
	ed_display_selection_rect(win, map);
	draw_fps();
}