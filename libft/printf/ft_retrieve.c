/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:05:47 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:39:43 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	lower_c(t_print *all, va_list arg)
{
	all->raw = ft_strnew(1);
	all->raw[0] = va_arg(arg, int);
	if (all->raw[0] == 0)
		all->ret++;
}

static void	lower_s(t_print *all, va_list arg)
{
	all->raw = ft_strdup(va_arg(arg, char*));
	if (!all->raw)
		all->raw = ft_strdup("(null)\0");
}

void		retrieve(t_print *all, va_list arg, char c)
{
	if (all->raw)
		ft_strdel(&all->raw);
	if (c == 's')
		lower_s(all, arg);
	else if (c == '%')
		all->raw = ft_strdup("%\0");
	else if (c == 'c')
		lower_c(all, arg);
	else if (c == 'C')
		all->raw_w = ft_strwxnew((wchar_t)va_arg(arg, wchar_t), 1);
	else if (c == 'd' || c == 'i')
		get_int(all, arg);
	else if (c == 'u')
		get_uint(all, arg);
	else if (c == 'U' || c == 'D')
		get_luint(all, arg);
	else if (c == 'x' || c == 'X' || c == 'o' || c == 'O')
		get_hexoct(all, arg);
	else if (c == 'S')
		all->raw_w = (wchar_t *)ft_strwdup(va_arg(arg, wchar_t *));
	else if (c == 'p')
		all->raw = ft_strxjoin("0x\0",
				ft_itoabase(all, va_arg(arg, uintmax_t), 'x'), 2);
}
