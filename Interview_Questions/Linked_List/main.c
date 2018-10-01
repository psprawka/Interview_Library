/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 10:57:15 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/01 11:33:54 by psprawka         ###   ########.fr       */
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


void	print_list(t_node *list)
{
	while (list)
	{
		printf("%d -> ", ((t_data *)list->data)->value);
		list = list->next;
	}
	printf("(null)\n");
}

int	main(int ac, char **av)
{
	t_node	*head, *tmp;
	t_data	*data;
	int		len;
	
	srand(time(NULL));

	len = 20;
	while (len--)
	{
		data = (t_data *)calloc(1, sizeof(t_data));
		data->value = rand() % 30 + 1;
		ft_add_list(&head, data);
	}
	
	print_list(head);
	remove_dups(head);
	print_list(head);
}
