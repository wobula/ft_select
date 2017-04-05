/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:49:44 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:32:12 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_print	*init(t_print *all)
{
	if (!all)
	{
		all = (t_print *)ft_memalloc(sizeof(t_print));
		all->spec = '0';
		all->flags = ft_strnew(5);
		all->precision = -1;
		all->width = 0;
		all->length = NULL;
		all->ch = '|';
	}
	else if (all)
	{
		if (all->flags)
			ft_strdel(&all->flags);
		if (all->length)
			ft_strdel(&all->length);
		if (all->raw)
			ft_strdel(&all->raw);
		ft_memdel((void *)&all);
	}
	return (all);
}
