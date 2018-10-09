/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stacks_queues.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:43:35 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/08 18:16:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"
#include <stdlib.h>

///////////////////////////////////// 3.2 //////////////////////////////////////
 
typedef struct	s_wrap_stack
{
	t_node	*stack;
	t_node	*stack_min;
}				t_wrap_stack;

t_node	*my_stack_pop(t_wrap_stack *my_stack);
void	my_stack_push(t_wrap_stack *my_stack, int value);
int		my_stack_min(t_wrap_stack *my_stack);

int		main(int ac, char **av)
{
	//////////////////////////////////// 3.2 ///////////////////////////////////

	t_wrap_stack	*my_stack;

	if (!(my_stack = (t_wrap_stack *)calloc(1, sizeof(t_wrap_stack))))
		return (0);
	for (int i = 1; i < ac; i++)
		my_stack_push(my_stack, atoi(av[i]));
	// printf("\n------------------------\nSTACK HERE:\n");
	// ft_print_list(my_stack->stack);
	// printf("------------------------\n\n");
	for (int i = 1; i < ac; i++)
	{
		printf("Currently min in stack: %d\nPopping...\n\n", my_stack_min(my_stack));
		my_stack_pop(my_stack);
	}


	return (0);
}

