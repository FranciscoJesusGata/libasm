/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 18:25:35 by fgata-va          #+#    #+#             */
/*   Updated: 2020/04/11 10:37:28 by fgata-va         ###   ########.fr       */
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
int			ft_test_len();

#endif
