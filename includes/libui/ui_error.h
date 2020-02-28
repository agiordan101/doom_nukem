/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui_error.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:17:22 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 18:17:23 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UI_ERROR_H
# define UI_ERROR_H

int		ui_ret_error(const char *function,
						const char *error_msg,
						int ret_value);
void	*ui_ret_null_error(const char *function,
							const char *error_msg,
							void *return_value);

#endif
