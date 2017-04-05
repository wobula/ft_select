/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:33:00 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/07 15:58:46 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoau(uintmax_t nbr)
{
	int size;
	char*ptr;

	size = ft_sizeu(nbr);
	ptr = ft_malloc(size);
	if (!ptr)
		return (NULL);
	return (ft_loaderu(ptr, nbr, size));
}
