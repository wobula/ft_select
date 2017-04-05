/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_align.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:15:44 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:43:33 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_print	*first(t_print *all)
{
	if ((ft_charfind(all->flags, '+') > -1 || all->sign == '-') && all->pad--)
	{
		all->raw = ft_strxjoin(ft_strxnew('0', all->pad), all->raw, 3);
		all->raw = ft_strxjoin(ft_strxnew(all->sign, 1), all->raw, 3);
	}
	else if ((ft_charfind(all->flags, ' ')) > -1 && (all->pad--))
	{
		all->raw = ft_strxjoin(ft_strxnew('0', all->pad), all->raw, 3);
		all->raw = ft_strxjoin(ft_strxnew(' ', 1), all->raw, 3);
	}
	else
		all->raw = ft_strxjoin(ft_strxnew('0', all->pad), all->raw, 3);
	return (all);
}

t_print			*right_align(t_print *all)
{
	all->x = ft_strlen(all->raw);
	all->pad = all->width - all->x;
	if ((ft_charfind(all->flags, '0')) > -1 && all->pad > 0)
		all = first(all);
	else if ((ft_charfind(all->flags, ' ')) > -1 && all->pad > 0)
	{
		if ((ft_charfind(all->flags, '+') > -1 || all->sign == '-') &&
				(all->pad--))
			all->raw = ft_strxjoin(ft_strxnew(all->sign, 1), all->raw, 3);
		all->raw = ft_strxjoin(ft_strxnew(' ', all->pad), all->raw, 3);
	}
	else
	{
		if ((ft_charfind(all->flags, '+') > -1 || all->sign == '-') &&
				(all->pad--))
			all->raw = ft_strxjoin(ft_strxnew(all->sign, 1), all->raw, 3);
		if (ft_charfind(all->flags, ' ') > -1 && ft_charfind(all->flags, '+')
				== -1 && (all->pad--) && all->sign == '+')
			all->raw = ft_strxjoin(ft_strxnew(' ', 1), all->raw, 3);
		if (all->pad > 0)
			all->raw = ft_strxjoin(ft_strxnew(' ', all->pad), all->raw, 3);
	}
	return (all);
}
