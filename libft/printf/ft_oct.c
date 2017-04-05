/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 09:54:30 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:36:32 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	norm(t_print *all, char c)
{
	if (all->precision < 0 && all->raw_x == 0 &&
		ft_charfind(all->flags, '#') > -1)
	{
		ft_strdel(&all->raw);
		all->raw = ft_strnew(1);
	}
	if (ft_charfind(all->flags, '#') > -1)
		all->raw = ft_strxjoin(ft_strxnew('0', 1), all->raw, 3);
	all->x = ft_strlen(all->raw);
	all->pad = all->width - all->x;
	if (all->pad > 0 && ft_charfind(all->flags, '-') == -1)
		all->raw = ft_strxjoin(ft_strxnew(c, all->pad), all->raw, 3);
	else if (all->pad > 0)
		all->raw = ft_strxjoin(all->raw, ft_strxnew(c, all->pad), 3);
}

static int	second(t_print *all, char c)
{
	if (c == '0')
	{
		all->x = ft_strlen(all->raw);
		all->pad = all->width - all->x;
		if (ft_charfind(all->flags, '#') > -1)
			all->pad = all->pad - 1;
		if (all->pad > 0)
			all->raw = ft_strxjoin(ft_strxnew(c, all->pad), all->raw, 3);
	}
	else if (c == ' ' && ft_charfind(all->flags, '#') > -1 && all->raw_x != 0)
	{
		if (all->spec == 'o' && (all->raw = ft_strxjoin("0\0", all->raw, 2)))
		{
			all->x = ft_strlen(all->raw);
			all->pad = all->width - all->x;
			if (all->pad > 0 && ft_charfind(all->flags, '-') == -1)
				all->raw = ft_strxjoin(ft_strxnew(c, all->pad), all->raw, 3);
			else if (all->pad > 0)
				all->raw = ft_strxjoin(all->raw, ft_strxnew(c, all->pad), 3);
			return (1);
		}
	}
	else
		norm(all, c);
	return (0);
}

static int	size(t_print *all, char c)
{
	if (ft_charfind(all->flags, '#') > -1 && (all->pad = all->pad - 1))
		all->raw = ft_strxjoin("0\0", all->raw, 2);
	if (all->pad > 0 && ft_charfind(all->flags, '-') > -1)
		all->raw = ft_strxjoin(all->raw, ft_strxnew(c, all->pad), 3);
	else if (all->pad > 0)
		all->raw = ft_strxjoin(ft_strxnew(c, all->pad), all->raw, 3);
	return (1);
}

void		oct(t_print *all)
{
	char c;

	if (ft_charfind(all->flags, '0') > -1 && ft_charfind(all->flags, '-') == -1)
		c = '0';
	else
		c = ' ';
	all->x = ft_strlen(all->raw);
	all->pad = all->precision - all->x;
	if (all->pad > 0)
		all->raw = ft_strxjoin(ft_strxnew('0', all->pad), all->raw, 3);
	all->x = ft_strlen(all->raw);
	all->pad = all->width - all->x;
	if (all->raw_i == 0 && all->precision == 0)
	{
		ft_strdel(&all->raw);
		all->raw = ft_strnew(1);
	}
	all->pad = all->width - ft_strlen(all->raw);
	if (all->pad > 0 && (size(all, c)))
		return ;
	else if (second(all, c) == 1)
		return ;
	if (ft_charfind(all->flags, '#') > -1 && all->raw_x != 0)
		all->raw = ft_strxjoin("0\0", all->raw, 2);
}
