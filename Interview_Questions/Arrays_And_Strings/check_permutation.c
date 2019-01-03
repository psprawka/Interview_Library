/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_permutation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:09:07 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/29 09:50:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Check Permutation: Given two strings, write a function to decide if one is
**	a permutation of the other.
*/

#include <stdbool.h>

bool	check_permutation(char *s1, char *s2)
{
	int		check[127] = {0};
	int		i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		check[s1[i]]++;
		check[s2[i]]--;
	}
	
	if (s1[i] || s2[i])
		return (false);	
	for (i = 0; i < 127; i++)
		if (check[i])
			return (false);
	return (true);
}