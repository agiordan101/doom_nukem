/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 19:39:31 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 19:45:10 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
