/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstswap.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 18:35:01 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 19:46:04 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
