/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 00:17:11 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:32:50 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			get_base(char c)
{
	int base;

	base = 0;
	if (c == 'o' || c == 'O')
		base = 8;
	else if (c == 'x' || c == 'X')
		base = 16;
	return (base);
}

char		*ft_itoabase(t_print *all, intmax_t nbr, char c)
{
	char	buff[32];
	int		i;
	int		base;

	i = 30;
	base = get_base(c);
	if (nbr == 0)
		return (ft_strxnew('0', 1));
	else if (nbr < 0 && (all->sign = -1))
		nbr = nbr * -1;
	while (nbr > 0 && i > 0)
	{
		if (c == 'o' || c == 'x')
			buff[i] = "0123456789abcdef"[nbr % base];
		else if (c == 'O' || c == 'X')
			buff[i] = "0123456789ABCDEF"[nbr % base];
		nbr = nbr / base;
		--i;
	}
	buff[i] = '\0';
	return (ft_strdup(buff + i + 1));
}
