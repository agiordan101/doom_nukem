/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:21:37 by widrye            #+#    #+#             */
/*   Updated: 2020/02/27 19:22:06 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list *ft_lst_pb(t_list **begin_list, char *line)
{
	t_list *list;
	if (!begin_list || !*begin_list)
		*begin_list = ft_create_elem(line);
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		if ((list->next = ft_create_elem(line)) == NULL)
			return (NULL);
	}
	return (*begin_list);
}