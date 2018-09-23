/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 07:18:17 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/22 08:15:30 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

#define t_node struct s_node

t_node	*new_node(int val)
{
	t_node *new;

	new = (t_node *)calloc(1, sizeof(t_node));
	new->value = val;
	return (new);
}

// struct s_node	*createBST(int *arr, int n)
t_node	*createBST(int *arr, int n)
{
	t_node *root;

	if (n < 1)
		return (NULL);

	root = new_node(arr[n / 2]);
	root->left = createBST(arr, n / 2);
	root->right = createBST(&(arr[n / 2 + 1]), n - n / 2 - 1);	
	return (root);
}