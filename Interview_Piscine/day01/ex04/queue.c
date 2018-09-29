/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:47:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/19 19:20:38 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

// struct s_node {
// 	char          *message;
// 	struct s_node *next;
// };

// struct s_queue {
//   struct s_node *first;
// 	struct s_node *last;
// };

#define t_queue struct s_queue
#define t_node struct s_node

t_queue	*queueInit(void)
{
	t_queue *queue;

	if (!(queue = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

t_node	*nodeInit(char *msg)
{
	t_node *new;

	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->message = msg;
	new->next = NULL;
	return (new);
}

char	*dequeue(t_queue *queue)
{
	t_node *tmp;

	if (!queue || !queue->first)
		return (NULL);

	tmp = queue->first;
	queue->first = tmp->next;
	return (tmp->message);
}

void	enqueue(t_queue *queue, char *message)
{
	t_node 	*new;
	
	new = nodeInit(message);
	if (!queue || !new)
		return ;
		
	if (!queue->first || !queue->last)
	{
		queue->first = new;
		queue->last = new;
	}
	else
	{
		queue->last->next = new;
		queue->last = new;
	}
}

char	*peek(t_queue *queue)
{
	if (queue && queue->first)
		return (queue->first->message);
	return (NULL);
}

int		isEmpty(t_queue *queue)
{
	// if (!queue || !queue->first)
	// 	return (EXIT_SUCCESS); // 0
	// return (EXIT_FAILURE); // 1
	if (!queue || !queue->first)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}



