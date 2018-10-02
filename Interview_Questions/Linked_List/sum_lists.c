/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:13:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 17:53:51 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Sum Lists: You have two numbers represented by linked list, where each node
**	contains a single digit. The digits are stored in reverse order, such as
**	7→6→4 for 467. Write function that returns a linked list with sum of the addition. 
*/

#include "../Libft/includes/libft.h"	/*	linked list	 */
#include <stdbool.h>

typedef struct	s_data {
	int	value;
}				t_data;

t_data	*init_data(int value);
// {
// 	t_data	*data;
	
// 	data = (t_data *)calloc(1, sizeof(t_data));
// 	data->value = rand() % 10;
// 	return (data);
// }

t_node	*sum_lists(t_node *l1, t_node *l2)
{
	t_node	*head, *prev;
	bool	carry = false;
	int		sum = 0;
	
	head = l1;
	while (l1 && l2)
	{
		sum = ((t_data *)l1->data)->value + ((t_data *)l2->data)->value + carry;
		carry = sum > 9 ? true : false;
		((t_data *)l1->data)->value = sum % 10;
		prev = l1;
		l1 = l1->next;
		l2 = l2->next;
	}
	prev->next = l2;
	while (l2)
	{
		sum = ((t_data *)l2->data)->value + carry;
		((t_data *)l2->data)->value = sum % 10;
		carry = sum > 9 ? true : false;
		if (!carry)
			break ;
		l2 = l2->next;
	}
	if (carry)
		ft_add_back_list(&prev, ft_init_node(init_data(1), sizeof(t_data)));
	return (head);
}