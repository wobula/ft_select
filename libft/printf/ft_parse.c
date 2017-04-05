/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 10:14:21 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/10 20:14:03 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		do_it_now(t_print *all)
{
	if (all->raw && all->ch != '\0' && all->spec != 'c')
		all->ret = all->ret + ft_strlen(all->raw);
	else if (all->raw && all->ch == '\0' && all->spec != 'c')
		all->ret = all->ret + ft_strlen(all->raw) + 1;
	else if (all->spec == 'S' || all->spec == 'C')
		all->ret = all->ret + ft_strwlen(all->raw_w);
	else if (all->spec == 's' && !all->raw)
		all->ret = all->ret + 6;
	if (all->spec == 'S' || all->spec == 'C')
		ft_putwstr(all->raw_w);
	else if (all->spec == 'c')
		ft_putbs(all, all->raw);
	else
		ft_putstr(all->raw);
	reset_struct(all);
}

void		parse(t_print *all, char *f)
{
	int c;

	c = 0;
	while (f[c] != '\0')
	{
		if ((f[c] == '[' && f[c + 1] == '.') ||
			(f[c] == '.' && f[c + 1] == ']'))
		{
			c = ft_colors(f + c, c);
			continue ;
		}
		if (f[c] == '%')
		{
			c = (percent_found(all, f + c + 1) + c);
			do_it_now(all);
		}
		else
		{
			ft_putchar(f[c]);
			all->ret++;
			c++;
		}
	}
}
