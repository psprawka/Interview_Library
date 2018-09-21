/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 00:38:37 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/20 21:38:22 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

#define t_stone struct s_stone

typedef struct	s_group
{
	int				count;
	int				value;
	struct s_group	*next;
}				t_group;


t_group	*newGroup(int value, int count)
{
	t_group *new;

	new = (t_group *)calloc(1, sizeof(t_group));
	new->value = value;
	new->count = count;
	return (new);
}

t_group *getGroups(t_stone *stones)
{
	int		value, count;
	t_group	*list = NULL, *new;
	
	if (!stones)
		return (NULL);
	while (stones)
	{
		count = 0;
		value = stones->size;
		while (stones && stones->size == value)
		{
			count++;
			stones = stones->next;
		}
		new = newGroup(value, count);
		new->next = list;
		list = new;
	}
	return (list);
}

void	swapGroups(t_group *group1, t_group *group2)
{
	int tmp1, tmp2;
	
	tmp1 = group1->value;
	tmp2 = group1->count;

	group1->value = group2->value;
	group1->count = group2->count;

	group2->value = tmp1;
	group2->count = tmp2;
}

void	bubbleSort(t_group *groups)
{
	for (t_group *out = groups; out->next != NULL; out = out->next)
	{
		for (t_group* in = groups; in->next != NULL; in = in->next)
			if (in->value > in->next->value)
				swapGroups(in, in->next);
	}
}

void	printGroups(t_group *groups)
{
	int i = 0;
	
	for (t_group *tmp = groups; tmp != NULL; tmp = tmp->next)
		printf("%d. GROUP: %d | COUNT: %d\n", ++i, tmp->value, tmp->count);
}

void	insertGroups(t_stone *stones, t_group *groups)
{
	for (t_group *tmp = groups; tmp && stones; tmp = tmp->next)
	{
		while (tmp->count-- && stones)
		{
			stones->size = tmp->value;
			stones = stones->next;
		}
	}	
}

void	sortStones(struct s_stone **stone)
{
	t_group *groups;

	groups = getGroups(*stone);
	bubbleSort(groups);
	// printGroups(groups);
	insertGroups(*stone, groups);
}
