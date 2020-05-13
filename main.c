/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:36:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/05/13 16:42:53 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"

int			main(void)
{
	ft_putstr_fd("\033[1;36m                  LibASM Tester\033[0m\n", 1);
	ft_putstr_fd("                  By: fgata-va\n\n", 1);
	ft_putstr_fd("\033[1;36m             [~ MANDATORY PART  ~]\033[0m\n", 1);

	ft_putstr_fd("Test_01: ft_strlen...........", 1);
	ft_test_len("");
	ft_test_len("Hello");
	ft_test_len("Hello World!");
	ft_test_len("Could I use a string with 42 characters??");
	ft_test_len("42 is the answer to life, the universe and everything");
	ft_test_len("dplf''\\@#%&&!!");
	ft_test_len("Count this\0 but not this");
	ft_test_len("'Cause you make my earth quake\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
'Cause you make my earth quake (earth quake, ooh)\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
Don't leave, it's my fault\
Don't leave, it's my fault\
Don't leave, it's my fault (yeah)\
'Cause when it all comes crashing down I'll need you");
	ft_putstr_fd("\033[0m\n", 1);

	ft_putstr_fd("Test_02: ft_strcpy...........", 1);
	ft_test_cpy("");
	ft_test_cpy("Hello");
	ft_test_cpy("Hello World!");
	ft_test_cpy("Could I use a string with 42 characters??");
	ft_test_cpy("42 is the answer to life, the universe and everything");
	ft_test_cpy("dplf''\\@#%&&!!");
	ft_test_cpy("Copy this\0 but not this");
	ft_test_cpy("'Cause you make my earth quake\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
'Cause you make my earth quake (earth quake, ooh)\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
Don't leave, it's my fault\
Don't leave, it's my fault\
Don't leave, it's my fault (yeah)\
'Cause when it all comes crashing down I'll need you");
	ft_putstr_fd("\033[0m\n", 1);

	ft_putstr_fd("\033[0mTest_03: ft_strcmp...........", 1);
	ft_test_cmp("", "");
	ft_test_cmp("test","test");
	ft_test_cmp("test","tost");
	ft_test_cmp("testing", "testinn");
	ft_test_cmp("testing", "testin");
	ft_test_cmp("Hey bro\0I'm hidden","Hey bro\0I'm hidden");
	ft_test_cmp("asfrtwrrwe23492395239\\#|@!!~","asfrtwrrwe23492395239\\#|@!!~");
	ft_test_cmp("'Cause you make my earth quake\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
'Cause you make my earth quake (earth quake, ooh)\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
Don't leave, it's my fault\
Don't leave, it's my fault\
Don't leave, it's my fault (yeah)\
'Cause when it all comes crashing down I'll need you",
"'Cause you make my earth quake\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
'Cause you make my earth quake (earth quake, ooh)\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
Don't leave, it's my fault\
Don't leave, it's my fault\
Don't leave, it's my fault (yeah)\
'Cause when it all comes crashing down I'll need you");
	ft_putstr_fd("\033[0m\n", 1);

	ft_putstr_fd("\033[0mTest_04: ft_write............", 1);
	write_tests();
	ft_putstr_fd("\033[0m\n", 1);

	ft_putstr_fd("\033[0mTest_05: ft_read.............", 1);
	read_tests();
	ft_putstr_fd("\033[0m\n", 1);

	ft_putstr_fd("\033[0mTest_05: ft_strdup...........", 1);
	ft_test_dup("");
	ft_test_dup("Hello World");
	ft_test_dup("\1 \t\t sdfw'20 \\ 03422");
	ft_test_dup("Heheehehehe you can't see me\0I'm hidden");
	ft_test_dup("'Cause you make my earth quake\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
'Cause you make my earth quake (earth quake, ooh)\
Oh, you make my earth quake\
Riding around, your love is shakin' me up and it's making my heart break\
Don't leave, it's my fault\
Don't leave, it's my fault\
Don't leave, it's my fault (yeah)\
'Cause when it all comes crashing down I'll need you");
	ft_putstr_fd("\033[0m\n", 1);

}

