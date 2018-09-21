/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 21:42:31 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/20 23:07:00 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMBER_OF_USTENSILS	15

void	countSort(unsigned char *utensils, int n)
{
	unsigned char	ret[n];
	int				count[NUMBER_OF_USTENSILS + 1];
	int				i;
	
	memset(count, 0, sizeof(count));
	for (i = 0; utensils[i]; i++)
		count[utensils[i]]++;
	for (i = 0; i < NUMBER_OF_USTENSILS; i++)
		count[i + 1] += count[i];	
	for (i = 0; i < n; count[utensils[i]]-- && i++)
		ret[count[utensils[i]] - 1] = utensils[i];
	for (i = 0; i < n; i++)
		utensils[i] = ret[i];
}
