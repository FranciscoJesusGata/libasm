/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 19:15:26 by fgata-va          #+#    #+#             */
/*   Updated: 2020/06/20 18:03:00 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

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

