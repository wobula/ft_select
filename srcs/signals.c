#include "../includes/ft_select.h"

static void		sig_tstp(int sig)
{
	t_environment *env;

	if (!isatty(1))
		return ;
	if (sig == SIGTSTP)
	{
		suspend_terminal(0);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, "\032");
	}
	else if (sig == SIGCONT)
	{
		env = store_retrieve_env(NULL);
		instantiate_terminal(env);
		ft_signals(env);
		refresh_screen(0);
	}
	else if (sig == SIGWINCH)
		refresh_screen(0);
}

static void		sig_handler(int sig)
{
	t_environment *env;

	env = store_retrieve_env(NULL);
	if (sig == SIGWINCH)
	{
		refresh_screen(0);
	}
	else
	{
		ft_putstr("weirdness");
		exit(1);
	}
}

void			ft_signals(t_environment *env)
{
	int				i;

	store_retrieve_env(env);
	i = -1;
	while (++i < 32)
		if (i == SIGTSTP || i == SIGCONT)
			signal(i, &sig_tstp);
		else if (i != SIGKILL && i != SIGSTOP
			&& i != SIGCHLD && i != SIGURG && i != SIGIO)
			signal(i, &sig_handler);
}
