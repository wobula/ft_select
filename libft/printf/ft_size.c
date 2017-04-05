/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:48:46 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/06 12:09:24 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_size(t_print *all, intmax_t nbr)
{
	int		array_size;

	array_size = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
		all->sign = '-';
	while (nbr != 0)
	{
		nbr = nbr / 10;
		array_size++;
	}
	return (array_size);
}
