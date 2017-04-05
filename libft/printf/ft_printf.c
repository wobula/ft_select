/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:38:08 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/08 18:21:38 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int				ft_printf(const char *format, ...)
{
	t_print *all;
	int		ret;

	ret = 0;
	all = NULL;
	all = init(all);
	va_start(all->arg, format);
	parse(all, (char *)format);
	va_end(all->arg);
	ret = all->ret;
	all = init(all);
	return (ret);
}
