/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 09:00:50 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/28 10:43:21 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

#define t_node struct s_node

t_node	*initNode(int value)
{
	t_node *new;
	
	if (!(new = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new->value = value;
	new->right = NULL;
	new->left = NULL;
	return (new);
}

struct s_node *createBST(int *arr, int n)
{
	t_node *root;

	if (n < 1)
		return (NULL);
	root = initNode(arr[(n-1)/2]);
	root->left = createBST(arr, (n-1)/2);
	root->right = createBST(&(arr[(n+1)/2]), (n)/2);

	// the other direction:
	// root = initNode(arr[n/2]);
	// root->left = createBST(arr, n/2);
	// root->right = createBST(&(arr[n/2 + 1]), (n-1)/2);
	return (root);
}


