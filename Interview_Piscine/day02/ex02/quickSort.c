/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 07:06:21 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/20 10:46:40 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

#define t_player struct s_player

void	swapValues(t_player **players, int i, int j)
{
	t_player *tmp;

	tmp = players[i];
	players[i] = players[j];
	players[j] = tmp;
}

void	callquickSort(t_player **players, int first, int last)
{
	int i = first, j = last;
	int pivot = i;
	
	if (first >= last)
		return ;
	while (i < j)
	{
		while (players[i]->score <= players[pivot]->score && i < last)
			i++;
		while (players[j]->score > players[pivot]->score)
			j--;
		if (i < j)
			swapValues(players, i, j);
	}
	swapValues(players, j, pivot);
	callquickSort(players, first, j - 1);
	callquickSort(players, j + 1, last);
}

void	quickSort(struct s_player **players)
{
	int len = 0;
	
	while (players && players[len])
		len++;
	
	callquickSort(players, 0, len - 1);
}