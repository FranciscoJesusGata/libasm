/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:36:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/04/11 00:17:36 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libasm.h"

int			main(void)
{
	char	dst[5];
	char	dst2[5];
	char 	*x;

	printf("Sting Hello World is %zu long\n", ft_strlen("Hello World"));
	x = ft_strcpy(dst, "test");
	printf("dst: %s\nx: %s\n", dst, x);
	x = strcpy(dst2, "test");
	printf("dst: %s\nx: %s\n", dst2, x);
}
