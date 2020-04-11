/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 10:22:37 by fgata-va          #+#    #+#             */
/*   Updated: 2020/04/11 10:38:24 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int			ft_test_len()
{
	size_t	expected;
	size_t	received;

	expected = ft_strlen_c("Hello World!");
	received = ft_strlen("Hello World!");
	if (expected == received)
		return (1);
	return (0);
}
