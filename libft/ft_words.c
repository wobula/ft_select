/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:52:20 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:25:28 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_words(char const *str, char c)
{
	int i;
	int word_c;
	char**ptr;

	i = 0;
	word_c = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word_c++;
			while (str[i] != c && str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	ptr = (char **)malloc((sizeof(*ptr) * word_c) + 1);
	if (!ptr)
		return (NULL);
	ptr[word_c] = NULL;
	return (ptr);
}
