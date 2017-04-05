/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:21:05 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:28:24 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	w_string(t_print *all)
{
	int x;

	if (!all->raw_w)
		return ;
	x = (int)ft_strwlen(all->raw_w);
	if (all->precision != -1)
		all->raw_w = ft_strwxjoin(ft_strwsub(all->raw_w, 0,
			((size_t)all->precision)), L"\0", 1);
	x = ft_strwlen(all->raw_w);
	if (all->spec == 'C' && all->raw_w[0] == '\0' &&
			(all->raw_w = ft_strwxnew(L' ', all->width - 1)))
		return ;
	if (all->width > x && (ft_charfind(all->flags, L'-') > -1))
		all->raw_w =
			ft_strwxjoin(all->raw_w, ft_strwxnew(L' ', all->width - x), 3);
	else if (all->width > x)
		all->raw_w =
			ft_strwxjoin(ft_strwxnew(L' ', all->width - x), all->raw_w, 3);
}

void	string(t_print *all)
{
	int x;

	if (!all->raw)
		all->raw = ft_strnew(0);
	x = (int)ft_strlen(all->raw);
	if (all->precision != -1 && all->spec == '%')
		all->raw = ft_strxjoin(ft_strsub(all->raw, 0,
			((size_t)all->precision)), "%\0", 1);
	else if (all->precision != -1)
		all->raw = ft_strxjoin(ft_strsub(all->raw, 0,
			((size_t)all->precision)), "\0", 1);
	x = ft_strlen(all->raw);
	if (all->spec == 'c' && all->raw[0] == '\0' && (all->raw =
			ft_strxnew(' ', all->width - 1)))
		return ;
	if (all->width > x && (ft_charfind(all->flags, '-') > -1))
		all->raw = ft_strxjoin(all->raw, ft_strxnew(' ', all->width - x), 3);
	else if (all->width > x)
		all->raw = ft_strxjoin(ft_strxnew(' ', all->width - x), all->raw, 3);
}

t_print	*with_precision(t_print *all)
{
	all->x = ft_strlen(all->raw);
	if (all->precision > all->x && (all->pad = all->precision - all->x))
		all->raw = ft_strxjoin(ft_strxnew('0', all->pad), all->raw, 3);
	else if (all->precision == 0 && all->raw_i == 0)
	{
		ft_strdel(&all->raw);
		all->raw = ft_strnew(1);
	}
	if (all->sign == '-' || ft_charfind(all->flags, '+') > -1)
		all->raw = ft_strxjoin(ft_strxnew(all->sign, 1), all->raw, 3);
	else if ((ft_charfind(all->flags, ' ') > -1))
		all->raw = ft_strxjoin(ft_strxnew(' ', 1), all->raw, 3);
	all->x = ft_strlen(all->raw);
	if (all->width > all->x)
	{
		if ((ft_charfind(all->flags, '-') == -1))
			all->raw =
				ft_strxjoin(ft_strxnew(' ', all->width - all->x), all->raw, 3);
		else
			all->raw =
				ft_strxjoin(all->raw, ft_strxnew(' ', all->width - all->x), 3);
	}
	return (all);
}

t_print	*left_align(t_print *all)
{
	if (ft_charfind(all->flags, '+') > -1 || all->sign == '-')
		all->raw = ft_strxjoin(ft_strxnew(all->sign, 1), all->raw, 3);
	else if (ft_charfind(all->flags, ' ') > -1)
		all->raw = ft_strxjoin(ft_strxnew(' ', 1), all->raw, 3);
	all->x = ft_strlen(all->raw);
	all->pad = all->width - all->x;
	if (all->pad > 0)
		all->raw = ft_strxjoin(all->raw, ft_strxnew(' ', all->pad), 3);
	return (all);
}
