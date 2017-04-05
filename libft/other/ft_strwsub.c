/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:58:23 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 11:06:48 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

wchar_t	*ft_strwsub(wchar_t *s, unsigned int start, size_t len)
{
	wchar_t *ptr;
	int		c;

	c = 0;
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(wchar_t) * (len + 1));
	if (!ptr)
		return (NULL);
	while (len > 0)
	{
		ptr[c] = s[start];
		start++;
		c++;
		len--;
	}
	ptr[c] = '\0';
	return (ptr);
}
