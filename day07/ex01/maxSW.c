/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 04:28:56 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/28 08:57:27 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

# define t_max			struct s_max
# define t_deque		struct s_deque
# define t_dequeNode	struct s_dequeNode

t_dequeNode		*nodeInit(int value)
{
	t_dequeNode	*new;

	if (!(new = (t_dequeNode *)malloc(sizeof(t_dequeNode))))
		return (NULL);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);	
}

struct s_deque	*dequeInit(void)
{
	t_deque *new;

	if (!(new = (t_deque *)malloc(sizeof(t_deque))))
		return (NULL);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void		pushFront(struct s_deque *deque, int value)
{
	t_dequeNode	*new;
	
	if (!deque || !(new = nodeInit(value)))
		return ;	
	new->next = deque->first;
	if (deque->first)
		deque->first->prev = new;
	deque->first = new;
	if (!deque->last)
		deque->last = new;
}

void		pushBack(struct s_deque *deque, int value)
{
	t_dequeNode	*new;
	
	if (!deque || !(new = nodeInit(value)))
		return ;
	new->prev = deque->last;
	if (deque->last)
		deque->last->next = new;
	deque->last = new;
	if (!deque->first)
		deque->first = new;
}

int			popFront(struct s_deque *deque)
{
	t_dequeNode	*tmp;
	int			value;
	
	if (!deque || !(tmp = deque->first))
		return (INT_MIN);
	deque->first = tmp->next;
	if (!(deque->first))
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	value = tmp->value;
	free(tmp);
	return (value);
}

int			popBack(struct s_deque *deque)
{
	t_dequeNode	*tmp;
	int			value;
	
	if (!deque || !(tmp = deque->last))
		return (INT_MIN);
	deque->last = tmp->prev;
	if (!(deque->last))
		deque->first = NULL;
	else
		deque->last->next = NULL;
	value = tmp->value;
	free(tmp);
	return (value);
}

bool		isEmpty(struct s_deque *deque)
{
	if (!deque || !(deque->first))
		return (true);
	return (false);
}

int			peekFront(struct s_deque *deque)
{
	if (isEmpty(deque))
		return (INT_MIN);
	return (deque->first->value);
}

int			peekBack(struct s_deque *deque)
{
	if (isEmpty(deque))
		return (INT_MIN);
	return (deque->last->value);
}

void		printQueue(struct s_deque *deque)
{
	t_dequeNode *tmp;
	
	if (!deque || !(tmp = deque->first))
		return ;
	
	printf("\nQUEUE:\n");
	while (tmp)
	{
		printf("[%d left: %d right: %d] ", tmp->value, tmp->prev ? tmp->prev->value : -100, tmp->next ? tmp->next->value : -100);
		tmp = tmp->next;
	}
	printf("\n\n");
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	t_deque *deque;
	t_max	*res;
	int		i = 0, j = 0;

	if (k < 1 || n < 1 || n < k || !(res = (t_max *)malloc(sizeof(t_max))) ||
		!(res->max = (int *)malloc(sizeof(int) * (n - k + 1))))
		return (NULL);
	deque = dequeInit();
	while (i < k)
	{
		while (!isEmpty(deque) && arr[peekBack(deque)] <= arr[i])
			popBack(deque);
		pushBack(deque, i++);
	}
	j = 0;
	while (i < n)
	{
		res->max[j++] = arr[peekFront(deque)];
		while (!isEmpty(deque) && peekFront(deque) <= i - k)
			popFront(deque);
		while (!isEmpty(deque) && arr[peekBack(deque)] <= arr[i])
			popBack(deque);
		pushBack(deque, i++);
	}
	res->max[j++] = arr[peekFront(deque)];
	res->length = j;
	return (res);
}