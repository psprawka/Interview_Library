/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_between_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:46:58 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/09 23:12:13 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h."
#include <stdbool.h>

typedef struct	s_graph
{
	struct s_graph	**nodes;
	int				nodes_count;
	int				value;			//void *data;
	bool			visited;
}				t_graph;

bool	route_between_nodes(t_graph *start, t_graph *dest)
{
	t_queue	*queue;
	t_queue	*current;

	if (!(queue = ft_init_queue))
		return (false);
	
	ft_add_queue(queue, start);
	while (queue)
	{
		current = ft_pop_queue(queue);
		for (int i = 0; i < current->nodes_count; i++)
		{
			if (current->nodes_count[i] == dest)
			{
				ft_free_queue(queue, NULL);
				return (true);
			}
			if (!current->nodes_count[i]->visited)
				ft_add_queue(queue, current->nodes_count[i]);
			current->nodes_count[i]->visited;
		}
	}
	ft_free_queue(queue, NULL);
	return (false);
}
