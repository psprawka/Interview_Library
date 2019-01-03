/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:30:51 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/19 23:45:43 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

#define t_tank	struct s_tank
#define t_stack	struct s_stack
#define t_elem	struct s_elem

struct s_tank *initTank(void)
{
	t_tank *new;

	if (!(new = (t_tank *)calloc(1, sizeof(t_tank))))
		return (NULL);
	new->stacks = NULL;
	new->n = 0;
	return (new);
}

t_stack *initStack(void)
{
	t_stack *new;

	if (!(new = (t_stack *)calloc(1, sizeof(t_stack))))
		return (NULL);
	new->sum = 0;
	new->elem = NULL;
	return (new);
}

t_elem *initElem(int energy)
{
	t_elem *new;

	if (!(new = (t_elem *)calloc(1, sizeof(t_elem))))
		return (NULL);
	new->energy = energy;
	new->next = NULL;
	return (new);
}

void	tankPush(struct s_tank *tank, int energy)
{
	t_stack *stack;
	t_elem	*new;


	if (!(new = initElem(energy)))
		return ;

	stack = NULL;
	if (tank->stacks)
	{
		stack = tank->stacks[tank->n - 1];
	}
	if (!tank->stacks)
	{
		tank->n += 1;
		tank->stacks = (t_stack **)realloc(tank->stacks, sizeof(t_stack *) * tank->n);
		stack = initStack();
		tank->stacks[tank->n - 1] = stack;
	}
	if (stack->sum + energy > 1000)
	{
		tank->n += 1;
		tank->stacks = (t_stack **)realloc(tank->stacks, sizeof(t_stack *) * tank->n);
		stack = initStack();
		tank->stacks[tank->n - 1] = stack;
	}

	stack->sum += energy;
	new->next = stack->elem;
	stack->elem = new;
	return ;
	
}

int		tankPop(struct s_tank *tank)
{
	t_stack *stack;
	t_elem	*tmp;
	int 	ret;
	
	if (!tank || !tank->n)
		return (0);

	stack = tank->stacks[tank->n - 1];
	stack->sum -= stack->elem->energy;
	tmp = stack->elem;
	ret = stack->elem->energy;
	stack->elem = stack->elem->next;
	free(tmp);
	
	if (!stack->elem)
	{
		free(tank->stacks[tank->n - 1]);
		tank->n -= 1;
		tank->stacks = (t_stack **)realloc(tank->stacks, sizeof(t_stack *) * tank->n);
	}
	return (ret);
}

void	printStacks(struct s_tank *tank)
{
	t_stack *stack;
	
	if (!tank || !tank->n)
		return ;

	for (int i = 0; i < tank->n; i++)
		printf("[%s]\t", i == 0 ? "norm" : "nitro");
	printf("\n");
	
	for (int i = 0; i < tank->n; i++)
	{
		stack = tank->stacks[i];
		printf("[%d]\t", stack->sum);
	}
	printf("\n");
}