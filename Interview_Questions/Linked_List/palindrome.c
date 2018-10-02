/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palindrome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:14:08 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 23:30:02 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"	/*	linked list	 */
#include <stdbool.h>

typedef struct	s_data {
	int	value;
}				t_data;
void	print_list(t_node *list);

bool	palindrome(t_node *list)
{
	t_node	*stack = NULL, *tmp;				/*	FIFO stack	*/
	t_node	*p1, *p2;

	p1 = list;
	p2 = list;
	while (p2 && p2->next)
	{
		tmp = ft_memdup(p1, sizeof(t_node));
		tmp->next = NULL;
		ft_add_front_list(&stack, tmp);
		p1 = p1->next;
		p2 = p2->next;
		if (p2 && p2->next)
			p2 = p2->next;
	}
	printf("hello\n");
	print_list(p1);
	print_list(stack);
	while (stack && p1)
	{
		if (((t_data *)stack->data)->value != ((t_data *)p1->data)->value)
			return (false);
		ft_remove_list(&stack, stack);
		p1 = p1->next;
	}
	printf("helldsdsao\n");
	return (stack || p1 ? false : true);
}
