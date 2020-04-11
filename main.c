/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:36:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/04/11 12:08:56 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
		{
			write(fd, s, 1);
			s++;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char		c;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n *= -1;
			n = n % 1000000000;
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

int			main(void)
{
	ft_putstr_fd("\033[1;36mLIBASM TESTER\033[0m\n", 1);
	ft_putstr_fd("By: fgata-va\n\n", 1);
	ft_putstr_fd("Test_01: ft_strlen...........", 1);
	if (ft_test_len() == 1)
		ft_putstr_fd("\033[1;32mOK!\n", 1);
	else
		ft_putstr_fd("\033[1;31mKO\n", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("Test_02: ft_strcpy...........", 1);
	ft_test_cpy();
}
