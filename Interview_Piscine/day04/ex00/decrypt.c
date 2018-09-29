/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:19:17 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/24 17:46:09 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

char	*getSum(char *a, char *b)
{
	int i = 5, res = 0;

	while (i >= 0)
	{
		// printf("res: %d\n", res);
		res += (a[i] == '1') ? 1 : 0;
		res += (b[i] == '1') ? 1 : 0;
		
		// printf("a %s a[i] %c | b %s b[i] %c | i %d | res %d\n", a, a[i], b, b[i], i, res);
		b[i--] = (res % 2) + 48;
		res = (res >= 2) ? 1 : 0;
	}
	// printf("b %s\n", b);
	return (b);
}


int		toInt(char *bits)
{
	int	i = 5, res = 0;
	
	while (i >= 0)
	{
		res <<= 1;
		if (bits[i--] == '1')
			res ^= 1;	
	}
	return (res);
}