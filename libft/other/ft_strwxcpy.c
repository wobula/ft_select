/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwxcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:32:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/02 14:46:30 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

wchar_t	*ft_strwxcpy(wchar_t *dst, wchar_t *src, int s, int t)
{
	while (src[s] != '\0')
	{
		dst[t] = src[s];
		s++;
		t++;
	}
	dst[t] = '\0';
	return (dst);
}
