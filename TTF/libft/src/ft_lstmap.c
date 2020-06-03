/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 18:12:09 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:22:25 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dst;

	dst = NULL;
	if (lst)
	{
		dst = f(lst);
		dst->next = ft_lstmap(lst->next, *f);
	}
	return (dst);
}
