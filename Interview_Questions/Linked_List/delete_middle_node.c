/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_middle_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:13:35 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 14:32:10 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Delete Middle Node: Implement an algorithm to delete a node in the middle
**	of a singly linked link list, given only access to this node.
*/

#include "../Libft/includes/libft.h"	/*	linked list	 */

void	delete_middle_node(t_node *node)
{
	t_node	*tmp;
	
	if (!node || !node->data)
		return ;
	if (!node->next)
	{
		node->data = NULL;
		node->data = 0;
		return ;
	}
	free(node->data);
	node->data = node->next->data;
	node->d_size = node->next->d_size;
	tmp = node->next;
	node->next = node->next->next;
	free(tmp);
}