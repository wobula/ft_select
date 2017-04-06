/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:22:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/04/06 23:46:35 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strdup2d(char **str2d, int start)
{
	char	**new;
	int		x;
	int		y;

	x = start;
	y = 0;
	while (str2d[x] != 0 && (y = y + 1))
		x++;
	new = (char **)ft_memalloc(sizeof(char*) * (y));
	new[y] = 0;
	x = start;
	y = 0;
	while (str2d[x])
	{
		new[y] = ft_strdup(str2d[x]);
		x++;
		y++;
	}
	return (new);
}
