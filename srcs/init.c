#include "doom_nukem.h"

/*
**	Produit vectoriel des vecteurs unitaire i et j
**	pour trouver le vecteur normal au plan
*/

void		init_polygone(t_poly *poly)
{
	int		i;

	i = 0;
	while (poly)
	{
		// if (i < 31) //Attention
		// {
		// 	translate_dot(&(poly->dots_rotz_only[0]), (t_fdot_3d){100, 400, 150});
		// 	translate_dot(&(poly->dots_rotz_only[1]), (t_fdot_3d){100, 400, 150});
		// 	translate_dot(&(poly->dots_rotz_only[2]), (t_fdot_3d){100, 400, 150});
		// 	translate_dot(&(poly->dots_rotz_only[3]), (t_fdot_3d){100, 400, 150});
		// }
		if (!(poly->object && poly->object->type && poly->object->type == DOOR))
		{
			poly->visible = 1;
			poly->collide = 1;
		}
		poly->index = i++;
		poly->is_slide_ban = 0;
		ft_memcpy(poly->dots, poly->dots_rotz_only, sizeof(t_fdot_3d) * N_DOTS_POLY);
		// ft_memcpy(poly->dots_rotz_only, poly->dots, sizeof(t_fdot_3d) * N_DOTS_POLY);
		poly->i_rotz_only = fdot_3d_sub(poly->dots_rotz_only[1], poly->dots_rotz_only[0]);
		poly->j_rotz_only = fdot_3d_sub(poly->dots_rotz_only[N_DOTS_POLY - 1], poly->dots_rotz_only[0]);
		poly->i = poly->i_rotz_only;
		poly->j = poly->j_rotz_only;
		poly->i_mag = mag(poly->i);
		poly->j_mag = mag(poly->j);
		poly->ii = poly->i_mag * poly->i_mag;
		poly->jj = poly->j_mag * poly->j_mag;
		poly->equation_rotz_only.v = normalize(vectoriel_product(poly->i_rotz_only, poly->j_rotz_only));
		poly->equation_rotz_only.d = -(poly->equation_rotz_only.v.x * poly->dots_rotz_only[0].x +\
								poly->equation_rotz_only.v.y * poly->dots_rotz_only[0].y +\
								poly->equation_rotz_only.v.z * poly->dots_rotz_only[0].z);
		poly->equation = poly->equation_rotz_only;
		// if (poly->object)
		// {
		// 	printf("dot %f %f %f\n", poly->dots_rotz_only[0].x, poly->dots_rotz_only[0].y, poly->dots_rotz_only[0].z);
		// 	print_poly(poly, 1);
		// }
		poly = poly->next;
	}
	// exit(0);
}

static void		init_player_maths(t_win *win, t_player *player)
{
	// win->map->view = TEXTURE_VIEW | WALL_VIEW | BOX_VIEW;
	win->map->view = TEXTURE_VIEW;
	// translate_all(win->map, (t_fdot_3d){-player->pos.x, -player->pos.y, -player->pos.z});

	translate_all_rotz_only(win->map, win->map->polys, (t_fdot_3d){-player->pos.x, -player->pos.y, -player->pos.z});
	rotate_all_rotz_only(win->map, win->map->polys, create_rz_matrix(-player->dir_init));
	// copy_rotate_rotz_only(win->map, win->map->polys, create_ry_matrix(0));
	player->rot_y = 0;
	player->ddir = 0.05;
	player->fov = win->w * M_PI_2 / 1000;
	player->fov_up = win->h * M_PI_2 / 1000;
	player->fov_2 = player->fov / 2;
	player->fov_up_2 = player->fov_up / 2;
	player->width_2 = player->width / 2;
	// player->height_10 = player->height / 10;
	// player->_9_height_10 = 9 * player->height_10;
	player->_4_height_10 = 2 * (float)player->height / 5;
	player->sneak = 0;
	player->collision_on = 1;
	player->fly = 0;
	win->w_div_fov = win->w / player->fov;
	win->h_div_fov = win->h / player->fov_up;
	if (init_rays(win, player))
		return (ft_putendl("Erreur malloc rays"));

	// t_object	*object;
	// object = win->map->objects;
	// while (object)
	// {
	// 	// if (object->type == LIGHT)
	// 	print_poly(object->poly, 1);
	// 	printf("Pos rotz %f %f %f\n", object->pos_rotz_only.x, object->pos_rotz_only.y, object->pos_rotz_only.z);
	// 	printf("Pos      %f %f %f\n\n", object->pos.x, object->pos.y, object->pos.z);
	// 	object = object->next;
	// }
	// exit(0);
}

static void		init_player_hud(t_player *player)
{
	player->inventory = define_inventory();
	player->maxHp = 100;
	player->currentHp = player->maxHp;
	player->maxArmor = 100;
	player->currentArmor = player->maxArmor;
	player->inventory->ammo = 15;
	player->inventory->magazine = 120;
	start_cooldown(&(player->timers.bullet_cd), 130);
	start_cooldown(&(player->timers.item_cd), 100);
	start_cooldown(&(player->timers.text_cd), 600);
	start_cooldown(&(player->timers.reload_cd), 600);
	start_cooldown(&(player->timers.animation_cd), 1000);
	start_cooldown(&(player->timers.shot_cd), 50);
	start_cooldown(&(player->timers.animation_shot_cd), 10);
    start_cooldown(&(player->timers.mouse), 10);
    player->timers.reload_cd.index = 5;
    player->timers.bullet_cd.index = 5;
    player->timers.bullet_cd.index = 0;
}

int			init_win_player(t_win *win, t_player *player)
{
	if (!(win->pixels = (Uint32 *)malloc(sizeof(Uint32) * win->w * win->h)))
		return (1);
	start_cooldown(&(win->view_change_time), 250);
	start_cooldown(&(win->map->objects_animation), 20);
	start_cooldown(&(win->map->objects_tp_timer), 2000);
	start_cooldown(&(player->interaction_inventaire_time), 250);
	start_cooldown(&(player->fly_timer), 250);
	init_player_maths(win, player);
	init_player_hud(player);
	// exit(0);
	return (0);
}

int			init_music_timer(t_map *map, t_doom_music *music)
{
	if (music)
	{
		if (!(music->editor_music = Mix_LoadMUS("sounds/map_editor.wav")))
			return (ret_error(SDL_GetError()));
		if (!(music->credit_music = Mix_LoadMUS("sounds/Remember_chill.mp3")))
			return (ret_error(SDL_GetError()));
		if (!(music->menu_music = Mix_LoadMUS("sounds/doomMenu.wav")))
			return (ret_error(SDL_GetError()));
	}
	// start_cooldown(&(map->gravity_inv_time), 5000);
	map = NULL;
	return (1);
}