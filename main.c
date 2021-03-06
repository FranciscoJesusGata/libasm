/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:36:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/07/06 18:23:22 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"

int			main(void)
{
	ft_putstr_fd("\033[1;36m                  LibASM Tester\033[0m\n", 1);
	ft_putstr_fd("                  By: fgata-va\n\n", 1);
	ft_putstr_fd("\033[1;36m              [~ MANDATORY PART ~]\033[0m\n", 1);

/*
** ft_strlen tests **
*/

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

/*
** ft_strcpy tests **
*/

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

/*
** ft_strcmp tests **
*/

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

/*
** ft_write tests **
*/

	ft_putstr_fd("\033[0mTest_04: ft_write............", 1);
	write_tests();
	ft_putstr_fd("\033[0m\n", 1);

/*
** ft_read tests **
*/

	ft_putstr_fd("\033[0mTest_05: ft_read.............", 1);
	read_tests();
	ft_putstr_fd("\033[0m\n", 1);

/*********************
 ** ft_strdup tests **
 *********************/

	ft_putstr_fd("\033[0mTest_06: ft_strdup...........", 1);
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

/*************************************************
 **                                             **
 **                 BONUS PART                  **
 **                                             **
 *************************************************/
	ft_putstr_fd("\033[1;36m              [~   BONUS PART   ~]\033[0m\n", 1);

/*
** ft_atoi_base **
*/

	ft_putstr_fd("\033[0mTest_07: ft_atoi_base........", 1);
	ft_test_atoi("", "");
	ft_test_atoi("10", "");
	ft_test_atoi("", "01");
	ft_test_atoi("42", "0123456789");
	ft_test_atoi("101010", "01");
	ft_test_atoi("2a", "0123456789abcdef");
	ft_test_atoi("\t\n\v\f\r 42", "01234");
	ft_test_atoi("fde0", "0123456789abcdef");
	write(1, "\n", 1);
	ft_putstr_fd("                             ", 1);
	ft_test_atoi("42", "0");
	ft_test_atoi("42", "01");
	ft_test_atoi("101010", "011");
	ft_test_atoi("10", "0+");
	ft_test_atoi("11", "-0");
	ft_test_atoi("101011", "\t321");
	ft_test_atoi("542", "0123\n456789");
	ft_test_atoi("10", "01\v");
	write(1, "\n", 1);
	ft_putstr_fd("                             ", 1);
	ft_test_atoi("11", "1\f0");
	ft_test_atoi("42", "0123456789\r");
	ft_test_atoi("101010", "0 1");
	ft_test_atoi("ffff", "0123456789abcdef");
	ft_test_atoi("---+-++-+-+--10--+-+-fe", "01");
	ft_test_atoi(" \n\t\r\f\v--+-2a", "0123456789abcdef");
	ft_test_atoi(" --+-\n--+f5 ", "0123456789abcdef");
	ft_test_atoi("--+ --f5-+ ff","0123456789abcdef");
	write(1, "\n", 1);
	ft_putstr_fd("                             ", 1);
	ft_test_atoi("-2147483648","0123456789");
	ft_test_atoi("+2147483647","0123456789");
	write(1,"\n",1);


	ft_putstr_fd("\033[0mTest_08: ft_list_push_front..", 1);
	ft_test_push_front("1 2 3 4 5 6", "0");
	ft_test_push_front("", "0");
	ft_test_push_front("0", "");
	ft_test_push_front("42 is the", "answer");
	ft_test_push_front("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19", "20");
	ft_test_push_front(NULL, "20");
	ft_test_push_front("42", NULL);
	write(1, "\n", 1);

	ft_putstr_fd("\033[0mTest_09: ft_list_size........", 1);
	ft_test_size("0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20");
	ft_test_size("");
	ft_test_size(NULL);
	ft_test_size("1");
	ft_test_size("1 2");
	ft_test_size("The answer is 42");
	write(1, "\n", 1);
}

