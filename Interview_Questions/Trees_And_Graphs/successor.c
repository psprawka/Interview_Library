/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   successor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:55:10 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/30 11:41:29 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Write an algorithm to find the "next" node (i.e. in-order successor) of
**  a given node in a BST. You may assume each node has a link to its parent.
*/

#include "libft.h"

typedef struct	s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
    struct s_tree	*parent;
	void			*data;
}				t_tree;


t_tree     *successor(t_tree *node)
{
    if (!node)
        return (NULL);

    if (!node->right)
        node = node->parent;
    else
    {
        node = node->right;
        while (node->left)
            node = node->left;
    }
    return (node);
}
