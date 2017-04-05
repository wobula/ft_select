/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loaderu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:54:35 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/07 15:58:06 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_loaderu(char *dst, uintmax_t nbr, int size)
{
	if (nbr == 0)
	{
		dst[0] = '0';
		return (dst);
	}
	size--;
	while (nbr != 0)
	{
		dst[size] = nbr % 10 + '0';
		nbr = nbr / 10;
		size--;
	}
	dst[size] = '\0';
	return (dst);
}
