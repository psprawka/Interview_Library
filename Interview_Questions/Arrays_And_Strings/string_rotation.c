/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:11:34 by psprawka          #+#    #+#             */
/*   Updated: 2018/10/07 21:57:48 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	String Rotation: Assume you have a method isSubstring() which checks if one
**	word is a substring of another. Given two strings, s1 and s2, write code
**	to check if s2 is a rotation of s1 using only one call to isSubstring(),
**	e.g. "water bottle" and "terbottle wa"
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool	is_substring(char *doubles1, char *s2)
{
	return (strstr(doubles1, s2) == NULL ? false : true);
}

bool	string_rotation(char *s1, char *s2)
{
	char	*doubles1;
	int		lens1 = strlen(s1);
	
	if (!(doubles1 = (char *)calloc(lens1 * 2 + 1, sizeof(char)))
		|| lens1 != strlen(s2))
		return (false);
		
	doubles1 = strcat(strcat(doubles1, s1), s1);
	return (is_substring(doubles1, s2));
}
