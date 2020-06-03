/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_export_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 10:47:47 by widrye            #+#    #+#             */
/*   Updated: 2020/05/16 23:59:19 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

int		ed_write_texture(int fd, t_list **lst, char *texname)
{
	static char		tmp[BUFSIZ];
	int				fd_text;
	int				n;
	int				bytes;

	if (!texname)
		texname = ft_strdup("brique.png");
	if (!ft_content_already_inlist(*lst, texname))
	{
		*lst = ft_lst_pb(lst, ft_strdup(texname));
		fd_text = open(ft_strjoin("textures/", texname), O_RDONLY);
		if (fd_text < 0)
			return (0);
		bytes = 0;
		while ((n = read(fd_text, tmp, sizeof(tmp))))
			bytes += n;
		ft_putendl_fd(texname, fd);
		ft_putendl_fd(ft_itoa(bytes), fd);
		fd_text = open(ft_strjoin("textures/", texname), O_RDONLY);
		while ((n = read(fd_text, tmp, sizeof(tmp))))
			if (write(fd, tmp, n) < 0)
				return (0);
		ft_putchar_fd('\n', fd);
	}
	return (1);
}

int		export_weapon_textures(int fd)
{
	t_list		*lst;

	lst = NULL;
	if (!ed_write_texture(fd, &lst, "weaponHud_3.png") ||
		!ed_write_texture(fd, &lst, "weaponHud_2.png") ||
		!ed_write_texture(fd, &lst, "weaponHud.png") ||
		!ed_write_texture(fd, &lst, "weaponLoad_1.png") ||
		!ed_write_texture(fd, &lst, "weaponLoad_2.png") ||
		!ed_write_texture(fd, &lst, "weaponLoad_3.png") ||
		!ed_write_texture(fd, &lst, "weaponLoad_4.png"))
	{
		ft_free_list(lst);
		return (0);
	}
	ft_free_list(lst);
	return (1);
}

int		export_hud_textures(int fd)
{
	t_list		*lst;

	lst = NULL;
	if (!ed_write_texture(fd, &lst, "ammoIcon.png") ||
		!ed_write_texture(fd, &lst, "healthBar.png") ||
		!ed_write_texture(fd, &lst, "healthPixel.png") ||
		!ed_write_texture(fd, &lst, "shieldBar.png") ||
		!ed_write_texture(fd, &lst, "shieldPixel.png") ||
		!ed_write_texture(fd, &lst, "slotIcon.png") ||
		!ed_write_texture(fd, &lst, "selectedSlot.png") ||
		!ed_write_texture(fd, &lst, "healthPotion.png") ||
		!ed_write_texture(fd, &lst, "shieldPotion.png") ||
		!ed_write_texture(fd, &lst, "pq.png") ||
		!ed_write_texture(fd, &lst, "crosshairIcon.png") ||
		!ed_write_texture(fd, &lst, "gameOverScreen.png") ||
		!ed_write_texture(fd, &lst, "miniMap.png") ||
		!ed_write_texture(fd, &lst, "boxPortalIcon.png") ||
		!ed_write_texture(fd, &lst, "creditBack.png") ||
		!ed_write_texture(fd, &lst, "Ammo_box_icon.png"))
	{
		ft_free_list(lst);
		return (0);
	}
	ft_free_list(lst);
	return (1);
}

int		export_ui_textures(int fd)
{
	t_list		*lst;

	lst = NULL;
	if (!ed_write_texture(fd, &lst, "imageMenu.png") ||
		!ed_write_texture(fd, &lst, "ui_text_entry_button_normal.png") ||
		!ed_write_texture(fd, &lst, "ui_text_entry_button_writting.png") ||
		!ed_write_texture(fd, &lst, "ui_normal_button.png") ||
		!ed_write_texture(fd, &lst, "ui_normal_button_square.png") ||
		!ed_write_texture(fd, &lst, "ui_on_mouse_button.png") ||
		!ed_write_texture(fd, &lst, "ui_clicked_button.png") ||
		!ed_write_texture(fd, &lst, "ui_clicked_button_square.png") ||
		!ed_write_texture(fd, &lst, "ui_clicked_button_blue.png") ||
		!ed_write_texture(fd, &lst, "ui_frame.png") ||
		!ed_write_texture(fd, &lst, "ui_on_mouse_button.png") ||
		!ed_write_texture(fd, &lst, "ui_on_mouse_button_grey.png") ||
		!ed_write_texture(fd, &lst, "ui_on_mouse_button_square.png") ||
		!ed_write_texture(fd, &lst, "ghost.png") ||
		!ed_write_texture(fd, &lst, "desert.jpg"))
	{
		ft_free_list(lst);
		return (0);
	}
	ft_free_list(lst);
	return (1);
}

int		ed_export_textures(int fd, t_map *map)
{
	t_list		*lst;
	t_object	*obj;
	t_mob		*mob;
	t_poly		*poly;
	int			ret;

	lst = NULL;
	ret = 0;
	obj = map->objects;
	ret = export_hud_textures(fd);
	ret = export_weapon_textures(fd);
	ret = export_ui_textures(fd);
	while (ret && obj && (ret = ed_write_texture(fd, &lst, obj->texture)) == 1)
		obj = obj->next;
	mob = map->mob;
	while (ret && mob && (ret = ed_write_texture(fd, &lst, mob->texture)))
		mob = mob->next;
	poly = map->polys;
	while (ret && poly && !poly->object &&
	(ret = ed_write_texture(fd, &lst, poly->texture_name)))
		poly = poly->next;
	ft_free_list(lst);
	return (ret);
}
