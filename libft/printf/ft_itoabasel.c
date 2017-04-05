/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:34:16 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/09 10:33:33 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_base(char c)
{
	int		base;

	base = 0;
	if (c == 'o' || c == 'O')
		base = 8;
	else if (c == 'x' || c == 'X')
		base = 16;
	return (base);
}

char		*ft_itoabasel(intmax_t nbr, char c)
{
	char		buff[32];
	int			i;
	int			base;
	uintmax_t	test;

	i = 30;
	test = 0;
	base = get_base(c);
	if (nbr == 0)
		return (ft_strxnew('0', 1));
	else
		test = nbr;
	while (test > 0 && i > 0)
	{
		if (c == 'o' || c == 'x')
			buff[i] = "0123456789abcdef"[test % base];
		else if (c == 'O' || c == 'X')
			buff[i] = "0123456789ABCDEF"[test % base];
		test = test / base;
		--i;
	}
	return (ft_strdup(buff + i + 1));
}
