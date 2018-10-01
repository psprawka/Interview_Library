/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_dups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:12:53 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 11:59:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Remove dups: Write code to remove duplicates from an unsorted linked list.
**	How would you solve it if a temporary buffer is not allowed?
*/

#include "../Libft/includes/libft.h"		/*	hash table, linked list	 */ 


typedef struct	s_data {
	int	value;
}				t_data;

int		cmp(void *node1, void *node2)
{
	if (!node1 || !node2)
		return (EXIT_FAILURE);

	return (((t_data *)node1)->value == ((t_data *)node2)->value ? EXIT_SUCCESS : EXIT_FAILURE);
}



void	remove_dups(t_node *head)
{
	t_ht_table	*ht;
	t_ht_item	*item;
	t_node		*prev = NULL;
	
	if (!(ht = ft_init_table_ht(20)))
		return ;
	
	while (head)
	{
		// printf("Inside; HT:\n");
		ft_print_ht(ht);
		// printf("\n");
		
		if (ft_search_ht(ht, head, &cmp))
		{
			// printf("searched\n")
			prev->next = head->next;
			free(head);						/*	free based of node content	*/
			head = prev->next;
			continue ;
		}
		// printf("tf\n");
		item = ft_init_item_ht(head, head->data);
		ft_insert_ht(ht, item, &cmp);
		prev = head;
		head = head->next;
	}
	ft_free_table_ht(ht);
}

/*
**	If no buffer is allowed (so no additional memory), we have to do it in place;
**	for each element we would gho through entire linked list to see if there are
**	duplicates and remove them. It gives us O(1) space and O(n2) time complexity.
*/
