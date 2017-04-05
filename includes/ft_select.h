#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>

# define KEY_ESCAPE 0x1B
# define KEY_SPACE 0x20
# define KEY_DOWN 0x415B1B
# define KEY_UP 0x425B1B
# define KEY_RIGHT 0x435B1B
# define KEY_LEFT 0x445B1B
# define KEY_ENTER 0xA
# define KEY_BACKSPACE 0x7F
# define KEY_DELETE 0x7E335B1B

typedef struct		s_environment
{
	struct termios	term;
	struct winsize	sz;
	int				argc;
	int				current;
	int				height;
	int				width;
	char			*high;
	char			**argv;
	char			*terminal_name;
}					t_environment;

void				ft_putstrfd(char const *str, int fd);
void				clear_it(t_environment *env);
void				print_text(t_environment *env);
void				wait_for_input(t_environment *env);
void				shutdown(t_environment *env);

#endif
