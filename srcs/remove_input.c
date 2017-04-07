/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:22:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/04/06 23:46:35 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

char	**recreate(char **old, int remove)
{
	char	**new;
	int		x;
	int		y;

	x = 0;
	while (old[x] != 0)
		x++;
	x = x - 1;
	new = (char **)ft_memalloc(sizeof(char*) * (x));
	new[x] = 0;
	x = 0;
	y = 0;
	while (old[x] != 0)
	{
		if (x != remove)
		{
			new[y] = ft_strdup(old[x]);
			y++;
		}
		x++;
	}
	ft_strdel2d(old);
	return (new);
}

char	*refresh_high(t_environment *env)
{
	char	*new;
	int		x;
	int		y;

	new = ft_strnew(env->argc);
	x = 0;
	y = 0;
	while (env->high[x] != '\0')
	{
		if (x != env->current)
		{
			new[y] = env->high[x];
			y++;
		}
		x++;
	}
	ft_strdel(&env->high);
	return (new);
}

void	remove_element(t_environment *env)
{
	char	**tmp2;

	env->argc--;
	tmp2 = ft_strdup2d(env->argv, 0);
	ft_strdel2d(env->argv);
	free(env->argv);
	env->argv = NULL;
	env->argv = recreate(tmp2, env->current);
	if (env->current > env->argc - 1)
		env->current--;
	ft_strdel2d(tmp2);
	free(tmp2);
	tmp2 = NULL;
	env->high = refresh_high(env);
}
