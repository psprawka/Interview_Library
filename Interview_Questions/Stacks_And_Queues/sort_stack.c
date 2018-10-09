/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:51:22 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/08 22:16:07 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/includes/libft.h"


typedef struct	s_data
{
	int		value;
}				t_data;


int		sort_stack(t_node *stack1)
{
	t_node	*stack2;
	t_data	*data;

	while (stack1)
	{
		data = stack1->data;
		while (((t_data *)ft_top_stack(stack1))->value 
		
	}


}
