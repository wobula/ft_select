/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:22:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/04/06 23:46:35 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void			shutdown(t_environment *env)
{
	int x;

	x = 0;
	while (env->argv[x] != 0)
	{
		ft_strdel(&env->argv[x]);
		x++;
	}
	ft_strdel(&env->argv[x]);
	free(env->argv);
	env->argv = NULL;
	ft_strdel(&env->high);
	env->term.c_lflag |= ICANON;
	env->term.c_lflag |= ECHO;
	ft_putstrfd(tgetstr("me", NULL), 2);
	ft_putstrfd(tgetstr("ve", NULL), 2);
	tcsetattr(0, 0, &env->term);
	ft_memdel((void*)&env);
	exit(1);
}

void			suspend_terminal(int signum)
{
	t_environment	*env;
	char			copy[2];

	(void)signum;
	env = store_retrieve_env(NULL);
	clear_it(env);
	env->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(0, 0, &(env->term));
	ft_putstrfd(tgetstr("te", NULL), 2);
	ft_putstrfd(tgetstr("ve", NULL), 2);
	if (signum == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		copy[0] = env->term.c_cc[VSUSP];
		copy[1] = 0;
		ioctl(0, TIOCSTI, copy);
	}
}

void			instantiate_terminal(t_environment *env)
{
	if (tgetent(NULL, env->terminal_name) <= 0)
	{
		ft_putstr("Error getting term, Motherfucka");
		exit(1);
	}
	tcgetattr(0, &env->term);
	env->term.c_lflag &= ~(ICANON);
	env->term.c_lflag &= ~(ECHO);
	env->term.c_cc[VMIN] = 1;
	env->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &env->term) == -1)
		exit(1);
	ioctl(0, TIOCGWINSZ, &env->sz);
	env->width = env->sz.ws_col;
	env->height = env->sz.ws_row;
	ft_putstr_fd(tgetstr("ti", NULL), 2);
	ft_putstr_fd(tgetstr("vi", NULL), 2);
}

t_environment	*setup_env(int argc, char **argv)
{
	t_environment	*env;

	env = (t_environment *)ft_memalloc(sizeof(t_environment));
	env->argc = argc - 1;
	env->argv = ft_strdup2d(argv, 1);
	env->terminal_name = getenv("TERM");
	env->current = 0;
	env->row_size = get_row_size(env->argv) + 1;
	env->high = ft_strxnew('0', env->argc);
	instantiate_terminal(env);
	return (env);
}

int				main(int argc, char **argv)
{
	t_environment	*env;
	int				x;

	x = 0;
	if (argc >= 2)
	{
		env = setup_env(argc, argv);
		store_retrieve_env(env);
		ft_signals(env);
		refresh_screen(0);
		wait_for_input();
	}
	else
		ft_putstr("Usage: ft_select [parameters]");
	return (0);
}
