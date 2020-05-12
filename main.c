/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:36:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/05/12 14:56:08 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"

int			main(void)
{
	char *s1;

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
	ft_putstr_fd("\033[0mTest_03: ft_strcmp...........", 1);
	ft_test_cmp("test","test");
	ft_test_cmp("testing", "testinn");
	ft_test_cmp("testing", "testin");
	ft_putnbr_fd((ft_write(1, "\n\033[0mHola! \n", 11)), 1);
	ft_putnbr_fd((write(1, "\n\033[0mHola! \n", 11)), 1);
	printf("\n\n");
	s1 = ft_strdup("Hello");
	printf("%s\n", s1);
	free(s1);
}

