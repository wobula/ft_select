/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <rschramm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:22:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/04/06 23:46:35 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int				get_row_size(char **str)
{
	size_t	largest;
	int		x;

	largest = 0;
	x = 0;
	while (str[x] != 0)
	{
		if (ft_strlen(str[x]) > largest)
			largest = ft_strlen(str[x]);
		x++;
	}
	return (largest);
}

void			clear_it(t_environment *env)
{
	int	x;

	x = 0;
	while (x < env->height)
	{
		ft_putstrfd(tgoto(tgetstr("cl", NULL), 0, x), 2);
		ft_putstrfd(tgetstr("ce", NULL), 2);
		x++;
	}
}

t_environment	*store_retrieve_env(t_environment *new)
{
	static t_environment	*storage = NULL;

	if (new)
		storage = new;
	return (storage);
}
