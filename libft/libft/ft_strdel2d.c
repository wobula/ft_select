#include "../includes/libft.h"

void	ft_strdel2d(char **str)
{
	int x;

	x = 0;
	while (str[x] != 0)
	{
		ft_strdel(&str[x]);
		x++;
	}
	ft_memdel((void*)str);
}
