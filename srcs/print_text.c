#include "../includes/ft_select.h"

void	print_text(t_environment *env)
{
	int row;
	int column;
	int current;

	row = 0;
	current = 0;
	while (row < env->height && row < env->argc)
	{
		ft_putstrfd(tgoto(tgetstr("cm", NULL), 0, row), 2);
		ft_putstrfd(tgetstr("ce", NULL), 2);
		column = 0;
		while (((current = (env->height * column) + row)) < env->argc)
		{
			if (env->high[current] == 'h')
				ft_putstrfd(tgetstr("so", NULL), 2);
			if (current == env->current)
				ft_putstrfd(tgetstr("us", NULL), 2);
			ft_putstrfd(env->argv[current], 2);
			if (current == env->current)
				ft_putstrfd(tgetstr("ue", NULL), 2);
			if (env->high[current] == 'h')
				ft_putstrfd(tgetstr("se", NULL), 2);
			ft_putcharnfd(' ', env->row_size - ft_strlen(env->argv[current]), 2);
			column++;
		}
		row++;
	}
}

void	set_window_size(t_environment *env)
{
	struct winsize window;

	ioctl(0, TIOCGWINSZ, &window);
	env->width = window.ws_col;
	env->height = window.ws_row;
}

int		size_check(t_environment *env)
{
	int column_count;

	column_count = env->argc / env->height + 1;
	return ((column_count * env->row_size) < env->width);
}

void	refresh_screen(int signum)
{
	t_environment	*env;

	(void)signum;
	env = store_retrieve_env(NULL);
	set_window_size(env);
	clear_it(env);
	if (size_check(env))
		print_text(env);
	else
		ft_putstrfd("No dice, dog.", 2);
}
