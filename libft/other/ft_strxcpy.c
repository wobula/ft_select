/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:58:12 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:27:09 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strxcpy(char *dst, const char *src, int s, int t)
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
