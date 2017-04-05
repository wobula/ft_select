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
	clear_it(env);
	print_text(env);
}

void	move_up_down(t_environment *env, unsigned long keycode)
{
	if (keycode == KEY_UP)
		env->current++;
	else
		env->current--;
	if (env->current <= -1)
		env->current = env->argc;
	else if (env->current > env->argc - 1)
		env->current = 0;
	clear_it(env);
	print_text(env);
}

char	**recreate(char **old, int remove)
{
	char	**new;
	int		x;
	int		y;

	x = 0;
	while (old[x] != 0)
		x++;
	new = (char **)ft_memalloc(sizeof(char*) * (x - 1));
	new[x - 1] = 0;
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


void	remove_element(t_environment *env)
{
	char	**tmp2;

	env->argc--;
	if (env->argc < 0)
		env->argc = 0;
	tmp2 = ft_strdup2d(env->argv, 0);
	ft_strdel2d(env->argv);
	env->argv = recreate(tmp2, env->current);
	if (env->current > env->argc - 1)
		env->current--;
	ft_strdel2d(tmp2);
	ft_strdel(&env->high);
	env->high = ft_strxnew('0', env->argc);
	clear_it(env);
	print_text(env);
}

void	wait_for_input(t_environment *env)
{
	unsigned long	keycode;

	clear_it(env);
	print_text(env);
	while (keycode = 0, (read(0, &keycode, 6)) != 0)
	{
		if (keycode == KEY_ESCAPE || ((keycode == KEY_DELETE || keycode == KEY_BACKSPACE) && env->argc == 1))
			exit(0);
		else if (keycode == KEY_UP || keycode == KEY_DOWN)
			move_up_down(env, keycode);
		else if (keycode == KEY_SPACE)
			highlight_text(env);
		else if (keycode == KEY_ENTER)
			highlight_return(env);
		else if (keycode == KEY_DELETE || keycode == KEY_BACKSPACE)
			remove_element(env);
	}
}
