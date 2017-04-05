/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:15:30 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:30:10 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		get_hexoct(t_print *all, va_list arg)
{
	if (!all->length && (all->spec == 'o' || all->spec == 'O' ||
		all->spec == 'x' || all->spec == 'X'))
		all->raw_x = va_arg(arg, unsigned int);
	else if (!all->length)
		all->raw_x = va_arg(arg, int);
	else if (all->length[0] == 'l' && all->length[1] == 'l')
		all->raw_x = va_arg(arg, unsigned long long);
	else if (all->length[0] == 'l')
		all->raw_x = va_arg(arg, unsigned long);
	else if (all->length[0] == 'h')
		all->raw_x = (unsigned short)va_arg(arg, uintmax_t);
	else if (all->length[0] == 'j')
		all->raw_x = va_arg(arg, uintmax_t);
	else if (all->length[0] == 'z')
		all->raw_x = va_arg(arg, size_t);
	all->sign = '+';
	all->raw = ft_itoabasel(all->raw_x, all->spec);
}

void		get_int(t_print *all, va_list arg)
{
	if (!all->length)
		all->raw_i = va_arg(arg, int);
	else if (all->length[0] == 'l' && all->length[1] == 'l')
		all->raw_i = va_arg(arg, intmax_t);
	else if (all->length[0] == 'l')
		all->raw_i = (long)va_arg(arg, intmax_t);
	else if (all->length[0] == 'h' && all->length[1] == 'h')
		all->raw_i = (char)va_arg(arg, size_t);
	else if (all->length[0] == 'h')
		all->raw_i = (short)va_arg(arg, intmax_t);
	else if (all->length[0] == 'j')
		all->raw_i = va_arg(arg, intmax_t);
	else if (all->length[0] == 'z')
		all->raw_i = va_arg(arg, size_t);
	if (all->spec == 'd' || all->spec == 'i' || all->spec == 'u' ||
			all->spec == 'D')
		all->raw = ft_itoa(all, all->raw_i);
}

void		get_uint(t_print *all, va_list arg)
{
	intmax_t x;

	x = 0;
	if (!all->length)
		all->raw_x = va_arg(arg, unsigned int);
	else if (all->length[0] == 'h' && all->length[1] == 'h')
		all->raw_x = (unsigned char)va_arg(arg, unsigned int);
	else if (all->length[0] == 'h')
		all->raw_x = va_arg(arg, unsigned int);
	else if (all->length[0] == 'l' && all->length[1] == 'l')
		all->raw_x = va_arg(arg, unsigned long long);
	else if (all->length[0] == 'l')
		all->raw_x = va_arg(arg, unsigned long);
	else if (all->length[0] == 'j')
		all->raw_x = va_arg(arg, uintmax_t);
	else if (all->length[0] == 'z')
		all->raw_x = va_arg(arg, size_t);
	all->raw = ft_itoau(all->raw_x);
}

void		get_luint(t_print *all, va_list arg)
{
	if (!all->length)
		all->raw_x = va_arg(arg, uintmax_t);
	else if (all->length[0] == 'l' && all->length[1] == 'l')
		all->raw_x = va_arg(arg, unsigned long long);
	else if (all->length[0] == 'l')
		all->raw_x = va_arg(arg, unsigned long);
	else if (all->length[0] == 'h')
		all->raw_x = va_arg(arg, size_t);
	else if (all->length[0] == 'j')
		all->raw_x = va_arg(arg, uintmax_t);
	else if (all->length[0] == 'z')
		all->raw_x = va_arg(arg, size_t);
	all->raw = ft_itoau(all->raw_x);
}
