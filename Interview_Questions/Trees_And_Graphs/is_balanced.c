/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_balanced.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 09:20:43 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/30 09:54:32 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  This function also counts the height of a tree.
*/

#include "libft.h"
#include <limits.h>

typedef struct	s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	void			*data;
}				t_tree;

int     is_balanced(t_tree *root)
{
    int     left, right;
    
    if (!root)
        return (0);

    left = is_balanced(root->left);
    right = is_balanced(root->right);

    if (abs(left - right) > 1)
        return (-1);
    return (left > right ? left + 1 : right + 1);
}