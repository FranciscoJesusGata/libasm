/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 19:50:20 by fgata-va          #+#    #+#             */
/*   Updated: 2020/07/05 20:00:12 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ft_test_atoi(char *str, char *base)
{
	int expected;
	int actual;

	expected = ft_atoi_base_c(str, base);
	actual = ft_atoi_base_bonus(str, base);
	if (expected == actual)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
	{
		ft_putstr_fd("\033[1;31mKO ", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putnbr_fd(actual, 1);
		write(1, "\n", 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putnbr_fd(expected, 1);
		write(1, "\n", 1);
	}
}

void	ft_test_push_front(char *data, void *append)
{
	t_list *actual;
	t_list *expected;

	ft_create_lst(&actual, data);
	ft_create_lst(&expected, data);
	ft_list_push_front_bonus(&actual, ft_strdup_c(append));
	ft_list_push_front_c(&expected, ft_strdup_c(append));
	if(ft_cmp_lst(&actual, &expected) == 0)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
		ft_putstr_fd("\033[1;31mKO \n", 1);
	ft_clean_lst(&actual);
	ft_clean_lst(&expected);
}

void	ft_test_size(char *data)
{
	int actual;
	int expected;
	t_list *lst;

	ft_create_lst(&lst, data);
	actual = ft_list_size_bonus(lst);
	expected = ft_list_size_c(lst);
	if(actual == expected)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
	{
		ft_putstr_fd("\033[1;31mKO ", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putnbr_fd(actual, 1);
		write(1, "\n", 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putnbr_fd(expected, 1);
		write(1, "\n", 1);
	}
	ft_clean_lst(&lst);
}
