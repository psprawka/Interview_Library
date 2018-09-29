/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:28:26 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/28 16:29:50 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

#define t_art struct s_art

void	swap_nodes(struct s_art **masterpiece, int a, int b)
{
	t_art	*tmp;
	
	tmp = masterpiece[a];
	masterpiece[a] = masterpiece[b];
	masterpiece[b] = tmp;
}

void	heapify(struct s_art **masterpiece, int size, int i)
{
	int		largest;
	int		right;
	int		left;
	
	largest = i;
	left = 2 * i + 1;
	right = 2 * i + 2;
	if (left < size && masterpiece[left]->price > masterpiece[largest]->price)
		largest = left;
	if (right < size && masterpiece[right]->price > masterpiece[largest]->price)
		largest = right;	
	if (largest == i)
		return ;

	swap_nodes(masterpiece, i, largest);
	heapify(masterpiece, size, largest);
}

void	heapSort(struct s_art **masterpiece, int n)
{
	if (!masterpiece || n < 2)
		return ;
	for (int i = n / 2 - 1; i >= 0; i--)
    	heapify(masterpiece, n, i);
		
	for (int i = n - 1; i >= 0; i--)
	{
		swap_nodes(masterpiece, 0, i);
    	heapify(masterpiece, i, 0);
	}
}