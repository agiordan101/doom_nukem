/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gal <gal@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:56:53 by gmonacho          #+#    #+#             */
/*   Updated: 2020/05/10 22:23:46 by gal              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_round(double nb)
{
	int		rounded;

	rounded = nb;
	if (nb - (double)rounded < nb - ((double)rounded + 1.0))
		return (rounded);
	else
		return (rounded);
}
