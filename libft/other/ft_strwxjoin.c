/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwxjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 14:27:52 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 11:07:02 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

wchar_t	*ft_strwxjoin(wchar_t *s1, wchar_t *s2, int free)
{
	int		c;
	wchar_t *ptr;

	if (!s1 || !s2)
		return (NULL);
	c = ft_strwlen(s1) + ft_strwlen(s2);
	ptr = malloc(c + 1);
	if (!ptr)
		return (NULL);
	ptr = ft_strwxcpy(ptr, s1, 0, 0);
	ptr = ft_strwxcpy(ptr, s2, 0, (ft_strwlen(s1)));
	if (free == 1)
		ft_strwdel(&s1);
	else if (free == 2)
		ft_strwdel(&s2);
	else if (free == 3)
	{
		ft_strwdel(&s1);
		ft_strwdel(&s2);
	}
	return (ptr);
}
