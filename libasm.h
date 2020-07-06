/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 18:25:35 by fgata-va          #+#    #+#             */
/*   Updated: 2020/07/04 11:43:16 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t		ft_strlen(const char *s);
size_t		ft_strlen_c(const char *s);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcpy_c(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strcmp_c(const char *s1, const char *s2);
size_t		ft_write(int fd, const void *buf, size_t count);
size_t		ft_read(int fd, void *buf, size_t count);
char		*ft_strdup(const char *s1);
char		*ft_strdup_c(const char *s1);
int			ft_atoi_base_bonus(char *str, char *base);
int			ft_atoi_base_c(char *str, char *base);
void		ft_list_push_front_bonus(t_list **begin_list, void *data);
void		ft_list_push_front_c(t_list **begin_list, void *data);
int			ft_list_size_bonus(t_list *begin_list);
int			ft_list_size_c(t_list *begin_list);
void		ft_test_len(char *str);
void		ft_test_cpy(char *str);
void		ft_test_cmp(char *str1, char *str2);
void		write_tests();
void		read_tests();
void		ft_test_dup(const char *str);
void		ft_test_atoi(char *str, char *base);
void		ft_test_push_front(char *data, void *append);
void		ft_test_size(char *data);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_list_sort(t_list **begin_list, int (*cmp)());
void		ft_create_lst(t_list **new_lst, void *input);
void		ft_clean_lst(t_list **head);
int			ft_cmp_lst(t_list **l1, t_list **l2);

#endif
