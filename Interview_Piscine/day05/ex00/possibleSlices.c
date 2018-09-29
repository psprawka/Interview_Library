/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 20:46:02 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/25 21:18:45 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	printPossibleSlices(int pizzaSize)
{
	struct s_array	*arr;
	int				newSize = 0;
	
	if (!pizzaSize)
		return ;
	
	arr = arrayInit();
	while (pizzaSize)
	{
		arrayAppend(arr, pizzaSize);
		printPossibleSlices(pizzaSize--);
	}
	arrayPrint(arr);
}
