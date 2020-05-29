/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:17:22 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/19 09:27:46 by gal              ###   ########lyon.fr   */
/*                                                                            */
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
