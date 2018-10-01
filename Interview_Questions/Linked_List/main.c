/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:57:15 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 14:34:34 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct	s_data {
	int	value;
}				t_data;


void	remove_dups(t_node *head);
t_node	*return_kth_to_last(t_node *head, int k);
void	delete_middle_node(t_node *node);

void	print_list(t_node *list)
{
	while (list)
	{
		if (list->data)
			printf("%d -> ", ((t_data *)list->data)->value);
		list = list->next;
	}
	printf("(null)\n");
}

int	main(int ac, char **av)
{
	t_node	*head, *tmp;
	t_data	*data;
	int		len, k;
	
	srand(time(NULL));

	len = 20;
	while (len--)
	{
		data = (t_data *)calloc(1, sizeof(t_data));
		data->value = rand() % 30 + 1;
		ft_add_list(&head, data);
	}
	
	print_list(head);
	// remove_dups(head);
	// print_list(head);
	
	k = 3;
	// tmp = return_kth_to_last(head, k);
	// printf("Return Kth to last: k = %d, val = %d\n", k, tmp ? ((t_data *)tmp->data)->value : -1);
	
	// k = 20;
	// tmp = return_kth_to_last(head, k);
	// printf("Deleting node kth (%d) to last: %d\n", k, ((t_data *)tmp->data)->value);
	// delete_middle_node(tmp);
	// print_list(head);
	
	// k = 4;
	// tmp = return_kth_to_last(head, k);
	// printf("Deleting node kth (%d) to last: %d\n", k, ((t_data *)tmp->data)->value);
	// delete_middle_node(tmp);
	// print_list(head);
	
	// k = 1;
	// tmp = return_kth_to_last(head, k);
	// printf("Deleting node kth (%d) to last: %d\n", k, ((t_data *)tmp->data)->value);
	// delete_middle_node(tmp);
	// print_list(head);
	
}
