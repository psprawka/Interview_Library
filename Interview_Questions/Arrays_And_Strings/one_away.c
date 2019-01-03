/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_away.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:10:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/30 08:49:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	One Away: There are three types of edits that may be performed on a character:
**	insert, remove, replace. Given two strings, write a function to determine if
**	strings are one or zero edits away.
*/

#include <stdbool.h>
#include <stdio.h>
bool		one_away(char *s1, char *s2)
{
	int		i, j;
	bool	one_edit = false;
	
	for (i = 0, j = 0; s1[i] && s2[j]; i++, j++)
	{
		printf("letter i: %d [%c] | j: %d [%c]\n", i, s1[i], j, s2[j]);
		if (s1[i] != s2[j])
		{
			if (one_edit == true)
				return (false);
			if ((s1[i+1] == s2[j] && ++i) || (s1[i] == s2[j+1] && ++j) || (s1[i] != s2[j]))
				one_edit = true;
			else
				return (false);
		}
	}
	/* Checking if the length are the same or +/- 1 */
	if (one_edit == true)
		return (!s1[i] && !s2[j] ? true : false);
	if ((!s1[i] && !s2[j]) || (!s2[j] && !s1[i+1]) || (!s1[i] && !s2[j+1]))
		return (true);
		
	return (false);
}

