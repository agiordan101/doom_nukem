/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_shape.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:19:45 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:52:39 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UI_SHAPE_H
# define UI_SHAPE_H

typedef struct	s_dot
{
	int			x;
	int			y;
}				t_dot;

typedef struct	s_fdot
{
	float		x;
	float		y;
}				t_fdot;

typedef struct	s_line
{
	t_dot		p1;
	t_dot		p2;
}				t_line;

typedef struct	s_rect
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_rect;

typedef struct	s_frect
{
	double		x;
	double		y;
	double		w;
	double		h;
}				t_frect;

int				ui_is_dot_in_rect(t_dot dot, t_rect rect);

#endif
