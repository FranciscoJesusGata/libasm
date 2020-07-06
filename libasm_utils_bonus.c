/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:51:17 by fgata-va          #+#    #+#             */
/*   Updated: 2020/07/04 11:44:38 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void				*ft_calloc(size_t count, size_t size)
{
	void			*s;
	unsigned int	i;
	unsigned int	len;

	if (!(s = malloc(size * count)))
		return (NULL);
	len = count * size;
	i = 0;
	while (i < len)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
	return (s);
}

int			ft_wrds(char const *s, char c)
{
	int wrds;
	int wrd_fnd;

	wrds = 0;
	wrd_fnd = 0;
	while (*s != '\0')
	{
		if (*s != c && wrd_fnd == 0)
		{
			wrds++;
			wrd_fnd = 1;
		}
		else if (*s == c)
			wrd_fnd = 0;
		s++;
	}
	return (wrds);
}

int			ft_chars(char const *s, char c)
{
	int cs;

	cs = 0;
	while (*s != c && *s != '\0')
	{
		cs++;
		s++;
	}
	return (cs);
}

void		ft_del_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void		ft_fillstr(int j, char **wrds, char const *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		wrds[j][i++] = *s;
		s++;
	}
}

char		**ft_split(char const *s, char c)
{
	char	**wrds;
	int		wrd_l;
	int		j;

	if (!s)
		return (NULL);
	if (!(wrds = ft_calloc(ft_wrds(s, c) + 1, sizeof(char *))))
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		wrd_l = ft_chars(s, c);
		if (wrd_l > 0 && !(wrds[j] = ft_calloc((wrd_l + 1), sizeof(char))))
		{
			ft_del_matrix(wrds);
			return (NULL);
		}
		ft_fillstr(j, wrds, s, c);
		s += wrd_l;
		j++;
	}
	return (wrds);
}

void		ft_create_lst(t_list **new_lst, void *input)
{
	t_list	*current;
	void	**data;
	int		i;

	*new_lst = malloc(sizeof(t_list));
	if (!input)
	{
		data = NULL;
		(*new_lst)->data = data;
		(*new_lst)->next = NULL;
		return ;
	}
	data = (void **)ft_split(input, ' ');
	current = *new_lst;
	i = 0;
	if(*data)
	{
		while (data[i + 1])
		{
			current->data = data[i];
			current->next = malloc(sizeof(t_list));
			current = current->next;
			i++;
		}
		current->data = data[i];
	}
	else
		current->data = *data;
	current->next = NULL;
	current = NULL;
	free(data);
}

void		ft_clean_lst(t_list **head)
{
	t_list	*current;
	t_list	*nxt;

	current = *head;
	while (current != NULL)
	{
		nxt = current->next;
		if (current->data)
			free(current->data);
		free(current);
		current = nxt;
	}
	current = NULL;
	nxt = NULL;
	*head = NULL;
}

int			ft_cmp_lst(t_list **l1, t_list **l2)
{
	int result;
	t_list *lst1;
	t_list *lst2;

	lst1 = *l1;
	lst2 = *l2;
	result = 0;
	while (lst1 && lst2)
	{
		if (!lst1->data && !lst2->data)
			return(0);
		else if (!lst1->data || !lst2->data)
			return(1);
		if(ft_strncmp(lst1->data, lst2->data, ft_strlen_c(lst1->data)) != 0)
		{
			result = 1;
			break ;
		}
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return (result);
}
