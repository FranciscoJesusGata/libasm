/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:13:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/04/11 00:02:40 by fgata-va         ###   ########.fr       */
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

