/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 10:22:37 by fgata-va          #+#    #+#             */
/*   Updated: 2020/06/05 23:03:39 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <fcntl.h>
#include <errno.h>

void			ft_test_len(char *str)
{
	size_t	expected;
	size_t	received;

	expected = ft_strlen_c(str);
	received = ft_strlen(str);
	if (expected == received)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
		ft_putstr_fd("\033[1;31mKO ", 1);
}

void		ft_test_cpy(char *str)
{
	char	dst[500];
	char	dst2[500];
	char	*output1;
	char	*output2;
	int		ok;

	ok = 0;
	output1 = ft_strcpy(dst, str);
	output2 = ft_strcpy_c(dst2, str);
	if (ft_strcmp_c(dst, dst2) == 0 && 
		ft_strcmp_c(output1, output2) == 0)
	{
		ft_putstr_fd("\033[1;32mOK! ", 1);
		ok = 1;
	}
	else
	{
		ft_putstr_fd("\033[1;31mKO ", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putstr_fd(dst, 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putstr_fd(dst2, 1);
	}
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

void		ft_test_write(int *fd, char *str, int len)
{
	int		out1;
	int		out2;
	char	buff1[100];
	char	buff2[100];

	out1 = ft_write(fd[1], str, len);
	out2 = write(fd[1], str, len);
	if (out1 == out2)
	{
		if(out1 <= 0)
			ft_putstr_fd("\033[1;32mOK! ", 1);
		else
		{
			read(fd[0], buff1, len);
			buff1[len] = '\0';
			read(fd[0], buff2, len);
			buff2[len] = '\0';
			if(ft_strcmp_c(buff1,buff2) == 0)
				ft_putstr_fd("\033[1;32mOK! ", 1);
			else
				{
					ft_putstr_fd("\033[1;31mKO\n", 1);
					ft_putstr_fd("\033[0mYour function returned: ", 1);
					ft_putstr_fd(buff1, 1);
					ft_putstr_fd("\nThe program expected: ", 1);
					ft_putstr_fd(buff2, 1);
					write(1,"\n",1);
				}
		}
	}
	else
	{
		ft_putstr_fd("\033[1;31mKO\n", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putnbr_fd(out1, 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putnbr_fd(out2, 1);
		write(1,"\n",1);
	}
}

void	write_tests()
{
	int	fds[2];
	int	out1;
	int out2;
	int	errno;
	int err1;
	int err2;

	errno = 0;
	pipe(fds);
	out1 = ft_write(-1, "Hello", 5);
	err1 = errno;
	out2 = write(-1, "Hello", 5);
	err2 = errno;
	if (out1 == out2 && err1 == err2)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
	{
		ft_putstr_fd("\033[1;31mKO\n", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putnbr_fd(out1, 1);
		ft_putstr_fd("\033[0m and errno: ", 1);
		ft_putnbr_fd(err1, 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putnbr_fd(out2, 1);
		ft_putstr_fd("\033[0m and errno: ", 1);
		ft_putnbr_fd(err2, 1);
		write(1,"\n",1);
	}
	ft_test_write(fds, NULL, 5);
	ft_test_write(fds, "Hello", 5);
	ft_test_write(fds, "Hello", 0);
	ft_test_write(fds, "H", 1);
	ft_test_write(fds, "", 0);
	ft_test_write(fds, "Hello", 6);
	ft_test_write(fds, "Hello", 2);
	close(fds[0]);
	close(fds[1]);
}

void		ft_test_read(char *str, int len)
{
	int		out1;
	int		out2;
	char	buff1[100];
	char	buff2[100];
	int		fd1[2];
	int		fd2[2];
	pipe(fd1);
	pipe(fd2);

	write(fd1[1], str, ft_strlen_c(str));
	out2 = read(fd1[0], buff2, len);
	buff1[len] = '\0';
	write(fd2[1], str, ft_strlen_c(str));
	out1 = ft_read(fd2[0], buff1, len);
	buff2[len] = '\0';
	if (out1 != out2)
	{
		ft_putstr_fd("\033[1;31mKO\n", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putnbr_fd(out1, 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putnbr_fd(out2, 1);
		write(1,"\n",1);
	}
	if (ft_strcmp_c(buff1,buff2) == 0)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
	{
		ft_putstr_fd("\033[1;31mKO\n", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putstr_fd(buff1, 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putstr_fd(buff2, 1);
		write(1,"\n",1);
	}
	close(fd1[0]);
	close(fd2[1]);
	close(fd1[0]);
	close(fd2[1]);
}

void	read_tests()
{
	int		out1;
	int		out2;
	char	buff[20];
	int		errno;
	int		err1;
	int		err2;

	out1 = ft_read(-1, buff, 5);
	err1 = errno;
	out2 = read(-1, buff, 5);
	err2 = errno;
	if (out1 == out2 && err1 == err2)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
	{
		ft_putstr_fd("\033[1;31mKO\n", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putnbr_fd(out1, 1);
		ft_putstr_fd("\033[0m and errno: ", 1);
		ft_putnbr_fd(err1, 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putnbr_fd(out2, 1);
		ft_putstr_fd("\033[0m and errno: ", 1);
		ft_putnbr_fd(err2, 1);
		write(1,"\n",1);
	}

	out1 = ft_read(-1, NULL, 5);
	err1 = errno;
	out2 = read(-1, NULL, 5);
	err2 = errno;
	if (out1 == out2 && err1 == err2)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
	{
		ft_putstr_fd("\033[1;31mKO\n", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putnbr_fd(out1, 1);
		ft_putstr_fd("\033[0m and errno: ", 1);
		ft_putnbr_fd(err1, 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putnbr_fd(out2, 1);
		ft_putstr_fd("\033[0m and errno: ", 1);
		ft_putnbr_fd(err2, 1);
		write(1,"\n",1);
	}

	ft_test_read("", 0);
	ft_test_read("Hello World", 5);
	ft_test_read("fgkrpktwporkw4'0234i569203r2'r@#!!\\\ndas", 
	ft_strlen_c("fgkrpktwporkw4'0234i569203r2'r@#!!\\\ndas"));
	ft_test_read("What is 42? 42 is the answer to the univer", 42);
	ft_test_read("What is 42? 42 is the answer to the univer" , 40);
}

void	ft_test_dup(const char *str)
{
	char	*dst;
	char	*dst2;

	dst = ft_strdup(str);
	dst2 = ft_strdup_c(str);
	if (ft_strcmp_c(dst, dst2) == 0)
		ft_putstr_fd("\033[1;32mOK! ", 1);
	else
	{
		ft_putstr_fd("\033[1;31mKO ", 1);
		ft_putstr_fd("\033[0mYour function returned: ", 1);
		ft_putstr_fd(dst, 1);
		ft_putstr_fd("\nThe program expected: ", 1);
		ft_putstr_fd(dst2, 1);
	}
	free(dst);
	free(dst2);
}

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
