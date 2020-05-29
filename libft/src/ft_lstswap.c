/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:35:01 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:22:36 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstswap(t_list **lst1, t_list **lst2)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return ;
	tmp->content = (*lst1)->content;
	tmp->content_size = (*lst1)->content_size;
	(*lst1)->content = (*lst2)->content;
	(*lst1)->content_size = (*lst2)->content_size;
	(*lst2)->content = tmp->content;
	(*lst2)->content_size = tmp->content_size;
}
