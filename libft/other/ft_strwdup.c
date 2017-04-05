/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:34:28 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/02 13:48:48 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

wchar_t	*ft_strwdup(wchar_t *s1)
{
	int		c;
	wchar_t *ptr;

	c = 0;
	if (!s1)
		return (NULL);
	while (s1[c] != '\0')
		c++;
	ptr = (wchar_t *)ft_memalloc(sizeof(wchar_t) * c + 1);
	c = 0;
	while (s1[c] != '\0')
	{
		ptr[c] = s1[c];
		c++;
	}
	ptr[c] = '\0';
	return (ptr);
}
