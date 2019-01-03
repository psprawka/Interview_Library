/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 04:29:25 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/19 04:45:54 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	printWords(struct s_node *lst)
{
	if (!lst)
		return ;

	printWords(lst->next);
	if (lst->next)
		printf("%c", ' ');
	printf("%s", lst->word);
}

void	printReverse(struct s_node *lst)
{
	printWords(lst);
	printf("\n");
}
