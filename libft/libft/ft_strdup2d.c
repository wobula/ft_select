#include "../includes/libft.h"

char	**ft_strdup2d(char **str2d, int start)
{
	char	**new;
	int		x;
	int		y;

	x = start;
	y = 0;
	while (str2d[x] != 0 && (y = y + 1))
		x++;
	new = (char **)ft_memalloc(sizeof(char*) * (y + 1));
	new[y] = 0;
	x = start;
	y = 0;
	while (str2d[x])
	{
		new[y] = ft_strdup(str2d[x]);
		x++;
		y++;
	}
	return (new);
}
