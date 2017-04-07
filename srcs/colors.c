/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:22:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/04/06 23:46:35 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

char	*ft_color_set(char *src)
{
	char	*ptr;

	ptr = NULL;
	if (ft_strcmp(src, "red\0") == 0)
		ptr = ft_strxdup("31\0", 0);
	else if (ft_strcmp(src, "green\0") == 0)
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
		ptr = ft_strxdup("96\0", 0);
	else if (!ft_strcmp(src, "normal\0"))
		ptr = ft_strxdup("39\0", 0);
	return (ptr);
}

void	ft_colorsfd(char *color, int fd)
{
	char	*ptr;

	if (color)
	{
		ptr = ft_color_set(color);
		ft_putstrfd("\e[", fd);
		ft_putstrfd(ptr, fd);
		ft_putstrfd("m", fd);
		ft_strdel(&ptr);
	}
	else
		ft_putstrfd("\e[39m", fd);
}

void	color_check(t_environment *env, int current)
{
	struct stat sb;
	char		*ptr;
	char		*ptr2;

	ptr = NULL;
	ptr2 = NULL;
	lstat(env->argv[current], &sb);
	if (S_ISDIR(sb.st_mode) == 1)
		ptr2 = ft_strdup("cyan");
	else if (sb.st_mode & S_IXUSR)
		ptr2 = ft_strdup("red");
	else if (S_ISLNK(sb.st_mode) == 1)
		ptr2 = ft_strdup("cyan");
	else if (S_ISREG(sb.st_mode) == 1)
		ptr2 = ft_strdup("green");
	if (ptr2)
		ft_colorsfd(ptr2, 2);
	else if (ptr)
		ft_colorsfd(ptr, 2);
	else
		ft_colorsfd("normal", 2);
	if (ptr2)
		ft_strdel(&ptr2);
	if (ptr)
		ft_strdel(&ptr);
}
