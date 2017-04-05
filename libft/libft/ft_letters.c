/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:56:31 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:12:56 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_letters(char const *str, char c, int i)
{
	int d;
	int b;
	char*ptr;

	b = i;
	d = 0;
	while (str[b] != c && str[b] != '\0')
	{
		d++;
		b++;
	}
	ptr = (char *)malloc((sizeof(ptr) * d) + 1);
	if (!ptr)
		return (NULL);
	ptr = ft_fill(str, ptr, c, i);
	return (ptr);
}
