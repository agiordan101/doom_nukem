/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:14:19 by widrye            #+#    #+#             */
/*   Updated: 2020/05/17 23:00:02 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_list(t_list *lst)
{
	t_list *tmp;

	if (lst)
	{
		while (lst)
		{
			tmp = lst;
			if (lst->content)
				free(lst->content);
			lst = lst->next;
			free(tmp);
		}
	}
}
