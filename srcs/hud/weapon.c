#include "doom_nukem.h"

void	draw_color_line(t_win *win, t_dot p1, t_dot p2)
{
	int		i;
	int		n_pixels;
	t_fdot	delta;
	t_fdot	absdelta;
	t_fdot	pixel;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	absdelta = (t_fdot){fabs(delta.x), fabs(delta.y)};
	n_pixels = absdelta.x > absdelta.y ? absdelta.x : absdelta.y;
	delta.x /= n_pixels;
	delta.y /= n_pixels;
	i = 0;
	while (i < n_pixels)
	{
		pixel = (t_fdot){	.x = p1.x + delta.x * i,\
							.y = p1.y + delta.y * i};
		if (0 <= pixel.y && pixel.y < win->h && 0 <= pixel.x && pixel.x < win->w)
		{
			SDL_SetRenderDrawColor(win->rend, 244, 244, 74, 255);
			SDL_RenderDrawPoint(win->rend, pixel.x, pixel.y);
		}
		i++;
	}
}
t_line 	is_point(int p1x, int p1y, int p2x, int p2y)
{	
	t_line l;

	l.p1.x = p1x;
	l.p1.y = p1y;
	l.p2.x = p2x;
	l.p2.y = p2y;
	return(l);
}

void	define_line_shot(t_win *win, t_player *player)
{	
	int i;

	i = 1;
	player->bullet_drop = NULL;
	player->len_bullet = 0;
	//player->l[0] = is_point(900, 470, 634, 490);
	player->l[1] = is_point(win->w * 0.68, win->h * 0.65, win->w * 0.637, win->h * 0.625);
	player->l[2] = is_point(win->w * 0.637, win->h * 0.625, win->w * 0.595, win->h * 0.6);
	player->l[3] = is_point(win->w * 0.595, win->h * 0.6, win->w * 0.552, win->h * 0.575);
	player->l[4] = is_point(win->w * 0.552, win->h * 0.575, win->w * 0.51, win->h * 0.55);
	// while (i < 4)
	// {	
	// 	printf( "%d | %d | %d | %d\n", player->l[i].p1.x, player->l[i].p1.y, player->l[i].p2.x, player->l[i].p2.y);
	// 	i++;
	// }
}

void	del_bullet(t_player *player)	//Supprime le 1er compteur
{
	int	i;
	int *tmp;

	player->len_bullet--;
	if (player->len_bullet)
	{	
		if (!(tmp = (int *)malloc(sizeof(int) * (player->len_bullet))))
				ft_putendl("error malloc in weapon.c l.57");
		i = -1;
		while (++i < player->len_bullet)
			tmp[i] = player->bullet_drop[i + 1];
		free(player->bullet_drop);
		player->bullet_drop = tmp;
	}
	else
	{
		free(player->bullet_drop);
		player->bullet_drop = NULL;
	}
}

void	add_bullet(t_player *player)	//Ajoute un nouveau compteur a la fin
{
	int i;
	int *tmp;

	i = -1;
	if (!(tmp = (int *)malloc(sizeof(int) * (player->len_bullet + 1))))
		ft_putendl("error malloc in weapon.c l.73");
	tmp[player->len_bullet] = 0;
	while (++i < player->len_bullet)
		tmp[i] = player->bullet_drop[i];
	free(player->bullet_drop);
	player->bullet_drop = tmp;
	player->len_bullet++;
}

void    print_weapon(t_win *win, t_player *player, t_texhud *texhud)
{   
    int             slotposx;
	int 	i;

    slotposx = 500;
	i = -1;
    if (player->inventory->weapon == 1 && !(player->inventory->magazine == 0 && player->inventory->ammo == 0))
    {   
        SDL_RenderCopy(win->rend, texhud->tex_weapon[player->timers.bullet_cd.index], NULL, &(SDL_Rect){(win->w * 0.55), (win->h * 0.55), (win->w * 0.7), (win->h * 0.4625)});
        SDL_RenderCopy(win->rend, texhud->tex[11], NULL, &(SDL_Rect){(win->w * 0.45), (win->h * 0.475), (win->w * 0.12), (win->h * 0.15)});
    }
    else
    {
        SDL_RenderCopy(win->rend, texhud->tex_reload[player->timers.reload_cd.index], NULL, &(SDL_Rect){(win->w * 0.55), (win->h * 0.575), (win->w * 0.7), (win->h * 0.4375)});   
    }
	//printf("b = %d\n", player->len_bullet);
	while (++i < player->len_bullet)
	{	
		draw_color_line(win, player->l[player->bullet_drop[i]].p1, player->l[player->bullet_drop[i]].p2);
	}
}