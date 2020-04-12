/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 18:25:35 by fgata-va          #+#    #+#             */
/*   Updated: 2020/04/12 19:02:53 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <string.h>
# include <unistd.h>

size_t		ft_strlen(const char *s);
size_t		ft_strlen_c(const char *s);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcpy_c(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
int     	ft_strcmp_c(const char *s1, const char *s2);
int			ft_test_len();
int			ft_test_cpy();
void		ft_test_cmp(char *str1, char *str2);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif
