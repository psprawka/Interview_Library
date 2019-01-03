/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_kth_to_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:13:12 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 14:33:52 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Return Kth to Last: Implement an algorithm to find the kth node in linked
**	list from the end.
*/

#include "../Libft/includes/libft.h"		/*	linked list	 */


/*	Interative solution - the most one:	*/
t_node	*return_kth_to_last(t_node *head, int k)
{
	t_node	*p1, *p2;

	for (p2 = head; k-- && p2; p2 = p2->next) ;
	if (k >= 0)
		return (NULL);
	for (p1 = head; p2; p1 = p1->next, p2 = p2->next) ;
	return (p1);
}
