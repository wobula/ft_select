/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:20:50 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/10 20:27:20 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strxdup(char *s1, int free)
{
	int length;
	char*ptr;

	length = 0;
	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	ptr = (char *)ft_memalloc(sizeof(char) * length + 1);
	length = 0;
	while (s1[length] != '\0' && (ptr[length] = s1[length]))
		length++;
	ptr[length] = '\0';
	if (free == 1)
		ft_strdel(&s1);
	return (ptr);
}
