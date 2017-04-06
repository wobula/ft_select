#include "../includes/ft_select.h"

void	ft_putcharnfd(char c, size_t nbr, int fd)
{
	size_t x;

	x = 0;
	while (x < nbr)
	{
		write(fd, &c, 1);
		x++;
	}
}
