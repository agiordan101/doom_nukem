/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   credit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:58:14 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 16:58:16 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

SDL_Texture		*define_credit(t_win *win)
{
	SDL_Texture	*text;
	TTF_Font	*police;
	char		*tmp;

	police = TTF_OpenFont("TTF/DooM.ttf", 65);
	tmp = "Aducimet Agiordan Gmomacho Widrye";
	text = generate_text(win->rend,
							police,
							tmp,
							(SDL_Color){255, 255, 255, 50});
	free(tmp);
	return (text);
}

void			print_credit(t_win *win)
{
	SDL_Event	event;
	SDL_bool	loop;
	SDL_Texture	*background;

	background = load_texture(win->rend, "textures/creditBack.png");
	loop = SDL_TRUE;
	if (win)
	{
		if (Mix_PlayMusic(win->music.credit_music, -1) == -1)
			ft_putendl_fd("editor loop : Impossible to play map_editor.wav", 2);
		while (loop)
		{
			SDL_GetWindowSize(win->ptr, &win->w, &win->h);
			clear_rend(win->rend, 197, 50, 250);
			SDL_PumpEvents();
			SDL_PollEvent(&event);
			SDL_RenderCopy(win->rend, background, NULL,
							&(SDL_Rect){(0), (0), (win->w), (win->h)});
			if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
				loop = SDL_FALSE;
			SDL_RenderPresent(win->rend);
		}
		Mix_FadeOutMusic(100);
		init_main_menu(win);
	}
}
