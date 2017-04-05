/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:02:14 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/08 09:32:02 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_loader(t_print *all, char *dst, intmax_t nbr, int size)
{
	uintmax_t test;

	test = 0;
	if (nbr == 0 && (all->sign = '+'))
	{
		dst[0] = '0';
		return (dst);
	}
	else if (nbr < 0 && (all->sign = '-'))
		test = nbr * -1;
	else if (nbr > 0 && (all->sign = '+'))
		test = nbr;
	size--;
	while (test != 0)
	{
		dst[size] = test % 10 + '0';
		test = test / 10;
		size--;
	}
	dst[size] = '\0';
	return (dst);
}
