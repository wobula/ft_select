/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwxnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:30:16 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/02 14:13:18 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

wchar_t	*ft_strwxnew(wchar_t letter, size_t size)
{
	wchar_t *ptr;

	if (!letter)
		return (ft_strwdup(L"\0"));
	ptr = (wchar_t *)malloc(sizeof(wchar_t) * size + 1);
	ptr[size] = L'\0';
	ptr = ft_charwset(ptr, letter, size);
	return (ptr);
}
