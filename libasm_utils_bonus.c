/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:15:26 by fgata-va          #+#    #+#             */
/*   Updated: 2020/06/27 19:39:05 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

char		*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (c == *s)
			return ((char *)s);
		s++;
	}
	if (c == '\0' && *s == '\0')
		return ((char *)s);
	return (NULL);
}

int		ft_isspace(char s)
{
	if (ft_strchr("\t\n\v\f\r ", s))
		return (1);
	return (0);
}

int			ft_validate_base(char *base)
{
	char	*aux;
	if (ft_strlen(base) <= 1)
		return (0);
	while (*base != 0)
	{
		if (ft_isspace(*base) || *base == '-' || *base == '+')
			return (0);
		aux = base;
		while (*(aux++) != 0)
		{
			if (*base == *aux)
				return (0);
		}
		base++;
	}
	return (1);
}

int					ft_atoi_base_c(char *str, char *base)
{
	long int		num;
	int				neg;
	int				len;

	if (ft_validate_base(base) == 0)
		return (0);
	neg = 1;
	len = ft_strlen(base);
	while (ft_isspace(*str) != 0)
			str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
				neg *= -1;
		str++;
	}
	num = 0;
	while (*str && ft_strchr(base, *str) != NULL)
	{
		num = (num * len) + (ft_strchr(base, *str) - base);
		str++;
	}
	return (num * neg);
}

void	ft_list_push_front_c(t_list **begin_list, void *data)
{
	t_list *new;

	if (begin_list == NULL)
		return ;
	if(!(new = malloc(sizeof(t_list))))
		return ;
	new->data = data;
	new->next = *begin_list;
	*begin_list = new;
}

int		ft_list_size_c(t_list *begin_list)
{
	int i;

	if (begin_list == NULL)
		return (0);
	i = 0;
	while(begin_list != NULL)
	{
		i++;
		begin_list = begin_list->next;
	}
	return(i);
}

t_list          *ft_swap(t_list *begin_list, t_list *nxt)
{
        t_list *aux;

        aux = nxt->next;
        nxt->next = begin_list;
        begin_list->next = aux;
        return (nxt);
}

void            ft_list_sort(t_list **begin_list, int (*cmp)())
{
        int             i;
        int             j;
        int             len;
        t_list  **head;

        if (begin_list == NULL || *begin_list == NULL || (*begin_list)->next == NULL)
                return ;
        len = ft_list_size_c(*begin_list);
        i = 0;
        while (i < len)
        {
                j = 0;
                head = begin_list;
                while (j < len - i - 1)
                {
                        if (((*cmp)((*head)->data, (*head)->next->data)) > 0)
                                *head = ft_swap(*head, (*head)->next);
                        head = &(*head)->next;
                        j++;
                }
                i++;
        }
}
