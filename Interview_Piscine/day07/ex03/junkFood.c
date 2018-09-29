/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:39:14 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/28 19:16:58 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define t_node		struct s_node
#define t_graph		struct s_graph
#define t_sellers	struct s_sellers
#define t_queue		struct s_queue
#define t_item		struct s_queueItem

t_node	*peekQueue(t_queue *queue)
{
	if (!queue || !queue->first)
		return (NULL);
	return (queue->first->place);
}

t_sellers	*fill_sell(t_queue *sell_queue, int distance, int amount)
{
	t_sellers	*sell;
	int			i = 0;
	
	if (!(sell = (t_sellers *)calloc(1, sizeof(t_sellers))) ||
		!(sell->placeNames = (char **)calloc(amount + 1, sizeof(char *))))
		return (NULL);

	sell->distance = distance;
	while (sell_queue && sell_queue->first)
		sell->placeNames[i++] = dequeue(sell_queue)->name;
	return (sell);
}

t_node		*find_me(struct s_graph *parisPlaces, char *youAreHere)
{
	for (int i = 0; parisPlaces->places[i]; i++)
		if (!strcmp(parisPlaces->places[i]->name, youAreHere))
			return (parisPlaces->places[i]);
		
	return (NULL);
}

t_sellers	*closestSellers(struct s_graph *parisPlaces, char *youAreHere)
{
	t_queue		*queue = queueInit(), *sell_queue = queueInit();
	t_node		*process;
	int			level = 0, amount = 0;
	
	if (!(process = find_me(parisPlaces, youAreHere)))
		return (NULL);
	if (process->hasCerealBar)
	{
		enqueue(sell_queue, process);
		return (fill_sell(sell_queue, level, 1));
	}
	enqueue(queue, process);
	enqueue(queue, NULL);
	while (queue && queue->first)
	{
		if (!(process = dequeue(queue)))
		{
			level++;
			if (sell_queue->first || !peekQueue(queue))
				break;
			enqueue(queue, NULL);
			continue ;
		}
		for (int j = 0; process->connectedPlaces[j] != NULL; j++)
		{
			if (process->connectedPlaces[j]->visited)
				continue ;
			if (process->connectedPlaces[j]->hasCerealBar && ++amount)
				enqueue(sell_queue, process->connectedPlaces[j]);
			process->connectedPlaces[j]->visited = true;
			enqueue(queue, process->connectedPlaces[j]);
		}
	}
	return (fill_sell(sell_queue, level, amount));
}