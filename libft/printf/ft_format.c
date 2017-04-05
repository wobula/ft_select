/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 19:01:02 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:23:41 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		format(t_print *all, char spec)
{
	if (spec == 's' || spec == '%' || spec == 'c')
		string(all);
	else if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'U' ||
		spec == 'D')
		decimal(all);
	else if (spec == 'S' || spec == 'C')
		w_string(all);
	else if (spec == 'X' || spec == 'x' || spec == 'p')
		hex(all);
	else if (spec == 'O' || spec == 'o')
		oct(all);
}
