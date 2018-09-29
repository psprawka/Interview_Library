/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 06:39:28 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/19 18:11:33 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

#define t_stack struct s_stack
#define t_item struct s_item

t_item		*itemInit(int idx)
{
	t_item	*new;

	new = (t_item *)malloc(sizeof(t_item));
	new->idx = idx;
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

int			pop(t_stack *stack)
{
	t_item	*tmp;
	
	if (!stack || !stack->item)
		return (0);
	
	tmp = stack->item;
	stack->item = stack->item->next;
	return (tmp->idx);
}

void	push(t_stack *stack, int idx)
{
	t_item	*new;

	new = itemInit(idx);
	
	new->next = stack->item;
	stack->item = new;
}

char	*console(void)
{
	char		*input;
	char		*msg;
	int			lastIndex;
	t_stack		*stack;
	size_t		bufsize = 256;
	
	lastIndex = 0;
	stack = stackInit();
	input = (char *)malloc(256);
	msg = (char *)malloc(256);
	bzero(input, 256);
	bzero(msg, 256);
	
	
	write(1, "> ", 2);
	while (getline(&input, &bufsize, stdin))
	{
		input[strlen(input) - 1] = '\0'; 
		if (!strcmp("SEND", input))
			return(msg);
		else if (!strcmp("UNDO", input))
		{
			lastIndex = pop(stack);
			msg[lastIndex] = '\0';
		}
		else
		{
			push(stack, lastIndex);
			if (msg[0] != '\0')
			{
				strcat(msg, " ");
				lastIndex += 1;
			}
			strcat(msg, input);
			lastIndex += strlen(input);
		}
		printf("%s\n", msg);
		bzero(input, 256);
		write(1, "> ", 2);	
	}
	return(NULL);
}
