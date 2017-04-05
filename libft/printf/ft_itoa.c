/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 11:46:36 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/07 16:02:56 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(t_print *all, intmax_t nbr)
{
	int size;
	char*ptr;

	size = ft_size(all, nbr);
	ptr = ft_malloc(size);
	if (!ptr)
		return (NULL);
	return (ft_loader(all, ptr, nbr, size));
}
