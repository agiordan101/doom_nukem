/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:22:35 by widrye            #+#    #+#             */
/*   Updated: 2020/05/17 23:02:09 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_create_elem(char *line)
{
	t_list *list;

	if ((list = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = line;
	list->next = NULL;
	return (list);
}
