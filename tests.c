/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 10:22:37 by fgata-va          #+#    #+#             */
/*   Updated: 2020/05/12 14:24:14 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int			ft_test_len()
{
	size_t	expected;
	size_t	received;

	expected = ft_strlen_c("42 is the answer to life, the universe and everything");
	received = ft_strlen("42 is the answer to life, the universe and everything");
	if (expected == received)
		return (1);
	return (0);
}

int			ft_test_cpy()
{
	char	dst[42];
	char	dst2[42];
	char	*output1;
	char	*output2;
	int		ok;

	ok = 0;
	output1 = ft_strcpy(dst, "Could I use a string with 42 characters??");
	output2 = ft_strcpy_c(dst2, "Could I use a string with 42 characters??");
	if (ft_strcmp_c(dst, dst2) == 0 && 
		ft_strcmp_c(output1, output2) == 0)
	{
		ft_putstr_fd("\033[1;32mOK!\n", 1);
		ok = 1;
	}
	else
	{
		ft_putstr_fd("\033[1;31mKO\n", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putstr_fd(dst, 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putstr_fd(dst2, 1);
	}
	return (ok);
}

void		ft_test_cmp(char *str1, char *str2)
{
	int exp;
	int act;

	exp = ft_strcmp_c(str1, str2);
	act = ft_strcmp(str1, str2);
	if(exp == act)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
	{
		ft_putstr_fd("\033[1;31mKO\n", 1);
	    ft_putstr_fd("\033[0mYour function returned: ", 1);
	    ft_putnbr_fd(exp, 1);
	    ft_putstr_fd("\nThe program expected: ", 1);
		ft_putnbr_fd(act, 1);
		write(1,"\n",1);
	}
}
