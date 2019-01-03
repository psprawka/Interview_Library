/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_BST.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 09:53:26 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/30 10:16:02 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Validate BST: Impplement a function to check if a BT is BST.
**  Clarification: Can it have duplicates? If so in left or right subtree?
*/

#include "libft.h"
#include <stdbool.h>

typedef struct	s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	void			*data;
}				t_tree;

bool     validate_BST(t_tree *root)
{
    if (!root)
        return (true);

    if (!((!root->left || root->left <= root) && (!root->right || root->right > root)))
        return (false);

    if (validate_BST(root->left) == false || validate_BST(root->right) == false)
        return (false);

    return (true);
}