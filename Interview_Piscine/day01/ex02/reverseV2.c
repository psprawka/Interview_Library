/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 05:16:41 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/19 06:38:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

#define t_stack struct s_stack
#define t_item struct s_item

t_item		*itemInit(char *word)
{
	t_item	*new;

	new = (t_item *)malloc(sizeof(t_item));
	new->word = word;
	new->next = NULL;
	return (new);
}

t_stack		*stackInit(void)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->item = NULL;
	return (new);
}

void		*pop(t_stack *stack)
{
	t_item	*tmp;
	
	if (!stack || !stack->item)
		return (NULL);
	
	tmp = stack->item;
	stack->item = stack->item->next;
	return (tmp);
}

void		push(t_stack *stack, char *word)
{
	t_item	*new;

	new = itemInit(word);
	
	new->next = stack->item;
	stack->item = new;
}

void		printReverseV2(struct s_node *lst)
{
	t_stack *stack;
	t_item	*pope;

	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}

	while ((pope = pop(stack)))
		printf("%s%c", pope->word, pope->next ? ' ' : '\n');
}