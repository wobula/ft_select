/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gather_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:09:20 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/15 15:32:55 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		gather_flags(t_print *all, char *f)
{
	int c;
	int skip;

	c = 0;
	skip = 0;
	while (!specifier(all, f[c]) && f[c] != '\0')
	{
		if ((skip = length(all, f + c)))
			c = c + skip - 1;
		else if (f[c] == '.' && (skip = precision(all, f + c)))
			c = c + skip - 1;
		else if ((skip = width(all, f + c)))
			c = c + skip - 1;
		else if ((skip = flags(all, f + c)))
			c = c + skip - 1;
		c++;
	}
	return (c);
}
