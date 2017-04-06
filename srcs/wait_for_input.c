/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:22:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/04/06 23:46:35 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	key_functions(t_environment *env, unsigned long keycode)
{
	int refresh;

	refresh = 1;
	if (keycode == KEY_ESCAPE || ((keycode == KEY_DELETE || keycode ==
		KEY_BACKSPACE) && env->argc == 1))
		shutdown(env);
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
		move_up_down(env, keycode);
	else if (keycode == KEY_SPACE)
		highlight_text(env);
	else if (keycode == KEY_ENTER)
		highlight_return(env);
	else if (keycode == KEY_DELETE || keycode == KEY_BACKSPACE)
		remove_element(env);
	else
		refresh = 0;
	if (refresh)
		refresh_screen(0);
}

void	wait_for_input(void)
{
	unsigned long	keycode;
	t_environment	*env;

	env = store_retrieve_env(NULL);
	while (1)
	{
		keycode = 0;
		if ((read(0, &keycode, 6)) != 0)
			key_functions(env, keycode);
	}
}
