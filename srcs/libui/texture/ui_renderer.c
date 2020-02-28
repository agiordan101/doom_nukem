/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_renderer.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:36:16 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 17:36:18 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_texture.h"

void				ui_set_rend_target(SDL_Renderer *rend, SDL_Texture *texture)
{
	SDL_SetRenderTarget(rend, texture);
}
