/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:13:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 15:16:24 by psprawka         ###   ########.fr       */
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


void	partition(t_node *head, int value)
{
	t_node *start, *end, *next;

	if (!head || !head->next)
		return ;
		
	start = head;
	end = head;
	head = head->next;
	next = head->next;
	
	while (head)
	{
		if (((t_data *)head->data)->value < value)
			ft_add_front_list(&start, hea)

		
	}
}