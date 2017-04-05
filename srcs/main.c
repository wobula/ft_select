#include "../includes/ft_select.h"
/*
static void	initiate_signals(void (*restart_function)(int))
{
	signal(SIGWINCH, refresh_screen);
	signal(SIGCONT, restart_function);
	signal(SIGTSTP, abort_no_exit);
	signal(SIGINT, shutdown);
	signal(SIGHUP, shutdown);
	signal(SIGTERM, shutdown);
	signal(SIGSEGV, shutdown);
	signal(SIGQUIT, shutdown);
	signal(SIGFPE, shutdown);
	signal(SIGALRM, shutdown);
	signal(SIGKILL, shutdown);
	signal(SIGABRT, shutdown);
	signal(SIGUSR1, shutdown);
	signal(SIGUSR2, shutdown);
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
	exit(1);
}

void	instantiate_terminal(t_environment *env)
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
		exit (1);
	ioctl(0, TIOCGWINSZ, &env->sz);
	env->width = env->sz.ws_col;
	env->height = env->sz.ws_row;
}
/*
static void	restart(int signum)
{
	t_environment *env;

	(void)signum;
	env = store_retrieve_env(NULL);
	instantiate_terminal(env);
	initiate_signals(&restart);
	print_screen(env);
}
*/
t_environment	*setup_env(int argc, char **argv)
{
	t_environment	*env;

	env = (t_environment *)ft_memalloc(sizeof(t_environment));
	env->argc = argc - 1;
	env->argv = ft_strdup2d(argv, 1);
	env->terminal_name = getenv("TERM");
	env->current = 0;
	env->high = ft_strxnew('0', env->argc);
	instantiate_terminal(env);
	return (env);
}

t_environment	*store_retrieve_env(t_environment *new)
{
	static t_environment	*storage = NULL;

	if (new)
		storage = new;
	return (storage);
}

int		main(int argc, char **argv)
{
	t_environment 	*env;
	int				x;

	x = 0;
	if (argc >= 2)
	{
		env = setup_env(argc, argv);
		store_retrieve_env(env);
		//initiate_signals(&restart);
		refresh_screen(env);
		wait_for_input();
	}
	else
		ft_putstr("Usage: ft_select [parameters]");
	return (0);
}
