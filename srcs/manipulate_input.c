/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:22:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/04/06 23:46:35 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	highlight_return(t_environment *env)
{
	int x;
	int pad;

	pad = 0;
	x = 0;
	clear_it(env);
	while (x < env->argc)
	{
		if (env->high[x] == 'h')
		{
			if (pad > 0)
				ft_putchar(' ');
			ft_putstr(env->argv[x]);
			pad = 1;
		}
		x++;
	}
	shutdown(env);
	exit(0);
}

void	highlight_text(t_environment *env)
{
	if (env->high[env->current] == 'h')
		env->high[env->current] = 0;
	else
		env->high[env->current] = 'h';
	env->current++;
	if (env->current >= env->argc)
		env->current = 0;
}

void	move_up_down(t_environment *env, unsigned long keycode)
{
	if (keycode == KEY_UP)
		env->current++;
	else
		env->current--;
	if (env->current < 0)
		env->current = env->argc - 1;
	else if (env->current > env->argc - 1)
		env->current = 0;
}