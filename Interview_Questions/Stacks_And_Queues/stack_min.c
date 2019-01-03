/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:50:31 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/08 18:17:01 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Stack Min: How would you design a stack, which in addition to push() and
**	pop() has a function min(), which returns the minimum element in the stack?
**	Push(), pop() and min() should be in O(1) time complexity. 
*/

#include "../Libft/includes/libft.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct	s_data
{
	int		value;
}				t_data;

typedef struct	s_wrap_stack
{
	t_node	*stack;
	t_node	*stack_min;
}				t_wrap_stack;


t_data	*my_create_data(int value)
{
	t_data *data;

	if (!(data = (t_data *)calloc(1, sizeof(t_data))))
		return (NULL);
	data->value = value;
	return (data);
}

t_node	*my_stack_pop(t_wrap_stack *my_stack)
{
	t_node	*tmp;
	
	if (!my_stack || !my_stack->stack || !my_stack->stack_min)
		return (NULL);	
	if (((t_data *)my_stack->stack->data)->value == ((t_data *)my_stack->stack_min->data)->value)
	{
		tmp = my_stack->stack_min;
		my_stack->stack_min = tmp->next;
		free(tmp);
	}
	tmp = my_stack->stack;
	my_stack->stack = tmp->next;
	return (tmp);
}

void	my_stack_push(t_wrap_stack *my_stack, int value)
{
	t_node	*to_add, *to_add_min;

	if (!my_stack || !(to_add = ft_init_node(my_create_data(value), sizeof(t_data))))
		return ;
	if (!my_stack->stack || !my_stack->stack_min)
	{
		my_stack->stack = to_add;
		if (!(to_add_min = (t_node *)calloc(1, sizeof(t_node))))
			return ;
		to_add_min = memcpy(to_add_min, to_add, sizeof(t_node));
		my_stack->stack_min = to_add_min;
		return ;
	}
	if (value <= ((t_data *)my_stack->stack_min->data)->value)
	{
		if (!(to_add_min = (t_node *)calloc(1, sizeof(t_node))))
			return ;
		to_add_min = memcpy(to_add_min, to_add, sizeof(t_node));
		to_add_min->next = my_stack->stack_min;
		my_stack->stack_min = to_add_min;
	}
	to_add->next = my_stack->stack;
	my_stack->stack = to_add;
}

int		my_stack_min(t_wrap_stack *my_stack)
{
	if (!my_stack || !my_stack->stack || !my_stack->stack_min)
		return (INT_MAX);
	return (((t_data *)my_stack->stack_min->data)->value);
}
