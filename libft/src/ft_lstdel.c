/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 19:39:31 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:22:12 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*lst;
	t_list	*tmp_next;

	lst = *alst;
	while (lst)
	{
		tmp_next = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = tmp_next;
	}
	*alst = NULL;
}
