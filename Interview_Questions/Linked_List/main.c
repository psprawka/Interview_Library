/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:57:15 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 23:32:10 by psprawka         ###   ########.fr       */
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
void	partition(t_node **head, int value);
t_node	*sum_lists(t_node *l1, t_node *l2);
bool	palindrome(t_node *list);

t_data	*init_data(int value)
{
	t_data	*data;
	
	data = (t_data *)calloc(1, sizeof(t_data));
	data->value = rand() % 10;
	return (data);
}

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
	t_node	*head1, *head2, *tmp;
	t_data	*data;
	int		len, len2, k;
	
	srand(time(NULL));

	len = 5;
	while (len--)
	{
		data = init_data(rand() % 10);
		tmp = ft_init_node(data, sizeof(data));
		ft_add_front_list(&head1, tmp);
	}
	len2 = 8;
	while (len2--)
	{
		data = init_data(rand() % 10);
		tmp = ft_init_node(data, sizeof(data));
		ft_add_front_list(&head2, tmp);
	}
	
	// remove_dups(head1);
	// print_list(head1);
	
	
	// k = 3;
	// tmp = return_kth_to_last(head1, k);
	// printf("Return Kth to last: k = %d, val = %d\n", k, tmp ? ((t_data *)tmp->data)->value : -1);
	

	// k = 20;
	// tmp = return_kth_to_last(head1, k);
	// printf("Deleting node kth (%d) to last: %d\n", k, ((t_data *)tmp->data)->value);
	// delete_middle_node(tmp);
	// print_list(head1);
	// k = 4;
	// tmp = return_kth_to_last(head1, k);
	// printf("Deleting node kth (%d) to last: %d\n", k, ((t_data *)tmp->data)->value);
	// delete_middle_node(tmp);
	// print_list(head1);
	// k = 1;
	// tmp = return_kth_to_last(head1, k);
	// printf("Deleting node kth (%d) to last: %d\n", k, ((t_data *)tmp->data)->value);
	// delete_middle_node(tmp);
	// print_list(head1);


	// print_list(head1);
	// partition(&head1, 15);
	// print_list(head1);
	
	
	// len = 5;
	// while (len--)
	// {
	// 	data = init_data(rand() % 10);
	// 	tmp = ft_init_node(data, sizeof(data));
	// 	ft_add_front_list(&head1, tmp);
	// }
	// len2 = 8;
	// while (len2--)
	// {
	// 	data = init_data(rand() % 10);
	// 	tmp = ft_init_node(data, sizeof(data));
	// 	ft_add_front_list(&head2, tmp);
	// }
	// printf("\nSUM OF:\n");
	// print_list(head1);
	// print_list(head2);
	// head1 = sum_lists(head1, head2);
	// printf("--------------------------------------------------\n");
	// print_list(head1);


	head1 = NULL;
	len = 0; len2 = 5;
	for (len = 0; len < len2; len++)
	{
		data = init_data(len);
		tmp = ft_init_node(data, sizeof(data));
		ft_add_front_list(&head1, tmp);
		tmp = ft_init_node(data, sizeof(data));
		// if (len != 3)							/*	non-palindrome	*/
		ft_add_back_list(&head1, tmp);
	}
	print_list(head1);
	printf("Palindrome? %s\n", palindrome(head1) ? "true" : "false");
	return (0);
}
