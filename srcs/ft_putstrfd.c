#include "../includes/ft_select.h"

void		ft_putstrfd(char const *str, int fd)
{
	write (fd, str, ft_strlen(str));
}
