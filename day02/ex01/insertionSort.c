/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 00:42:07 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/20 06:32:00 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

#define t_player struct s_player

void	insertionSort(struct s_player **players)
{
	t_player	*tmp;
	int			j;

	if (!players || !players[0] || !players[1])
		return ;

	for (int i = 1; players[i]; i++)
	{
		tmp = players[i];
		for (j = i - 1; j >= 0 && players[j]->score > tmp->score; j--)
			players[j + 1] = players[j];
		players[j + 1] = tmp;
	}
}
