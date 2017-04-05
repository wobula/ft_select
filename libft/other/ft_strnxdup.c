/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnxdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:31:16 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:23:34 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnxdup(const char *s1, size_t offset, size_t spaces)
{
	size_t	counter;
	char	*ptr;

	counter = 0;
	ptr = ft_strnew(spaces);
	if (ptr == NULL)
		return (NULL);
	while (spaces > counter)
	{
		ptr[counter] = s1[counter + offset];
		counter++;
	}
	return (ptr);
}
