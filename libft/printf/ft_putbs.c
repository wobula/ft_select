/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:46:29 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/08 17:28:52 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	zero(char *str)
{
	int d;

	d = 0;
	if (str[0] == 0)
	{
		ft_putchar('\0');
		d = 1;
	}
	return (d);
}

static int	increment(t_print *all, char *str, int i)
{
	if (str[i] == 0)
	{
		ft_putchar('\0');
		all->ret++;
		i++;
	}
	else
	{
		ft_putchar(str[i]);
		all->ret++;
		i++;
	}
	return (i);
}

void		ft_putbs(t_print *all, char *str)
{
	int c;

	c = 0;
	if (all->spec == 'c')
	{
		if (zero(str) > 0)
			return ;
		while (str[c] != '\0')
			c = increment(all, str, c);
	}
	else
	{
		while (str[c] != '\0')
		{
			ft_putchar(str[c]);
			c++;
			all->ret++;
		}
	}
}
