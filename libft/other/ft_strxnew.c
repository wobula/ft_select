/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strxnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 07:55:24 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:26:57 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strxnew(int letter, size_t size)
{
	char *ptr;

	if (!letter)
		return (ft_strdup("\0"));
	ptr = (char *)malloc(sizeof(char) * size + 1);
	ptr[size] = '\0';
	ptr = ft_charset(ptr, letter, size);
	return (ptr);
}
