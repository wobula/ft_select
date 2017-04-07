/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:22:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/04/06 23:46:35 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

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
	int				row_size;
	char			*high;
	char			**argv;
	char			*terminal_name;
}					t_environment;

void				ft_putstrfd(char const *str, int fd);
void				ft_putcharnfd(char c, size_t nbr, int fd);
void				clear_it(t_environment *env);
void				print_text(t_environment *env);
void				wait_for_input(void);
t_environment		*store_retrieve_env(t_environment *new);
void				refresh_screen(int signum);
void				shutdown(t_environment *env);
void				ft_signals(t_environment *env);
void				instantiate_terminal(t_environment *env);
void				suspend_terminal(int signum);
void				highlight_return(t_environment *env);
void				highlight_text(t_environment *env);
void				move_up_down(t_environment *env, unsigned long keycode);
char				**recreate2d(char **old, int remove);
void				remove_element(t_environment *env);
int					get_row_size(char **str);

#endif
