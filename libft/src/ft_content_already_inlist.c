/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_already_inlist.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:18:34 by widrye            #+#    #+#             */
/*   Updated: 2020/02/27 19:20:36 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_content_already_inlist(t_list *lst, char *texname)
{
	t_list *l;

	l = lst;
	while (l && l->content)
	{
		if (!ft_strcmp(l->content, texname))
			return (1);
		l = l->next;
	}
	return (0);
}