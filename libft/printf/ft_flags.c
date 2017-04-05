/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:33:45 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/15 15:33:30 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	length(t_print *all, char *f)
{
	int c;

	c = 0;
	if (all->length)
		ft_strdel(&all->length);
	if (f[c] == 'h' && f[c + 1] == 'h' && (c = c + 2))
		all->length = ft_strdup("hh\0");
	else if (f[c] == 'h' && (c = c + 1))
		all->length = ft_strdup("h\0");
	else if (f[c] == 'l' && f[c + 1] == 'l' && (c = c + 2))
		all->length = ft_strdup("ll\0");
	else if (f[c] == 'l' && (c = c + 1))
		all->length = ft_strdup("l\0");
	else if (f[c] == 'z' && (c = c + 1))
		all->length = ft_strdup("z\0");
	else if (f[c] == 'j' && (c = c + 1))
		all->length = ft_strdup("j\0");
	return (c);
}

int	precision(t_print *all, char *f)
{
	int c;
	char*ptr;

	c = 1;
	all->precision = 0;
	if (f[c] >= '0' && f[c] <= '9')
	{
		while (f[c] >= '0' && f[c] <= '9')
			c++;
		ptr = ft_strnxdup(f, 1, c - 1);
		all->precision = ft_atoi(ptr);
		ft_strdel(&ptr);
	}
	if (f[c] == '*' && (c = c + 1))
		all->precision = va_arg(all->arg, int);
	return (c);
}

int	width(t_print *all, char *f)
{
	int c;
	char*ptr;

	c = 0;
	if (f[c] >= '1' && f[c] <= '9')
	{
		while (f[c] >= '0' && f[c] <= '9')
			c++;
		ptr = ft_strnxdup(f, 0, c);
		all->width = ft_atoi(ptr);
		ft_strdel(&ptr);
	}
	if (f[c] == '*' && (c = c + 1))
		all->width = va_arg(all->arg, int);
	return (c);
}

int	flags(t_print *all, char *f)
{
	int c;

	c = 0;
	if (f[c] == '-' || f[c] == '+' || f[c] == ' ' || f[c] == '0' ||
		f[c] == '#')
	{
		while (f[c] == '-' || f[c] == '+' || f[c] == ' ' || f[c] == '0' ||
			f[c] == '#')
		{
			all->flags[c] = f[c];
			c++;
		}
	}
	return (c);
}

int	specifier(t_print *all, char c)
{
	if ((c == 'c' || c == 'd' || c == 'i' || c == 'e' || c == 'E' || c == 'g'
		|| c == 'G' || c == 'o' || c == 's' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'n' || c == '%' || c == 'S' || c == 'D' || c == 'C'
		|| c == 'O' || c == 'U') && (all->spec = c))
		return (1);
	return (0);
}
