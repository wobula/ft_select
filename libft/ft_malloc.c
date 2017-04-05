/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:32:14 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:50:50 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_malloc(int size)
{
	char	*ptr;

	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	else
		ptr[size] = '\0';
	return (ptr);
}
