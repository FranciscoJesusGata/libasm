/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:13:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/06/20 18:03:01 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

size_t		ft_strlen_c(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strcpy_c(char *dst, const char *src)
{
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int			ft_strcmp_c(const char *s1, const char *s2)
{
	size_t	i;
	
	i = 0;
	while (((unsigned char)s1[i] != 0) && ((unsigned char)s2[i] != 0))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			if ((unsigned char)s1[i] < (unsigned char)s2[i])
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

char				*ft_strdup_c(const char *s1)
{
	char			*s2;
	size_t			l;
	unsigned int	i;

	i = 0;
	l = ft_strlen(s1);
	s2 = (char *)malloc(l + 1);
	if (s2)
	{
		while (s1[i] != '\0' && i < l)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	else
		return (0);
	return (s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s != '\0')
		{
			write(fd, s, 1);
			s++;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char		c;

	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == -2147483648)
		{
			write(fd, "2", 1);
			n *= -1;
			n = n % 1000000000;
		}
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

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



