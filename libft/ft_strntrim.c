/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strntrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 03:50:39 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:23:16 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strntrim(char *big, const char *little)
{
	char	*ptr;
	int		x;
	int		y;

	ptr = NULL;
	x = (ft_strlen(little)) + 1;
	y = ft_strlen(big);
	if (x + 1 == y)
		ptr = ft_strnew(0);
	else if (x == 0)
		ptr = ft_strndup(big, 1);
	else if (y > x)
		ptr = ft_strndup(big, x);
	free(big);
	return (ptr);
}
