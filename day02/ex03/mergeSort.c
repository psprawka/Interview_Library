/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:52:29 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/20 11:32:59 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define t_player struct s_player

void	callMerge(t_player **players, int start, int middle, int end)
{
	t_player	**arr1 = (t_player**)calloc(middle - start, sizeof(t_player *));
	t_player	**arr2 = (t_player**)calloc(end - middle - 1, sizeof(t_player *));
	int			i = -1, j = -1, x = 0;
	int			len1 = middle - start, len2 = end - middle - 1;

	
	while (++i < len1)
		arr1[i] = players[i + start];
	while (++j < len2)
		arr2[j] = players[i + middle + 1];

	i = 0; j = 0;
	while (i < len1 && j < len2)
	{
		players[x++] = (arr1[i] > arr2[j]) ? arr1[i++] : arr2[j++];
		// if (arr1[i] > arr2[j])
		// 	players[x++] = arr1[i++];
		// else
		// 	players[x++] = arr2[j++];		
	}
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
	middle = (end - start) / 2;
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
