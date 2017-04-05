/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charwset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:32:25 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/02 13:52:15 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

wchar_t	*ft_charwset(wchar_t *str, wchar_t x, int size)
{
	int c;

	c = 0;
	while (size > c && (str[c] = x))
		c++;
	return (str);
}
