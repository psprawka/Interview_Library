/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palindrome_permutation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:09:57 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/29 10:55:03 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Palindrome Permutation: Given a string, write a function to check if it is
**	a permutation of a palindrome. A palindrome is a word or phrase that is
**	the same forwards and backwards. A permutation is a rearrangement of letters.
**	The palindrome doesn't need to be limited to dictionary words.
*/

#include <stdbool.h>

bool	palindrome_permutation(char *str)
{
	int		check[127] = {0};
	int		i;

	for (i = 0; str[i]; i++)
		check[str[i]]++;
		
	for (bool odd = 0, i = 0; i < 127; i++)
	{
		if (check[i] % 2)
		{
			if (odd == true)
				return (false);
			odd = true;
		}
	}
	return (true);
}

//bool (if/else) vs int (++) - space vs time trade off 