/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:34:07 by gal               #+#    #+#             */
/*   Updated: 2020/05/28 14:54:58 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"
#include "ui.h"
#include "ui_error.h"
#include "libft.h"

void		dead_menu_ui(t_win *win)
{
	ui_set_draw_color(win->rend, &(SDL_Color){71, 27, 27, 255});
	ui_clear_win(win->winui);
	ui_display_frames(win->winui, win->winui->ui.frames);
	ui_draw_rend(win->winui);
	ui_poll_event(&win->winui->event);
	ui_update_ui(win->winui);
}

void		define_line_shot(t_win *win, t_player *player)
{
	player->bullet_drop = NULL;
	player->len_bullet = 0;
	player->l[1] = is_point(win->w * 0.68, win->h * 0.62,
		win->w * 0.65, win->h * 0.6);
	player->l[2] = is_point(win->w * 0.65, win->h * 0.6,
		win->w * 0.605, win->h * 0.57);
	player->l[3] = is_point(win->w * 0.605, win->h * 0.57,
		win->w * 0.555, win->h * 0.535);
	player->l[4] = is_point(win->w * 0.555, win->h * 0.535,
		win->w * 0.5, win->h * 0.5);
}

int			end_game_win(t_win *win, t_map *map, t_player *player, int i)
{
	if (player->end)
	{
		i = win_menu(win, player);
		{
			if (i == 2)
			{
				main_free(win, map);
				exit(0);
			}
			else
			{
				i = 1;
				return (i);
			}
		}
	}
	return (0);
}
