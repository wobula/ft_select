/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:21:43 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:31:45 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	last(t_print *all)
{
	if (all->spec == 'X' && all->raw_x != 0)
		all->raw = ft_strxjoin("0X\0", all->raw, 2);
	else if (all->spec == 'x' && all->raw_x != 0)
		all->raw = ft_strxjoin("0x\0", all->raw, 2);
}

static void	join(t_print *all, char c)
{
	all->x = ft_strlen(all->raw);
	all->pad = all->width - all->x;
	all->raw = ft_strxjoin(ft_strxnew(c, all->pad), all->raw, 3);
}

static void	one(t_print *all, char c)
{
	if (c == '0')
	{
		if (ft_charfind(all->flags, '#') > -1)
			all->pad = all->pad - 2;
		all->raw = ft_strxjoin(ft_strxnew(c, all->pad), all->raw, 3);
	}
	else if (c == ' ' && ft_charfind(all->flags, '#') > -1 && all->raw_x != 0)
	{
		if (all->spec == 'X' && (all->raw = ft_strxjoin("0X\0", all->raw, 2)))
			join(all, c);
		else if (all->spec == 'x' && (all->raw =
				ft_strxjoin("0x\0", all->raw, 2)))
			join(all, c);
		return ;
	}
	else
	{
		if (all->raw_x == 0 || (ft_charfind(all->flags, '#') > -1))
			all->pad = all->pad + 1;
		all->raw = ft_strxjoin(ft_strxnew(c, all->pad), all->raw, 3);
	}
	if (ft_charfind(all->flags, '#') > -1)
		all->raw = ft_strxjoin("0x\0", all->raw, 2);
}

static void	big(t_print *all, char c)
{
	if (ft_charfind(all->flags, '-') > -1)
	{
		if (ft_charfind(all->flags, '#') > -1)
		{
			all->raw = ft_strxjoin("0x\0", all->raw, 2);
			all->pad = all->pad - 2;
		}
		all->raw = ft_strxjoin(all->raw, ft_strxnew(c, all->pad), 3);
	}
	else
		one(all, c);
}

void		hex(t_print *all)
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
		all->raw = ft_strnew(0);
	}
	if (all->pad > 0)
	{
		big(all, c);
		return ;
	}
	if (ft_charfind(all->flags, '#') > -1)
		last(all);
}
