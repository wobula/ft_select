/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:19:39 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:24:00 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int i;
	int d;
	char**ptr;

	if ((!c) || (!s))
		return (NULL);
	d = 0;
	i = 0;
	ptr = ft_words(s, c);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ptr[d] = ft_letters(s, c, i);
			while (s[i] != c && s[i + 1] != '\0')
				i++;
			d++;
		}
		i++;
	}
	return (ptr);
}
