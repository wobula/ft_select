/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:50:43 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/19 17:16:09 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include "../includes/libft.h"

int		main(int argc, char **argv)
{
	int c;
	int b;

	argc = 0;
	argv = 0;
	c = 0;
	b = 0;
	c = ft_printf("*****ft_printf: %d\n", 12345);
	ft_putstr("Return: ");
	ft_putnbr(c);
	ft_putchar('\n');
	b = printf("-----nm_printf: %d\n", 12345);
	ft_putstr("Return: ");
	ft_putnbr(b);
	ft_putchar('\n');
	return (0);
}
