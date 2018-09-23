/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 04:31:14 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/22 06:06:07 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// • The minimum value in the tree.
// • The maximum value in the tree.
// • The number of nodes in the tree.
// • The height of the tree, the number of edges on the longest path from the root node
// to a leaf.
// • Is it a Binary Search Tree (BST)?
// • Is it balanced ?

// struct s_info {
// 	int min; // the minimum value in the tree
// 	int max; // the max value in the tree
// 	int elements; // the number of nodes in the tree
// 	int height; // the height of the tree
// 	int isBST; // 0 = FALSE, 1 = TRUE
// 	int isBalanced; // 0 = FALSE, 1 = TRUE
// };

#define t_info		struct s_info
#define t_node		struct s_node
#define max(x, y)	(x >= y) ? x : y
#define min(x, y)	(x < y) ? x : y
#define abs(x, y)	(x - y) > 0 ? x - y : y - x


int		tree_height(t_node *root)
{
	if (!root)
		return (0);
	return (1 + (max(tree_height(root->left), tree_height(root->right))));
}

int		tree_count_nodes(t_node *root)
{
	if (!root)
		return (0);
	return (1 + tree_count_nodes(root->left) + tree_count_nodes(root->right));
}


static void	get_min_max(t_node *root, int *min, int *max)
{
	if (!root)
		return ;
	
	*min = min(*min, root->value);
	*max = max(*max, root->value);
	get_min_max(root->left, min, max);
	get_min_max(root->right, min, max);
}

bool		tree_get_min_max(t_node *root, int *min, int *max)
{
	if (!root)
		return (false);

	*min = root->value;
	*max = root->value;
	
	get_min_max(root, min, max);
	return (true);
}


bool	tree_is_balanced(t_node *root)
{
	int 	left, right;
	
	if (!root)
		return (true);
	
	left = tree_height(root->left);
	right = tree_height(root->right);
	
	if (abs(left, right) > 1 ||
		!tree_is_balanced(root->left) || !tree_is_balanced(root->right))
		return (false);
		
	return (true);
}

bool	tree_is_BST(t_node *root)
{	
	if (!root)
		return (true);

	if ((root->left && root->left->value >= root->value)
		|| (root->right && root->right->value <= root->value))
		return (false);
		
	return (tree_is_BST(root->left) && tree_is_BST(root->right));
}


struct s_info	getInfo(struct s_node *root)
{
	static t_info	info;

	tree_get_min_max(root, &info.min, &info.max);
	info.elements = tree_count_nodes(root);
	info.height = tree_height(root);
	info.isBalanced = tree_is_balanced(root);
	info.isBST = tree_is_BST(root);
	return info; 
}
