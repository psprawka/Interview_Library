/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:52:29 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/20 20:02:30 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define t_player struct s_player

void	callMerge(t_player **players, int start, int middle, int end)
{
	t_player	**arr1;
	t_player	**arr2;
	int			i, j, x;
	int			len1 = middle - start + 1, len2 = end - middle;

	arr1 = (t_player**)calloc(len1 + 1, sizeof(t_player *));
	arr2 = (t_player**)calloc(len2 + 1, sizeof(t_player *));

	for (i = 0; i < len1; i++) 
        arr1[i] = players[start + i]; 
    for (j = 0; j < len2; j++) 
        arr2[j] = players[middle + 1+ j]; 
	
	i = 0; j = 0, x = start;
	while (i < len1 && j < len2)
		players[x++] = (arr1[i]->score < arr2[j]->score) ? arr1[i++] : arr2[j++];
	while (i < len1)
		players[x++] = arr1[i++];
	while (j < len2)
		players[x++] = arr2[j++];
}

void	callMergeSort(t_player **players, int start, int end)
{
	int		middle;

	if (start >= end)
		return ;

	middle = (end + start) / 2;
	callMergeSort(players, start, middle);
	callMergeSort(players, middle + 1, end);
	callMerge(players, start, middle, end);
}

struct s_player **mergeSort(struct s_player **players)
{
	int len = 0;

	while (players && players[len])
		len++;
		
	callMergeSort(players, 0, len - 1);
	return (players);
}
