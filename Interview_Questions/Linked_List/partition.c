/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:13:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 17:16:50 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Partition: Write code to partition a linked list around a value x, such
**	as all elements less than x come after all nodes greater than node x.
**	If x is contained in a given list, the values of x only need to be after
**	the elements less than x - it can appear anywhere in right partition.
*/

#include "../Libft/includes/libft.h"	/*	linked list	 */

typedef struct	s_data {
	int	value;
}				t_data;


void	partition(t_node **head, int value)
{
	t_node *start, *end, *next, *list;

	if (!(*head) || !(*head)->next)
		return ;
	
	start = *head;
	end = *head;
	list = (*head)->next;
	
	while (list)
	{
		next = list->next;
		if (((t_data *)list->data)->value < value)
		{
			list->next = start;
			start = list;
		}
		else
		{
			end->next = list;
			end = end->next;
			end->next = NULL;
		}
		list = next;
	}
	*head = start;
}