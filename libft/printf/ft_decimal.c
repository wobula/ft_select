/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:52:36 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/08 18:53:54 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	decimal(t_print *all)
{
	if (all->precision > -1)
		all = with_precision(all);
	else
	{
		if (ft_charfind(all->flags, '-') > -1)
			all = left_align(all);
		else
			all = right_align(all);
	}
}
