/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_compression.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 08:10:48 by psprawka          #+#    #+#             */
/*   Updated: 2018/09/30 21:05:08 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	String Compression: Implement a function to perform basic string compression
**	using the counts of repeated characters - the string "aaabbccccdddaa" would
**	become a3b2c4d3a2. If the new string is greater than old one, return
**	an initial string. Assume there are only letters.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*string_compression(char *str)
{
	char	*new, nb[13];
	int		len, start = 0, i = 0;
	char	letter;

	if (!(new = (char *)calloc(1, sizeof(str))))
		return (NULL);
		
	for (len = 0; str[len] && str[i]; )
	{
		for (start = 0, letter = str[len]; str[len] && str[len] == letter; len++)
			start++;
		new[i] = letter;
		sprintf(nb, "%d", start);
		memcpy(&(new[++i]), nb, strlen(nb));
		i += strlen(nb);
	}
	return (i >= len ? str : new);
}
