/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:12:28 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/10 21:56:54 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_color_check(char *src)
{
	char	*ptr;

	ptr = NULL;
	if (!ft_strcmp(src, "red\0"))
		ptr = ft_strxdup("31\0", 0);
	else if (!ft_strcmp(src, "green\0"))
		ptr = ft_strxdup("32\0", 0);
	else if (!ft_strcmp(src, "yellow\0"))
		ptr = ft_strxdup("33\0", 0);
	else if (!ft_strcmp(src, "blue\0"))
		ptr = ft_strxdup("34\0", 0);
	else if (!ft_strcmp(src, "white\0"))
		ptr = ft_strxdup("97\0", 0);
	else if (!ft_strcmp(src, "black\0"))
		ptr = ft_strxdup("30\0", 0);
	else if (!ft_strcmp(src, "cyan\0"))
		ptr = ft_strxdup("36\0", 0);
	else if (!ft_strcmp(src, "magenta\0"))
		ptr = ft_strxdup("35\0", 0);
	ft_strdel(&src);
	return (ptr);
}

static int	start(char *f, int c)
{
	char	*ptr;
	int		x;

	x = 2;
	while (f[x] != '.')
		x++;
	ptr = ft_strsub(f, 2, x - 2);
	ptr = ft_strxdup(ft_color_check(ptr), 1);
	ft_putstr("\e[");
	ft_putstr(ptr);
	ft_putchar('m');
	c += x + 1;
	ft_strdel(&ptr);
	return (c);
}

static int	finish(int c)
{
	ft_putstr("\e[0m");
	c += 2;
	return (c);
}

int			ft_colors(char *f, int c)
{
	if (f[0] == '[')
		c = start(f, c);
	else
		c = finish(c);
	return (c);
}
