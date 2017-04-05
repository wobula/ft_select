#include "../includes/ft_select.h"

void	print_text(t_environment *env)
{
	int x;

	x = 0;
	while (env->argv[x])
	{
		if (env->high[x] == 'h')
			ft_putstrfd(tgetstr("so", NULL), 2);
		if (x == env->current)
			ft_putstrfd(tgetstr("us", NULL), 2);
		ft_putstrfd(env->argv[x], 2);
		ft_putstrfd("\n", 2);
		if (x == env->current)
			ft_putstrfd(tgetstr("ue", NULL), 2);
		if (env->high[x] == 'h')
			ft_putstrfd(tgetstr("se", NULL), 2);
		x++;
	}
}

void	refresh_screen(t_environment *env)
{
	clear_it(env);
	print_text(env);
}
