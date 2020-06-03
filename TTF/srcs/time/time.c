/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:10:18 by agiordan          #+#    #+#             */
/*   Updated: 2020/05/28 14:04:08 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	start_cooldown(t_timer *timer, uint32_t time)
{
	timer->save = SDL_GetTicks();
	timer->time = time;
}

int		test_timer_refresh(t_timer *timer)
{
	if (SDL_GetTicks() > timer->save + timer->time)
	{
		timer->save = SDL_GetTicks();
		return (1);
	}
	else
		return (0);
}

int		test_timer(t_timer *timer)
{
	if (SDL_GetTicks() > timer->save + timer->time)
		return (1);
	else
		return (0);
}

void	reload_cd(t_map *map)
{
	int	i;

	i = -1;
	if (test_timer_refresh(&(map->player.timers.shot_cd)) == 1 &&\
			map->player.timers.bullet_cd.index < 5)
		map->player.timers.bullet_cd.index++;
	if (map->player.bullet_drop)
	{
		while (++i < map->player.len_bullet)
			(map->player.bullet_drop[i])++;
		if (map->player.bullet_drop[0] >= 5)
			del_bullet(&map->player);
	}
	if (test_timer_refresh(&(map->player.timers.reload_cd)) == 1 &&\
			map->player.timers.reload_cd.index < 4)
		map->player.timers.reload_cd.index++;
	if (map->player.timers.reload_cd.index == 4)
		map->player.inventory->weapon = 1;
	if (test_timer_refresh(&(map->player.timers.mouse)) == 1)
		map->player.timers.mouse.index = 0;
}
