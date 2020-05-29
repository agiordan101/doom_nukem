/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:37:42 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/06 14:18:57 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ui_win.h"
#include "ui.h"

void	ui_free_ui(t_ui *ui)
{
	if (ui->frames)
	{
		ui_free_frames(&ui->frames);
		ui->frames = NULL;
	}
	ui->on_mouse_button = NULL;
	ui->clicked_button = NULL;
	if (ui->button_font)
	{
		TTF_CloseFont(ui->button_font);
		ui->button_font = NULL;
	}
	if (ui->textures)
		ui_free_textures(&ui->textures);
}
