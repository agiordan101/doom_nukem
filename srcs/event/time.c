/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 16:24:32 by gal               #+#    #+#             */
/*   Updated: 2020/05/10 16:25:10 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	draw_fps(void)
{
	static int		nb_frame = 0;
	static Uint32	time_since_last = 0;
	int				new_time;

	if (!nb_frame)
		time_since_last = SDL_GetTicks();
	nb_frame++;
	new_time = SDL_GetTicks();
	if (new_time - time_since_last > 1000)
	{
		ft_putnbr(nb_frame);
		ft_putchar('\n');
		nb_frame = 0;
	}
}
