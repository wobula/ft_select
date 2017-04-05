/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:15:32 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/13 12:15:35 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoal(int nbr)
{
	int		size;
	char	*ptr;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_sizel(nbr);
	ptr = ft_malloc(size);
	if (!ptr)
		return (NULL);
	return (ft_loaderl(ptr, nbr, size));
}
