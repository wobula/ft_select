/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_found.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:20:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:37:49 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	percent_found(t_print *all, char *f)
{
	int skip;

	skip = (gather_flags(all, f)) + 2;
	retrieve(all, all->arg, all->spec);
	format(all, all->spec);
	return (skip);
}
