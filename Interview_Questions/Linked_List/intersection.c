/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:14:20 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 23:23:00 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Intersection: Given two single linked lists, determine if two linked lists
**	intersect. Return the intersecting node (intersection is based on addresses,
**	not value!).
*/

#include "../Libft/includes/libft.h"	/*	linked list	 */
#include <stdbool.h>

t_node	*intersection(t_node *l1, t_node *l2)
{
	int		len1, len2;
	t_node	*last1, *last2, *head1, *head2;

	head1 = l1;
	head2 = l2;
	
	for (len1 = 0; l1; len1++, l1 = l1->next)
		last1 = l1;
	for (len2 = 0; l2; len2++, l2 = l2->next)
		last2 = l2;

	if (last1 != last2)
		return (NULL);
	for (int res = len1 - len2; res > 0; res--)
		head1 = head1->next;
	for (int res = len2 - len1; res > 0; res--)
		head2 = head2->next;
	
	for (; head1 && head2; head1 = head1->next, head2 = head2->next)
		if (head1 == head2)
			return (head1);
	return (false);
}
