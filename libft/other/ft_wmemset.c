/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmemset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:42:43 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/02 13:51:26 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_wmemset(void *b, int c, size_t len)
{
	int		x;
	wchar_t	*ptr;

	x = 0;
	ptr = b;
	while (len > 0)
	{
		ptr[x] = c;
		c++;
		len--;
	}
	ptr = NULL;
	return (b);
}
