/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 15:11:31 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 19:46:16 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_area;

	if (!(mem_area = (void*)malloc(size)))
		return (NULL);
	ft_bzero(mem_area, size);
	return (mem_area);
}
