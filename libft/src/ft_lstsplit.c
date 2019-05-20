/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 16:36:08 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 19:45:57 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

t_list	*ft_lstsplit(const char *s, char c)
{
	t_list	*lst;
	t_list	*start;
	char	**split;
	int		i;

	split = ft_strsplit(s, c);
	if (!(lst = (t_list*)malloc(
					sizeof(t_list) * (ft_tablen((void**)split) + 1))))
		return (NULL);
	start = lst;
	i = 0;
	while (split[i])
	{
		lst->next = ft_lstnew((void*)split[i], ft_strlen(split[i]));
		i++;
		lst = lst->next;
	}
	lst = start->next;
	free(start);
	return (lst);
}
