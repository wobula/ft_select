/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:57:23 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:38:39 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		reset_struct(t_print *all)
{
	all->spec = '0';
	ft_charset(all->flags, '|', 5);
	all->precision = -1;
	all->width = 0;
	if (all->length)
		ft_strdel(&all->length);
	all->ch = 'z';
}
