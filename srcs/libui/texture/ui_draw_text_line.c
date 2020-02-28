/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_draw_text_line.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:36:03 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 12:43:49 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_texture.h"
#include "ui_error.h"
#include "libft.h"


static void		fill_src_struct(const t_rect *data, t_rect **filled_rect)
{
	(*filled_rect)->x = data->x;
	(*filled_rect)->y = data->y;
	(*filled_rect)->w = data->w;
	(*filled_rect)->h = data->h;
}

static void		fill_src_rect(t_text_line_kit *text,
								t_rect **src_rect,
								t_dot texture_size,
								int width)
{
	if (width > text->max_width)
	{
		if (text->alignment & TEXT_ALIGN_LEFT)
		{
			fill_src_struct(&(t_rect){0, 0,
					texture_size.x * text->max_width / width,
					texture_size.y}, src_rect);
		}
		else if (text->alignment & TEXT_ALIGN_RIGHT)
		{
			fill_src_struct(&(t_rect){
				texture_size.x - texture_size.x * text->max_width / width,
				0, texture_size.x, texture_size.y}, src_rect);
		}
		else if (text->alignment & TEXT_ALIGN_CENTER)
		{
			fill_src_struct(&(t_rect){
			texture_size.x / 2 - texture_size.x * text->max_width / width / 2,
			0, texture_size.x * text->max_width / width, texture_size.y}, src_rect);
		}
		else
		{
			free(*src_rect);
			*src_rect = NULL;
		}
	}
	else
	{
		free(*src_rect);
		*src_rect = NULL;
	}
}

static t_rect	*get_src_rect(t_text_line_kit *text,
								t_dot texture_size,
								int width)
{
	t_rect	*src_rect;

	if (!(src_rect = (t_rect*)ft_memalloc(sizeof(t_rect))))
	{
		return (ui_ret_null_error("get_src_rect",
				"src_rect allocation failed", NULL));
	}
	fill_src_rect(text, &src_rect, texture_size, width);
	return (src_rect);
}

static t_rect	get_dst_rect(t_text_line_kit *text, int width)
{
	if (width > text->max_width)
	{
		if (text->alignment & TEXT_ALIGN_RIGHT)
			return ((t_rect){text->pos.x - text->max_width,
				text->pos.y, text->max_width, text->height});
		else if (text->alignment & TEXT_ALIGN_CENTER)
			return ((t_rect){text->pos.x - text->max_width / 2,
				text->pos.y, text->max_width, text->height});
		else
			return ((t_rect){text->pos.x, text->pos.y,
				text->max_width, text->height});
	}
	else
	{
		if (text->alignment & TEXT_ALIGN_RIGHT)
			return ((t_rect){text->pos.x - width, text->pos.y,
				width, text->height});
		else if (text->alignment & TEXT_ALIGN_CENTER)
			return ((t_rect){text->pos.x - width / 2,
				text->pos.y, width, text->height});
		else
			return ((t_rect){text->pos.x, text->pos.y, width, text->height});
	}
}

static int		get_dst_y(t_text_line_kit *text)
{
	if (text->alignment & TEXT_ALIGN_V_MIDDLE)
		return (text->pos.y - text->height / 2);
	else if (text->alignment & TEXT_ALIGN_V_TOP)
		return (text->pos.y - text->height);
	else
		return (text->pos.y);
}

int				ui_draw_text_line(SDL_Renderer *rend,
							t_text_line_kit *text)
{
	int			width;
	SDL_Texture	*texture;
	t_rect		*src_rect;
	t_rect		dst_rect;
	t_dot		texture_size;

	if (text && text->str)
	{
		width = ui_get_text_width(text->font, text->str, text->height);
		if ((texture = ui_new_text(rend, text->font,
		text->str, &text->color)))
		{
			SDL_QueryTexture(texture, NULL, NULL,
					&texture_size.x, &texture_size.y);
			src_rect = get_src_rect(text, texture_size, width);
			dst_rect = get_dst_rect(text, width);
			dst_rect.y = get_dst_y(text);
			SDL_RenderCopy(rend, texture,
			(SDL_Rect*)src_rect, (SDL_Rect*)&dst_rect);
			SDL_DestroyTexture(texture);
			if (src_rect)
				free(src_rect);
		}
	}
	return (text->height);
}
