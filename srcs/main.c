#include "../includes/ft_select.h"

/*
static void	initiate_sig(void (*restart_function)(int))
{
	signal(SIGWINCH, refresh_screen);
	signal(SIGCONT, restart_function);
	signal(SIGTSTP, abort_no_exit);
	signal(SIGINT, abort_exit);
	signal(SIGHUP, abort_exit);
	signal(SIGTERM, abort_exit);
	signal(SIGSEGV, abort_exit);
	signal(SIGQUIT, abort_exit);
	signal(SIGFPE, abort_exit);
	signal(SIGALRM, abort_exit);
	signal(SIGKILL, abort_exit);
	signal(SIGABRT, abort_exit);
	signal(SIGUSR1, abort_exit);
	signal(SIGUSR2, abort_exit);
}
*/

void		clear_it(t_environment *env)
{
	int	x;

	x = 0;
	while (x < env->height)
	{
		ft_putstrfd(tgoto(tgetstr("cm", NULL), 0, x), 2);
		ft_putstrfd(tgetstr("ce", NULL), 2);
		x++;
	}
}

void		shutdown(t_environment *env)
{
	int x;

	x = 0;
	while (env->argv[x] != 0)
	{
		ft_strdel(&env->argv[x]);
		x++;
	}
	ft_strdel(&env->high);
	ft_memdel((void*)&env);
}

t_environment *instantiate_terminal(int argc, char **argv)
{
	t_environment	*env;

	env = (t_environment *)ft_memalloc(sizeof(t_environment));
	env->argc = argc - 1;
	env->argv = ft_strdup2d(argv, 1);
	env->terminal_name = getenv("TERM");
	env->current = 0;
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
		exit (1);
	ioctl(0, TIOCGWINSZ, &env->sz);
	env->width = env->sz.ws_col;
	env->height = env->sz.ws_row;
	env->high = ft_strxnew('0', env->argc);
	return (env);
}

int		main(int argc, char **argv)
{
	t_environment 	*env;
	int				x;

	x = 0;
	if (argc >= 2)
	{
		env = instantiate_terminal(argc, argv);
		wait_for_input(env);
		shutdown(env);
	}
	else
		ft_putstr("Usage: ft_select [parameters]");
	return (0);
}
