/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimal_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 15:47:19 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/10 00:01:36 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct	s_data
{
	int value;
}				t_data;

typedef struct	s_bst
{
	struct s_bst	*left;
	struct s_bst	*right;
	void			*data;
}				t_bst;

t_data	*create_data(int value)
{
	t_data *node;

	if (!(node = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	node->value = value;
	return (node);
}

t_bst	*ft_init_bst(void *data)
{
	t_bst	 *node;

	if (!(node = (t_bst *)calloc(1, sizeof(t_bst))))
		return (NULL);
	node->data = data;
	return (node);
}

t_bst	*createBST(int *arr, int n)
{
	t_bst *root;
	
	if (n < 1)
		return (NULL);

	root = ft_init_bst(create_data(arr[n/2]));
	root->left = createBST(arr, n/2);
	root->left = createBST(&(arr[n/2 + 1]), (n-1)/2);
	return (root);
}
