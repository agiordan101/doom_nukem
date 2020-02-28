/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_call_button_function.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 17:36:36 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 15:21:49 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ui_win.h"

void	ui_call_simple_function(t_winui *win, t_simple_button *simple_button)
{
	if (simple_button->f && simple_button->clicked_condition & win->mouse.releasing)
		simple_button->f(simple_button->argurment);
}

void	ui_call_text_entry_function(t_text_entry_button *text_entry_button)
{
	if (text_entry_button->f)
		text_entry_button->f(text_entry_button->argument,
		text_entry_button->text);
}
