/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 08:33:24 by widrye            #+#    #+#             */
/*   Updated: 2020/05/10 13:49:28 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void		attribute_texture(t_texhud *texhud, t_win *win)
{
	if (!(texhud->tex[0] = load_texture(win->rend, "textures/ammoIcon.png")) ||
!(texhud->tex[1] = load_texture(win->rend, "textures/healthBar.png")) ||
!(texhud->tex[2] = load_texture(win->rend, "textures/healthPixel.png")) ||
!(texhud->tex[3] = load_texture(win->rend, "textures/shieldBar.png")) ||
!(texhud->tex[4] = load_texture(win->rend, "textures/shieldPixel.png")) ||
!(texhud->tex[5] = load_texture(win->rend, "textures/slotIcon.png")) ||
!(texhud->tex[6] = load_texture(win->rend, "textures/selectedSlot.png")) ||
!(texhud->tex[7] = load_texture(win->rend, "textures/healthPotion.png")) ||
!(texhud->tex[8] = load_texture(win->rend, "textures/shieldPotion.png")) ||
!(texhud->tex[9] = load_texture(win->rend, "textures/pq.png")) ||
!(texhud->tex[11] = load_texture(win->rend, "textures/crosshairIcon.png")) ||
!(texhud->tex[12] = load_texture(win->rend, "textures/gameOverScreen.png")) ||
!(texhud->tex[13] = load_texture(win->rend, "textures/miniMap.png")) ||
!(texhud->tex[14] = load_texture(win->rend, "textures/boxPortalIcon.png")) ||
!(texhud->tex[15] = load_texture(win->rend, "textures/Ammo_box_icon.png")))
		ft_putendl("failed to load HUD textures");
	if (!(texhud->police = TTF_OpenFont("TTF/DooM.ttf", 65)))
		ft_putendl("failed to load Font TTF/DooM.ttf");
}

void		attribute_texture_weapon(t_texhud *texhud, t_win *win)
{
	if (!(texhud->tex_weapon[0] = load_texture(win->rend,
	"textures/weaponHud_3.png")) ||
	!(texhud->tex_weapon[1] = load_texture(win->rend,
	"textures/weaponHud_3.png")) ||
	!(texhud->tex_weapon[2] = load_texture(win->rend,
	"textures/weaponHud_2.png")) ||
	!(texhud->tex_weapon[3] = load_texture(win->rend,
	"textures/weaponHud_2.png")) ||
	!(texhud->tex_weapon[4] = load_texture(win->rend,
	"textures/weaponHud.png")) ||
	!(texhud->tex_weapon[5] = load_texture(win->rend,
	"textures/weaponHud.png")) ||
	!(texhud->tex_reload[0] = load_texture(win->rend,
		"textures/weaponLoad_1.png")) ||
	!(texhud->tex_reload[1] = load_texture(win->rend,
		"textures/weaponLoad_2.png")) ||
	!(texhud->tex_reload[2] = load_texture(win->rend,
		"textures/weaponLoad_3.png")) ||
	!(texhud->tex_reload[3] = load_texture(win->rend,
		"textures/weaponLoad_4.png")) ||
	!(texhud->tex_reload[4] = load_texture(win->rend,
		"textures/weaponLoad_1.png")))
		ft_putendl("failed to load weapon textures");
}

t_texhud	*define_texhud(t_win *win)
{
	t_texhud	*texhud;

	if (!(texhud = (t_texhud *)ft_memalloc(sizeof(t_texhud))))
		return (ret_null_error("texhud allocation failed in t_text_entry"));
	attribute_texture(texhud, win);
	attribute_texture_weapon(texhud, win);
	ft_putendl("texture_parse done →");
	return (texhud);
}
