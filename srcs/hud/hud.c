/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiordan <agiordan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:34:27 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 22:48:16 by agiordan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	hud_ammo(t_win *win, t_player *player, t_texhud *texhud)
{
	SDL_Texture		*text;
	char			*tmp;
	char			*tmp2;
	char			*tmp_free;

	tmp = ft_itoa(player->inventory->ammo);
	tmp_free = tmp;
	tmp = ft_strjoin(tmp, " | ");
	ft_strdel(&tmp_free);
	tmp_free = ft_itoa(player->inventory->magazine);
	tmp2 = ft_strjoin(tmp, tmp_free);
	ft_strdel(&tmp_free);
	text = generate_text(win->rend, texhud->police, tmp2,
		(SDL_Color){255, 255, 255, 50});
	SDL_RenderCopy(win->rend, text, NULL, &(SDL_Rect){(win->w * 0.09),
		(win->h * 0.9125), (win->w * 0.07), (win->h * 0.0725)});
	SDL_RenderCopy(win->rend, texhud->tex[0], NULL, &(SDL_Rect){(win->w * 0.01),
		(win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)});
	ft_strdel(&tmp2);
	ft_strdel(&tmp);
}

void	hud_health(t_win *win, t_player *player, t_texhud *texhud)
{
	int		i;
	float	hpposx;

	i = 0;
	hpposx = win->w * 0.857;
	SDL_RenderCopy(win->rend, texhud->tex[1], NULL,
		(&(SDL_Rect){(win->w * 0.76), (win->h * 0.8875),
		(win->w * 0.2), (win->h * 0.0875)}));
	while (i++ < player->current_hp)
	{
		SDL_RenderCopy(win->rend, texhud->tex[2], NULL,
			(&(SDL_Rect){(hpposx), (win->h * 0.92),
			(win->w * 0.006), (win->h * 0.02)}));
		hpposx += (win->w * 0.0009);
	}
}

void	hud_armor(t_win *win, t_player *player, t_texhud *texhud)
{
	int		i;
	float	armorposx;

	i = 0;
	armorposx = win->w * 0.858;
	SDL_RenderCopy(win->rend, texhud->tex[3], NULL,
	(&(SDL_Rect){(win->w * 0.76), (win->h * 0.7875),
	(win->w * 0.2), (win->h * 0.0875)}));
	while (i < player->current_armor)
	{
		SDL_RenderCopy(win->rend, texhud->tex[4], NULL,
		(&(SDL_Rect){(armorposx), (win->h * 0.8225),
		(win->w * 0.006), (win->h * 0.02)}));
		armorposx += (win->w * 0.0009);
		i++;
	}
}

void	hud(t_win *win, t_player *player, t_texhud *texhud)
{
	print_weapon(win, player, texhud);
	hud_health(win, player, texhud);
	hud_armor(win, player, texhud);
	hud_ammo(win, player, texhud);
	inventory_hud(win, texhud, player);
}
